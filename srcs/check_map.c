/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:48:14 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/05 21:40:31 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	push_pts(t_game *game, t_pts *tmp)
{
	t_pts	*ptr;

	ptr = game->pts;
	if (game->pts == NULL)
		game->pts = tmp;
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = tmp;
	}
}

static void	parse_text(t_game *game, char *path)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		print_err(game, "Texture doesn't exist\n");
	}
	else if (read(fd, line, 0) == -1)
	{
		close(fd);
		print_err(game, "Texture is a directory\n");
	}
	else if (ft_strlen(path) <= 4 || !*(path + 4) || *(path + 4) == '/'
		|| ft_strcmp(&path[(int)ft_strlen(path) - 4], ".mpx") == 0)
	{
		close(fd);
		print_err(game, "Texture has the wrong extension\n");
	}
}

static void	check(t_pts *pts, int *flag, int x, int y)
{
	if (pts->x == x - 1 && pts->y == y - 1)
		(*flag)++;
	else if (pts->x == x && pts->y == y - 1)
		(*flag)++;
	else if (pts->x == x + 1 && pts->y == y - 1)
		(*flag)++;
	else if (pts->x == x - 1 && pts->y == y)
		(*flag)++;
	else if (pts->x == x + 1 && pts->y == y)
		(*flag)++;
	else if (pts->x == x - 1 && pts->y == y + 1)
		(*flag)++;
	else if (pts->x == x && pts->y == y + 1)
		(*flag)++;
	else if (pts->x == x + 1 && pts->y == y + 1)
		(*flag)++;
}

static void	check_wall_map(t_game *game, int x, int y)
{
	t_pts	*pts;
	int		flag;

	pts = game->pts;
	flag = 0;
	while (pts != NULL)
	{
		check(pts, &flag, x, y);
		pts = pts->next;
	}
	if (flag != 8)
		print_err(game, "Invalid map, it's not surrounded by '1'\n");
}

void	check_map(t_game *game)
{
	t_pts	*pts;
	int		player;

	pts = game->pts;
	player = 0;
	while (pts != NULL)
	{
		if (pts->name != '1')
		{
			check_wall_map(game, pts->x, pts->y);
			if (pts->name != '0')
				player = 1;
		}
		pts = pts->next;
	}
	if (player == 0)
		print_err(game, "No player\n");
	parse_text(game, game->north);
	parse_text(game, game->south);
	parse_text(game, game->east);
	parse_text(game, game->west);
	check_colors(game, game->color_c);
	check_colors(game, game->color_f);
	game->ref_color_c = get_code(game, game->color_c);
	game->ref_color_f = get_code(game, game->color_f);
}
