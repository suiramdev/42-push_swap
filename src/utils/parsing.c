/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 18:07:47 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/08 18:08:21 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/stack.h"
#include <libft.h>
#include <limits.h>

/// @brief Verify if the string is valid to be parsed
/// @param str The string to verify
/// @return 1 if the string is valid, 0 otherwise
static int	verify_parsing(char *str)
{
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

/// @brief Verify if the stack contains duplicates
/// @param stack The stack to verify
/// @return 1 if the stack contains no duplicates, 0 otherwise
static int	verify_duplicates(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->value == tmp->value)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

static int	parse_arg(char *arg, t_node **stack)
{
	int		i;
	char	**split;
	long	num;

	split = ft_split(arg, ' ');
	i = 0;
	while (split && split[i])
	{
		num = ft_atol(split[i]);
		if (num < INT_MIN || num > INT_MAX || !verify_parsing(split[i])
			|| !push_stack(stack, num))
		{
			i = 0;
			while (split && split[i])
				free(split[i++]);
			free(split);
			return (0);
		}
		i++;
	}
	i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);
	return (1);
}

/// @brief Parse the arguments and create a stack
/// @param args The arguments to parse
/// @return The stack created from the arguments
t_node	**parse_args(char **args)
{
	t_node	**stack;

	stack = malloc(sizeof(t_node *));
	if (!stack)
		return (NULL);
	*stack = NULL;
	while (args && *args)
	{
		if (!parse_arg(*args, stack))
		{
			free_stack(stack);
			return (NULL);
		}
		args++;
	}
	if (!verify_duplicates(*stack))
	{
		free_stack(stack);
		return (NULL);
	}
	return (stack);
}
