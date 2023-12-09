/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:59:13 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/01 12:48:53 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_pts(t_pts *pts)
{
	t_pts	*pts_next;

	if (pts != NULL)
	{
		while (pts != NULL)
		{
			pts_next = pts->next;
			free(pts);
			pts = pts_next;
		}
	}
}

void	free_img(t_game *game, t_img *img)
{
	if (img != NULL)
	{
		if (img->name != NULL)
			mlx_destroy_image(game->mlx, img->name);
		free(img);
	}
}

static void	free_textures(t_game *game)
{
	if (game->north != NULL)
		free(game->north);
	if (game->south != NULL)
		free(game->south);
	if (game->east != NULL)
		free(game->east);
	if (game->west != NULL)
		free(game->west);
	if (game->color_f != NULL)
		free(game->color_f);
	if (game->color_c != NULL)
		free(game->color_c);
}

void	free_game(t_game *game)
{
	int	i;

	i = -1;
	if (game != NULL)
	{
		free_pts(game->pts);
		free_textures(game);
		while (NB_TEXTURE > ++i)
			if (game->textures[i] != NULL)
				free_img(game, game->textures[i]);
		free_img(game, game->img);
		if (game->mlx != NULL)
		{
			if (game->win != NULL)
				mlx_destroy_window(game->mlx, game->win);
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		free(game);
	}
}

void	free_next_line(t_game *game)
{
	char	*line;
	int		fd;
	int		status;

	status = 0;
	fd = game->fd;
	line = NULL;
	while (status == 0)
	{
		line = get_next_line(fd);
		free(line);
		if (line == NULL)
			status = 1;
	}
	close(fd);
}
