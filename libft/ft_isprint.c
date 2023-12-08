/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:55:01 by bfiguet           #+#    #+#             */
/*   Updated: 2021/12/05 20:37:29 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int    main()
{
    int    i;

    i = '+';
    printf("%d/ %d : %d\n", i, isprint(i), ft_isprint(i));
    i = '4';
    printf("%d/ %d : %d\n", i, isprint(i), ft_isprint(i));
    i = 'w';
    printf("%d/ %d : %d\n", i, isprint(i), ft_isprint(i));
    i = 178;
    printf("%d/ %d : %d\n", i, isprint(i), ft_isprint(i));
    return (0);
}*/
