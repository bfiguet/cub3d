/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 13:18:08 by bfiguet           #+#    #+#             */
/*   Updated: 2022/11/28 13:17:46 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] != (unsigned char)c)
			i--;
		else
			return ((char *)s + i);
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int    main()
{
    char    *str;
    int c;
    
    str = "Hello toi";
    c = 'l';
    printf("str: %s\n", str);
    printf("%d %s : %s\n", c, strrchr(str, c), ft_strrchr(str, c));
    c = 'o';
    printf("%d %s : %s\n", c, strrchr(str, c), ft_strrchr(str, c));
    c = '4';
    printf("%d %s : %s\n", c, strrchr(str, c), ft_strrchr(str, c));
    c = 'E';
    printf("%d %s : %s\n", c, strrchr(str, c), ft_strrchr(str, c));
    return (0);
}*/
