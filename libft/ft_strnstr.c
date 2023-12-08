/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 20:03:35 by bfiguet           #+#    #+#             */
/*   Updated: 2022/11/28 13:17:49 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] == needle[j] && haystack[i] && i < len)
		{
			i++;
			j++;
		}
		if (!needle[j])
			return ((char *)&haystack[i - j]);
		i = (i - j) + 1;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
int    main()
{
    char    *s1;
    char    *s2;
    int n;
    
    s1 = "Hello toi";
    s2 = "Hello";
    n = 10;
    printf("str: %s\n", s1);
    printf("s2: %s/ %s : %s\n",s2,  strnstr(s1, s2, n), ft_strnstr(s1, s2, n));
    s2 = "Hello moi";
    printf("s2: %s/ %s : %s\n", s2, strnstr(s1, s2, n), ft_strnstr(s1, s2, n));
    s2 = "Hel";
    printf("s2: %s/ %s : %s\n", s2, strnstr(s1, s2, n), ft_strnstr(s1, s2, n));
    return (0);
}*/
