/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:35:54 by bfiguet           #+#    #+#             */
/*   Updated: 2022/11/28 13:15:35 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int    main()
{
    int    i;

    i = '+';
    printf("%d/ %d : %d\n", i, isascii(i), ft_isascii(i));
    i = '4';
    printf("%d/ %d : %d\n", i, isascii(i), ft_isascii(i));
    i = 'w';
    printf("%d/ %d : %d\n", i, isascii(i), ft_isascii(i));
    i = 178;
    printf("%d/ %d : %d\n", i, isascii(i), ft_isascii(i));
    return (0);
}*/
