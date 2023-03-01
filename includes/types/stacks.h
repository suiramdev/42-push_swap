/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suiramdev <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:02:25 by suiramdev         #+#    #+#             */
/*   Updated: 2023/03/01 15:43:36 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "types/stack.h"

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

#endif
