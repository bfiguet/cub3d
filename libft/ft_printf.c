/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:08:07 by bfiguet           #+#    #+#             */
/*   Updated: 2022/02/23 14:42:18 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_flags(va_list args, const char type)
{
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (type == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (type == 'p')
		len += ft_print_ptr(va_arg(args, unsigned long long));
	else if (type == 'd' || type == 'i')
		len += ft_print_nbr(va_arg(args, int));
	else if (type == 'u')
		len += ft_print_unsigned(va_arg(args, unsigned int));
	else if (type == 'x' || type == 'X')
		len += ft_print_hexa(va_arg(args, unsigned int), type);
	else if (type == '%')
		len += ft_print_percent();
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	args;
	int		len;

	i = 0;
	len = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			len += ft_flags(args, s[i + 1]);
			i++;
		}
		else
			len += ft_printchar(s[i]);
		i++;
	}
	va_end(args);
	return (len);
}
