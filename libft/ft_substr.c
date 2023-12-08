/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:56:24 by bfiguet           #+#    #+#             */
/*   Updated: 2023/10/05 18:22:04 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*str;
	char	*src;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t)start)
		return (ft_strdup(""));
	src = (char *)s + start;
	if (ft_strlen(src) < len)
		s_len = ft_strlen(src) + 1;
	else
		s_len = len + 1;
	str = malloc(s_len * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, src, s_len);
	return (str);
}
