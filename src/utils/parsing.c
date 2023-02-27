/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suiramdev <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 03:06:23 by suiramdev         #+#    #+#             */
/*   Updated: 2023/02/23 03:12:49 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/// @brief Checks if the given string is a correct number to be used in a stack.
/// @param arg The argument to be checked.
/// @return 1 if the argument is a correct number, 0 otherwise.
int	verify_arg(char *arg)
{
	while (ft_isspace(*arg))
		arg++;
	if (*arg == '\0')
		return (0);
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	return (1);
}
