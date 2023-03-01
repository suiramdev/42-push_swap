/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:24:23 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/01 16:36:03 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stacks.h"
#include "types/node.h"
#include "utils/math.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static int	error()
{
	write(STDOUT_FILENO, "Error\n", 6);
	return (EXIT_FAILURE);
}

static void	free_stacks(t_stacks *stacks)
{
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
}

static t_stacks	*init_stacks(char **nums)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->a = init_stack('a', nums);
	stacks->b = init_stack('b', NULL);
	if (!stacks->a)
	{
		free_stacks(stacks);
		return (NULL);
	}
	return (stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	long		bit;
	long		bits_max;
	size_t		i;

	if (argc < 2)
		return (error());
	stacks = init_stacks(argv + 1);
	if (!stacks)
		return (error());
	bits_max = count_bits(highest_node(stacks->a->head)->num);
	bit = 0;
	while (bit < bits_max)
	{
		i = 0;
		while (i < stacks->a->size)
		{
			if (stacks->a->head->num & ft_pow(2, bit))
				push_stack(stacks->a, stacks->b);
			else
				rotate_stack(stacks->a);
			i++;
		}
		bit++;
	}
	free_stacks(stacks);
	return (EXIT_SUCCESS);
}

