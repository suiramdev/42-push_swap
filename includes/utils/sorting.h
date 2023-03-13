/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:06:37 by mnouchet          #+#    #+#             */
/*   Updated: 2023/03/09 18:11:27 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTING_H
# define SORTING_H

# include "types/stack.h"

void	sort_any(t_node	**a, t_node **b);
void	sort_2_3(t_node **a);
void	sort_4_5(t_node **a, t_node **b);

#endif
