/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suiramdev <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:04:40 by suiramdev         #+#    #+#             */
/*   Updated: 2023/02/27 16:43:25 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stacks.h"
#include "utils/parsing.h"
#include <libft.h>
#include <limits.h>

static long	*fill_stack(long *stack, char **nums)
{
	size_t	i;
	long	num;

	i = 0;
	while (nums[i])
	{
		num = ft_atol(nums[i]);
		if (!verify_arg(nums[i]) || num > INT_MAX)
			return (NULL);
		stack[i] = num;
		i++;
	}
	return (stack);
}

t_stacks	*init_stacks(char **nums)
{
	t_stacks	*stacks;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->size = 0;
	while (nums[stacks->size])
		stacks->size++;
	stacks->a = malloc(stacks->size * sizeof(int));
	stacks->b = malloc(stacks->size * sizeof(int));
	if (!stacks->a || !stacks->b)
	{
		free_stacks(stacks);
		return (NULL);
	}
	stacks->a = fill_stack(stacks->a, nums);
	if (!stacks->a)
	{
		free_stacks(stacks);
		return (NULL);
	}
	return (stacks);
}

void	free_stacks(t_stacks *stacks)
{
	if (stacks->a)
		free(stacks->a);
	if (stacks->b)
		free(stacks->b);
	free(stacks);
}
