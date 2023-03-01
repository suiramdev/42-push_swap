/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suiramdev <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:31:20 by suiramdev         #+#    #+#             */
/*   Updated: 2023/03/01 16:35:23 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include "types/node.h"
# include <stddef.h>

typedef struct s_stack
{
	char	name;
	t_node	*head;
	size_t	size;
}	t_stack;

void	free_stack(t_stack *stack);
t_stack	*init_stack(char name, char **nums);
void	swap_stack(t_stack *stack);
void	rotate_stack(t_stack *stack);
void	push_stack(t_stack *from, t_stack *to);

#endif
