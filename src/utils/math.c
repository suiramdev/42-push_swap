/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suiramdev <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:53:37 by suiramdev         #+#    #+#             */
/*   Updated: 2023/03/01 14:54:31 by suiramdev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	count_bits(long	num)
{
	long	count;

	count = 0;
	while (num > 0)
	{
		count++;
		num >>= 1;
	}
	return (count);
}

long	ft_pow(long num, long pow)
{
	long	result;

	result = 1;
	while (pow > 0)
	{
		result *= num;
		pow--;
	}
	return (result);
}
