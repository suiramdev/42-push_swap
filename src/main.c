/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 22:24:23 by mnouchet          #+#    #+#             */
/*   Updated: 2023/02/27 16:45:24 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stacks.h"
#include <unistd.h>
#include <stdlib.h>

static int	error()
{
	write(STDOUT_FILENO, "Error\n", 6);
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc < 2)
		return (error());
	stacks = init_stacks(argv + 1);
	if (!stacks)
		return (error());
	free_stacks(stacks);
	return (EXIT_SUCCESS);
}
