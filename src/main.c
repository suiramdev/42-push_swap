/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:33:00 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/09 18:10:00 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stack.h"
#include "utils/parsing.h"
#include "utils/scaling.h"
#include "utils/sorting.h"
#include <unistd.h>
#include <stdlib.h>

static int	error(void)
{
	write(STDERR_FILENO, "Error", 5);
	return (EXIT_FAILURE);
}

static void	sorting(int argc, t_node **a, t_node **b)
{
	if (argc < 5)
		sort_2_3(a);
	else if (argc < 7)
		sort_4_5(a, b);
	else
		sort_any(a, b);
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_node	**parsed;
	t_node	**a;
	t_node	**b;

	if (argc <= 2)
		return (EXIT_SUCCESS);
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
	sorting(argc, a, b);
	return (EXIT_SUCCESS);
}
