/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:06:36 by bfiguet           #+#    #+#             */
/*   Updated: 2022/11/28 13:15:31 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int    main(void)
{
    int    i;

    i = '/';
    printf("%d/ %d : %d\n", i,  isalpha(i), ft_isalpha(i));
    i = '3';
    printf("%d/ %d : %d\n", i,  isalpha(i), ft_isalpha(i));
    i = 'A';
    printf("%d/ %d : %d\n", i,  isalpha(i), ft_isalpha(i));
    return (0);
}*/
