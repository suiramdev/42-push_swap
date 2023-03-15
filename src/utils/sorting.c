/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:04:53 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/09 18:11:09 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stack.h"
#include "utils/moves.h"
#include "utils/maths.h"
#include <stdlib.h>

/// @brief Check if the stack is is_sorted
/// @param stack The stack to check
/// @return 1 if the stack is is_sorted, 0 otherwise
static int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_2_3(t_node **a)
{
	if ((*a)->value > (*a)->next->value)
		move_swap('a', a);
	if ((*a)->next->next)
	{
		if ((*a)->next->value > (*a)->next->next->value)
		{
			move_reverse_rotate('a', a);
			if ((*a)->value > (*a)->next->value)
				move_swap('a', a);
		}
	}
}

void	sort_4_5(t_node **a, t_node **b)
{
	if (is_sorted(*a))
		return ;
	while ((*a)->value != 0)
		move_rotate('a', a);
	move_push('b', a, b);
	while ((*a)->value != 1)
		move_rotate('a', a);
	move_push('b', a, b);
	sort_2_3(a);
	move_push('a', b, a);
	move_push('a', b, a);
}

void	sort_any(t_node	**a, t_node **b)
{
	size_t	size;
	size_t	bits;
	size_t	bit;
	size_t	i;

	size = stack_size(*a);
	bits = count_bits(size - 1);
	bit = 0;
	while (bit < bits)
	{
		i = 0;
		while (i < size && !is_sorted(*a))
		{
			if ((((*a)->value >> bit) & 1) == 1)
				move_rotate('a', a);
			else
				move_push('b', a, b);
			i++;
		}
		while (*b)
			move_push('a', b, a);
		bit++;
	}
}
