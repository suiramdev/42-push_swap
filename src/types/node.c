/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suiramdev <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:46:03 by suiramdev         #+#    #+#             */
/*   Updated: 2023/03/01 16:06:55 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/node.h"
#include <stdlib.h>

t_node	*new_node(t_node **head, long num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->num = num;
	node->next = *head;
	*head = node;
	return (node);
}

t_node	*highest_node(t_node *head)
{
	t_node	*cursor;
	t_node	*highest;

	cursor = head;
	highest = cursor;
	while (cursor->next)
	{
		if (cursor->num > highest->num)
			highest = cursor;
		cursor = cursor->next;
	}
	return (cursor);
}

