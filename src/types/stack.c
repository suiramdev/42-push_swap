/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:38:24 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/08 18:51:52 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stack.h"
#include <stdlib.h>
#include <unistd.h>

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	tmp = *stack;
	while (tmp)
	{
		*stack = tmp->next;
		free(tmp);
		tmp = *stack;
	}
	free(stack);
}

t_node	*push_stack(t_node **stack, int value)
{
	t_node	*new;
	t_node	*last;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	if (*stack)
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*stack = new;
	return (new);
}

size_t	stack_size(t_node *stack)
{
	size_t	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

/// @brief Shift up all elements of stack by 1.
/// The first element becomes the last one.
/// @param stack The stack to rotate
void	move_rotate(char c, t_node **stack)
{
	t_node	*last;
	t_node	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
		last = last->next;
	tmp = *stack;
	last->next = tmp;
	*stack = tmp->next;
	tmp->next = NULL;
	write(STDOUT_FILENO, "r", 1);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, "\n", 1);
}

/// @brief Take the first element of the stack and put
/// it first in the other stack
/// @param from The stack to take the element from
/// @param to The stack to put the element in
void	move_push(char c, t_node **from, t_node **to)
{
	t_node	*tmp;

	if (!*from)
		return ;
	tmp = *from;
	*from = tmp->next;
	tmp->next = *to;
	*to = tmp;
	write(STDOUT_FILENO, "p", 1);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, "\n", 1);
}
