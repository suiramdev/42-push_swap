/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:05:54 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/09 18:06:29 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVES_H
# define MOVES_H

# include "types/stack.h"

void	move_rotate(char c, t_node **stack);
void	move_reverse_rotate(char c, t_node **stack);
void	move_push(char c, t_node **from, t_node **to);
void	move_swap(char c, t_node **stack);

#endif
