/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:55:54 by bfiguet           #+#    #+#             */
/*   Updated: 2022/08/30 15:32:54 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read(int fd, char *s)
{
	char	*buff;
	int		i;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	i = 1;
	while (!gnl_chr(s, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		s = gnl_join(s, buff);
	}
	free(buff);
	return (s);
}

char	*ft_get_line(char *s)
{
	int		i;
	char	*line;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_save( char *s)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	new = malloc(sizeof(char) * (gnl_len(s) - i + 1));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		new[j++] = s[i++];
	new[j] = '\0';
	free(s);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	s = ft_read(fd, s);
	if (!s)
		return (NULL);
	line = ft_get_line(s);
	s = ft_save(s);
	return (line);
}
