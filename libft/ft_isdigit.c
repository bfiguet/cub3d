/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:39:46 by bfiguet           #+#    #+#             */
/*   Updated: 2022/11/28 13:12:51 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int    main(void)
{
    int    i;

    i = '/';
    printf("%d/ %d : %d\n",i, isdigit(i), ft_isdigit(i));
    i = '3';
    printf("%d/ %d : %d\n",i, isdigit(i), ft_isdigit(i));
    i = 'A';
    printf("%d/ %d : %d\n",i, isdigit(i), ft_isdigit(i));
    return (0);
}*/
