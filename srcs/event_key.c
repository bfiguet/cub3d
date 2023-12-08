/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:58:53 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/08 17:37:37 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	good_end(t_game *game)
{
	ft_printf("Thank your for your participation!\n");
	free_game(game);
	exit(EXIT_SUCCESS);
}

static int	key_press(int key, t_game *game)
{
	if (key == ESC)
		good_end(game);
	if (key == LEFT)
		game->key[KEY_LEFT] = 1;
	if (key == RIGHT)
		game->key[KEY_RIGHT] = 1;
	if (key == UP)
		game->key[KEY_UP] = 1;
	if (key == DOWN)
		game->key[KEY_DOWN] = 1;
	if (key == W)
		game->key[KEY_W] = 1;
	if (key == A)
		game->key[KEY_A] = 1;
	if (key == S)
		game->key[KEY_S] = 1;
	if (key == D)
		game->key[KEY_D] = 1;
	return (0);
}

static int	key_release(int key, t_game *game)
{
	if (key == LEFT)
		game->key[KEY_LEFT] = 0;
	if (key == RIGHT)
		game->key[KEY_RIGHT] = 0;
	if (key == UP)
		game->key[KEY_UP] = 0;
	if (key == DOWN)
		game->key[KEY_DOWN] = 0;
	if (key == W)
		game->key[KEY_W] = 0;
	if (key == A)
		game->key[KEY_A] = 0;
	if (key == S)
		game->key[KEY_S] = 0;
	if (key == D)
		game->key[KEY_D] = 0;
	return (0);
}

static int	close_hook(t_game *game)
{
	good_end(game);
	return (0);
}

//Ancien : mlx_hook(img.win, 17, 1L<<17, [close_func], &img);
//Nouveau : mlx_hook(img.win, 33, 1L<<17, [close_func], &img);??

void	event_hook(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 3, 1L << 1, key_release, game);
	mlx_hook(game->win, 17, 1l << 17, close_hook, game);
}
