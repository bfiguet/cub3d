/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:06:26 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/05 17:40:41 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*define_text(t_game *game, char *line, char *text, int i)
{
	if (!is_xpm_file(line))
	{
		free(line);
		print_err(game, "error texture file\n");
	}
	if (text != NULL)
	{
		free(line);
		print_err(game, "texture is not define\n");
	}
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '\0')
	{
		free(line);
		print_err(game, "no path's texture\n");
	}
	text = dup_val(game, line, i);
	if (text == NULL)
		print_err(game, "error malloc texture\n");
	return (text);
}

static void	color_floor(t_game *game, char *line, int i)
{
	if (game->color_f != NULL)
	{
		free(line);
		print_err(game, "floor's color, it's not define\n");
	}
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
	{
		free(line);
		print_err(game, "no floor's color\n");
	}
	*line = remove_spaces_from_str(line, i);
	game->color_f = dup_val(game, line, i);
	if (game->color_f == NULL)
		print_err(game, "error malloc color floor\n");
}

static void	color_ceiling(t_game *game, char *line, int i)
{
	if (game->color_c != NULL)
	{
		free(line);
		print_err(game, "ceiling's color, it'snt define\n");
	}
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '\0')
	{
		free(line);
		print_err(game, "no ceiling's color\n");
	}
	*line = remove_spaces_from_str(line, i);
	game->color_c = dup_val(game, line, i);
	if (game->color_c == NULL)
		print_err(game, "error malloc color ceiling\n");
}

static int	check_direction(t_game *game, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		game->north = define_text(game, line, game->north, i + 3);
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		game->south = define_text(game, line, game->south, i + 3);
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		game->east = define_text(game, line, game->east, i + 3);
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		game->west = define_text(game, line, game->west, i + 3);
	else if (line[i] == 'F' && line[i + 1] == ' ')
		color_floor(game, line, i + 2);
	else if (line[i] == 'C' && line[i + 1] == ' ')
		color_ceiling(game, line, i + 2);
	else
		return (0);
	return (1);
}

void	ref_text(t_game *game, char *line)
{
	int	i;

	i = 0;
	if (game->pts != NULL)
		print_err(game, "the map should be the last in the file\n");
	else
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0' || line[i] == '\n')
			free(line);
		else if (!check_direction(game, line, i))
		{
			free(line);
			print_err(game, "error parsing texture\n");
		}
	}
}
