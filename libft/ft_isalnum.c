/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:32:19 by bfiguet           #+#    #+#             */
/*   Updated: 2022/11/28 13:15:28 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*#include <stdio.h>
#include <ctype.h>
int    main()
{
    int    i;
    
    i = '+';
    printf("%d/ %d : %d\n", i, isalnum(i), ft_isalnum(i));
    i = '4';
    printf("%d/ %d : %d\n", i, isalnum(i), ft_isalnum(i));
    i = 'w';
    printf("%d/ %d : %d\n", i, isalnum(i), ft_isalnum(i));
    return (0);
}*/
