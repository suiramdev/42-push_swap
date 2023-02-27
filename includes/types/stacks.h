/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suiramdev <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:02:25 by suiramdev         #+#    #+#             */
/*   Updated: 2023/02/27 16:38:35 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include <stdlib.h>

typedef struct s_stacks
{
	long	*a;
	long	*b;
	size_t	size;
}	t_stacks;

t_stacks	*init_stacks(char **nums);
void		free_stacks(t_stacks *stacks);

#endif
