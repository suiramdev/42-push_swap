/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:33:00 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/08 18:53:48 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stack.h"
#include "utils/parsing.h"
#include "utils/scaling.h"
#include "utils/maths.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static int	error(void)
{
	write(STDERR_FILENO, "Error", 5);
	return (EXIT_FAILURE);
}

/// @brief Check if the stack is is_sorted
/// @param stack The stack to check
/// @return 1 if the stack is is_sorted, 0 otherwise
static int	is_sorted(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void	default_sort(t_node	**a, t_node **b)
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

int	main(int argc, char **argv)
{
	t_node	**parsed;
	t_node	**a;
	t_node	**b;

	if (argc < 3)
		return (error());
	parsed = parse_args(argv + 1);
	if (!parsed)
		return (error());
	a = weight_stack(parsed);
	free_stack(parsed);
	if (!a)
		return (error());
	b = malloc(sizeof(t_node *));
	if (!b)
	{
		free_stack(a);
		return (error());
	}
	*b = NULL;
	default_sort(a, b);
	free_stack(a);
	free_stack(b);
	return (EXIT_SUCCESS);
}
