/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:34:11 by bfiguet           #+#    #+#             */
/*   Updated: 2022/11/28 13:12:57 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_array(char *str, unsigned int n, long int len)
{
	while (n > 0)
	{
		str[len--] = 48 + (n % 10);
		n /= 10;
	}
	return (str);
}

static long int	ft_lenint(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len = 1;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	nbr;
	long int		len;
	int				sign;

	sign = 1;
	len = ft_lenint(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		sign *= -1;
		nbr = n * -1;
		str[0] = '-';
	}
	else
		nbr = n;
	str = ft_array(str, nbr, len);
	return (str);
}
/*
#include<stdio.h>
int main() {
  int n;
  
  n = 2;
  printf("%d/ %s\n", n, ft_itoa(n));
  n = 2000;
  printf("%d/ %s\n", n, ft_itoa(n));
  n = -22;
  printf("%d/ %s\n", n, ft_itoa(n));
  return 0;
}*/
