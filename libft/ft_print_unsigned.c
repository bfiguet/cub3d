/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:56:35 by bfiguet           #+#    #+#             */
/*   Updated: 2022/02/23 15:41:32 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	char	*nbr;
	int		len;

	len = ft_len(n);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len] = '\0';
	while (n != 0)
	{
		nbr[len - 1] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (nbr);
}

int	ft_print_unsigned(unsigned int n)
{
	int		len;
	char	*nbr;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		nbr = ft_uitoa(n);
		len += ft_print_str(nbr);
		free(nbr);
	}
	return (len);
}
