/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:50:35 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/05 21:16:51 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_struct(t_game *game)
{
	game->east = NULL;
	game->north = NULL;
	game->south = NULL;
	game->west = NULL;
	game->color_f = NULL;
	game->color_c = NULL;
	game->ref_color_f = 0;
	game->ref_color_c = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->pts = NULL;
	game->x_pos = 0;
	game->y_pos = 0;
	game->status = 0;
	game->x_len = 0;
	game->y_len = 0;
	game->view = 0;
	game->map = 0;
}

t_pts	*init_pts(t_game *game, char *s)
{
	t_pts	*pts;

	pts = malloc(sizeof(t_pts));
	if (!pts)
	{
		free(s);
		print_err(game, "error malloc\n");
	}
	pts->name = '\0';
	pts->next = NULL;
	pts->x = 0;
	pts->y = 0;
	return (pts);
}

t_img	*init_img(void)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (!img)
		return (NULL);
	img->name = NULL;
	img->add = NULL;
	img->size = 0;
	img->bpp = 0;
	img->endian = 0;
	return (img);
}

void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		print_err(game, "init mlx failed\n");
	game->win = mlx_new_window(game->mlx, WIN_SIZE_X, WIN_SIZE_Y, "Cub3D");
	if (!game->win)
		print_err(game, "mlx_new_window failed\n");
}

t_game	*init_game(void)
{
	int		i;
	t_game	*game;

	i = -1;
	game = malloc(sizeof(t_game));
	if (!game)
		print_err(game, "error malloc game\n");
	game->img = init_img();
	if (!game->img)
		print_err(game, "error malloc img\n");
	while (++i < NB_TEXTURE)
	{
		(game->textures)[i] = init_img();
		if (!(game->textures)[i])
			print_err(game, "error malloc texture\n");
	}
	i = -1;
	while (++i < NB_KEY)
		game->key[i] = 0;
	init_struct(game);
	return (game);
}
