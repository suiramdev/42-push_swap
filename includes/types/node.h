/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suiramdev <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:45:41 by suiramdev         #+#    #+#             */
/*   Updated: 2023/03/01 14:52:54 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

typedef struct s_node
{
	long			num;
	struct s_node	*next;
}	t_node;

t_node	*new_node(t_node **head, long num);
t_node	*last_node(t_node *head);
t_node	*highest_node(t_node *head);

#endif
