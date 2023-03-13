/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:04:21 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/09 18:04:51 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stack.h"
#include <unistd.h>

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

/// @brief Shift down all elements of stack by 1.
/// The last element becomes the first one.
/// @param stack The stack to rotate
void	move_reverse_rotate(char c, t_node **stack)
{
	t_node	*last;
	t_node	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	write(STDOUT_FILENO, "rr", 2);
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

/// @brief Swap the two first elements of the stack
/// @param stack The stack to swap
void	move_swap(char c, t_node **stack)
{
	t_node	*tmp;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	write(STDOUT_FILENO, "s", 1);
	write(STDOUT_FILENO, &c, 1);
	write(STDOUT_FILENO, "\n", 1);
}
