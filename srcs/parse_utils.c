/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imarushe <imarushe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:04:17 by imarushe          #+#    #+#             */
/*   Updated: 2023/12/08 15:04:17 by imarushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map(t_game *game, char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\n')
	{
		if (game->pts != NULL)
			return (0);
		else
			return (1);
	}
	if (line[i] == '1')
	{
		if (game->north == NULL || game->south == NULL
			|| game->east == NULL || game->west == NULL
			|| game->color_c == NULL || game->color_f == NULL)
			print_err (game, "Texture or color isn't defined\n");
		return (1);
	}
	return (0);
}

int	is_empty(const char *s)
{
	while (*s != '\0')
	{
		if (!ft_isspace((unsigned char)*s))
			return (0);
		s++;
	}
	return (1);
}

char	*dup_val(t_game *game, char *line, int i)
{
	char	*s;
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (line[i + j] && line[i + j] != ' ' && line[i + j] != '\t'
		&& line[i + j] != '\n')
		j++;
	if (line[i + j] != ' ')
	{
		while (line[i + j + k] == ' ')
			k++;
		if (line[i + j + k] != '\0' && line[i + j + k] != '\n'
			&& line[i + j + k] != '\t')
		{
			free(line);
			print_err(game, "error path\n");
		}
	}
	s = ft_strndup(&line[i], j);
	free(line);
	return (s);
}

char	remove_spaces_from_str(char *string, int j)
{
	int	i;

	i = j;
	while (string[i] != '\0')
	{
		if (string[i] != ' ')
		{
			string[j] = string[i];
			j++;
		}
		i++;
	}
	string[j] = '\0';
	return (*string);
}

int	is_xpm_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	len -= 2;
	while (ft_isspace(arg[len]))
		len--;
	if ((arg[len - 2] != 'x' || arg[len - 1] != 'p'
			|| arg[len] != 'm' || arg[len - 3] != '.'))
		return (0);
	return (1);
}
