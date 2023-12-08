/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 07:20:46 by bfiguet           #+#    #+#             */
/*   Updated: 2023/10/30 07:21:25 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat_malloc(char *str1, const char *str2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = ft_strlen(str1);
	j = ft_strlen(str2);
	str = malloc(sizeof(char) * (i + j + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str1[i])
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		str[i] = str2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
