/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:38:35 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/08 18:52:37 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

void	free_stack(t_node **head);
t_node	*push_stack(t_node **stack, int value);
size_t	stack_size(t_node *head);
void	move_rotate(char c, t_node **head);
void	move_push(char c, t_node **from, t_node **to);

#endif
