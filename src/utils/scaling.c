/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:06:44 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/08 18:31:09 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stack.h"
#include <stdlib.h>
#include <stdio.h>

// Split the function weight_stack in two parts
static int	weight(t_node *stack, int value)
{
	int	weight;

	weight = 0;
	while (stack)
	{
		if (value > stack->value)
			weight++;
		stack = stack->next;
	}
	return (weight);
}

/// @brief Simplify a stack by replacing each value by its weight.
/// The weight of a value is the number of values smaller than it.
/// @param stack The stack to simplify
/// @return The simplified stack
t_node	**weight_stack(t_node **stack)
{
	t_node	**simplified;
	t_node	*current;

	simplified = malloc(sizeof(t_node *));
	if (!simplified)
		return (NULL);
	*simplified = NULL;
	current = *stack;
	while (current)
	{
		if (!push_stack(simplified, weight(*stack, current->value)))
		{
			free_stack(simplified);
			return (NULL);
		}
		current = current->next;
	}
	return (simplified);
}
