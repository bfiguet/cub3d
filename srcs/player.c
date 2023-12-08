/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:00:21 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/08 17:42:32 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	posix_player(t_game *game, char *line, int i, int nb_l)
{
	if (game->x_pos != 0 || game->y_pos != 0)
	{
		free(line);
		print_err(game, "error parsing player\n");
	}
	game->x_pos = (double)i + 0.5;
	game->y_pos = (double)nb_l + 0.5;
	if (line[i] == 'N')
		game->angle = 0;
	else if (line[i] == 'E')
		game->angle = 0.5;
	else if (line[i] == 'S')
		game->angle = 1;
	else if (line[i] == 'W')
		game->angle = 1.5;
}

void	player_move(t_game *game)
{
	if (game->key[KEY_W] == 1)
		is_move(game, W, MOVE);
	if (game->key[KEY_A] == 1)
		is_move(game, A, MOVE);
	if (game->key[KEY_S] == 1)
		is_move(game, S, MOVE);
	if (game->key[KEY_D] == 1)
		is_move(game, D, MOVE);
	if (game->key[KEY_LEFT] == 1)
		is_rotat(&(game->angle), -ANGL);
	if (game->key[KEY_RIGHT] == 1)
		is_rotat(&(game->angle), ANGL);
	if (game->key[KEY_UP] == 1)
		change_view(&(game->view), -VIEW);
	if (game->key[KEY_DOWN] == 1)
		change_view(&(game->view), VIEW);
}
