/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suiramdev <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:29:40 by suiramdev         #+#    #+#             */
/*   Updated: 2023/03/01 16:35:03 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stacks.h"
#include "utils/parsing.h"
#include <libft.h>

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->head)
	{
		tmp = stack->head;
		stack->head = stack->head->next;
		free(tmp);
	}
	free(stack);
}

t_stack	*init_stack(char name, char **nums)
{
	t_stack	*stack;
	t_node	*node;
	size_t	i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->name = name;
	stack->head = NULL;
	i = 0;
	while (nums && nums[i])
	{
		node = new_node(&stack->head, ft_atol(nums[i]));
		if (!node || !verify_arg(nums[i]) || node->num > INT_MAX)
		{
			free_stack(stack);
			return (NULL);
		}
		i++;
	}
	stack->size = i;
	return (stack);
}

void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*third;

	if (!stack->head)
		return ;
	first = stack->head;
	third = stack->head->next->next;
	stack->head = stack->head->next;
	stack->head->next = first;
	first->next = third;
	write(1, "s", 1);
	write(1, &stack->name, 1);
	write(1, "\n", 1);
}

void	rotate_stack(t_stack *stack)
{
	t_node	*last;
	t_node	*before_last;

	if (!stack->head || !stack->head->next)
		return ;
	last = stack->head;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = stack->head;
	stack->head = last;
	write(1, "r", 1);
	write(1, &stack->name, 1);
	write(1, "\n", 1);
}

void	push_stack(t_stack *from, t_stack *to)
{
	t_node	*node;

	if (!from->head)
		return ;
	node = from->head;
	from->head = from->head->next;
	node->next = to->head;
	to->head = node;
	to->size++;
	from->size--;
	write(1, "p", 1);
	write(1, &to->name, 1);
	write(1, "\n", 1);
}

