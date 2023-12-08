/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_no_malloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 07:01:03 by bfiguet           #+#    #+#             */
/*   Updated: 2023/10/30 07:06:40 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	recursive(unsigned int nbr, char *buff)
{
	int				size;
	int				i;
	unsigned int	nbr2;

	size = 1;
	i = 0;
	nbr2 = nbr;
	nbr = nbr / 10;
	if (nbr > 0)
		size += recursive(nbr, buff);
	while (buff[i])
		i++;
	buff[i] = (nbr2 % 10) + '0';
	return (size);
}

int	ft_itoa_no_malloc(int nbr, char *buff)
{
	int				size;
	unsigned int	nbr2;

	ft_bzero(buff, 12);
	size = 0;
	nbr2 = nbr;
	if (nbr < 0)
	{
		buff[0] = '-';
		nbr2 = -nbr;
		size++;
	}
	size += recursive(nbr2, buff);
	return (size);
}
