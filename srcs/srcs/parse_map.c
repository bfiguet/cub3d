/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 18:05:03 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/05 17:37:57 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_pts(t_game *game, char *l, int i, int nb_l)
{
	t_pts	*tmp;

	if (l[i] != ' ')
	{
		tmp = init_pts(game, l);
		tmp->x = i;
		tmp->y = nb_l;
		tmp->name = l[i];
		if (tmp->x > game->x_len)
			game->x_len = tmp->x;
		if (tmp->y > game->y_len)
			game->y_len = tmp->y;
		push_pts(game, tmp);
		if (l[i] == 'N' || l[i] == 'S' || l[i] == 'E' || l[i] == 'W')
			posix_player(game, l, i, nb_l);
	}
}

static int	add_line(t_game *game, char *line, int nb_l)
{
	int	i;
	int	between_wall;

	i = 0;
	between_wall = -1;
	while (line[i] && line[i] != '\n')
	{
		if (ft_strchr("012NSWE ", line[i]))
		{
			if (line[i] == '1' && line[i + 1] && line[i + 1] != '\n'
				&& ft_strchr("012NSWE ", line[i + 1]))
				between_wall *= -1;
			if (line[i] == ' ' && between_wall > 0)
				line[i] = '1';
			add_pts(game, line, i, nb_l);
		}
		else
		{
			free(line);
			print_err(game, "invalid character on map\n");
		}
		i++;
	}
	free(line);
	return (nb_l);
}

// Unreachable code:
//	if (game->pts != NULL && status == 0)
//		print_err(game, "empty line\n");
static int	parse_line(t_game *game, char *line, int nb_l)
{
	if (line == NULL || ft_strcmp(line, "\n") == 0 || is_empty(line))
	{
		free(line);
		if (game->pts != NULL)
		{
			game->map = 1;
		}
	}
	else if (ft_strcmp(line, "") == 0)
		free(line);
	else if (is_map(game, line) == 1)
	{
		if (game->map == 1)
		{
			free(line);
			print_err(game, "The map should be the last in the file\n");
		}
		nb_l = add_line(game, line, nb_l);
		nb_l++;
	}
	else
		ref_text(game, line);
	return (nb_l);
}

void	parse_map(t_game *game, char *av)
{
	char	*line;
	int		fd;
	int		status;
	int		nb_l;

	nb_l = 0;
	status = 0;
	fd = open(av, O_RDONLY);
	game->fd = fd;
	line = NULL;
	if (fd < 0)
		print_err(game, "failed to load map\n");
	while (status == 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			status = 1;
		nb_l = parse_line(game, line, nb_l);
	}
	close(fd);
}
