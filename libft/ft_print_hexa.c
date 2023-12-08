/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:29:49 by bfiguet           #+#    #+#             */
/*   Updated: 2022/02/23 14:59:17 by bfiguet          ###   ########.fr       */
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
		n = n / 16;
	}
	return (len);
}

void	ft_hexa(unsigned int n, const char type)
{
	if (n >= 16)
	{
		ft_hexa(n / 16, type);
		ft_hexa(n % 16, type);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd ((n + '0'), 1);
		else
		{
			if (type == 'x')
				ft_putchar_fd ((n - 10 + 'a'), 1);
			if (type == 'X')
				ft_putchar_fd ((n - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hexa(unsigned int n, const char type)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_hexa(n, type);
	return (ft_len(n));
}
