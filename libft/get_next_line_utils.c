/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:56:31 by bfiguet           #+#    #+#             */
/*   Updated: 2022/03/28 20:55:17 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ssize_t read(int fd, void *buf, size_t count);

char	*gnl_chr(char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (c == '\0')
		return ((char *)&s[gnl_len(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

size_t	gnl_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_join(char *s1, char *s2)
{
	int		i;
	int		c;
	char	*str;

	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (gnl_len(s1) + gnl_len(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	c = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[c] != '\0')
		str[i++] = s2[c++];
	str[gnl_len(s1) + gnl_len(s2)] = '\0';
	free(s1);
	return (str);
}
