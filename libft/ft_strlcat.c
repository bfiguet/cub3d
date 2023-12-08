/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:00:25 by bfiguet           #+#    #+#             */
/*   Updated: 2022/11/28 13:18:01 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_src;
	size_t	s_dst;

	if (!dst || !src)
		return (0);
	s_src = ft_strlen(src);
	s_dst = ft_strlen(dst);
	if (size < s_dst)
		return (s_src + size);
	else
	{
		dst += s_dst;
		ft_strlcpy(dst, src, size - s_dst);
		return (s_src + s_dst);
	}
}
