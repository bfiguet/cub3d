/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:42:39 by bfiguet           #+#    #+#             */
/*   Updated: 2022/11/28 13:17:33 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
#include <stdio.h>
#include <ctype.h>
int    main()
{
    int c;
    
    c = 'H';
    printf("%d/ %d : %d\n", c, tolower(c), ft_tolower(c));
    c = 'e';
    printf("%d/ %d : %d\n", c, tolower(c), ft_tolower(c));
    c = '4';
    printf("%d/ %d : %d\n", c, tolower(c), ft_tolower(c));
    return (0);
}*/
