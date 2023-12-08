/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 16:35:59 by bfiguet           #+#    #+#             */
/*   Updated: 2023/09/22 14:06:42 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s1, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s;

	if (!s1 || !f)
		return (NULL);
	i = 0;
	s = malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!(s))
		return (NULL);
	while (i != ft_strlen(s1))
	{
		s[i] = (*f)(i, s1[i]);
		i++;
	}
	s[i] = '\0';
	return (s);
}
/*
 char my_func(unsigned int i, char str)
 {
     printf("My inner function: index = %d and %c\n", i, str);
     return str - 32;
 }

#include<stdio.h>
 int main()
 {
     char str[10] = "hello.";
     printf("The result is %s\n", str);
     char *result = ft_strmapi(str, my_func);
     printf("The result is %s\n", result);
     return 0;
 }*/
