/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:41:49 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/08 17:46:33 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_out(t_game *game, double x, double y, int sign)
{
	t_pts	*pts;
	int		floor_x;
	int		floor_y;

	floor_x = floor(x + (double)(sign * MOVE));
	floor_y = floor(y + (double)(sign * MOVE));
	pts = game->pts;
	while (pts != NULL)
	{
		if (floor_x == pts->x && floor_y == pts->y && pts->name == '1')
		{
			if (floor_x != pts->x && floor_x != x)
				game->x_pos = x;
			if (floor_y != pts->y && floor_y != y)
				game->y_pos = y;
			return (1);
		}
		pts = pts->next;
	}
	return (0);
}

void	change_view(int *view, int val)
{
	*view += val;
	if (*view > WIN_SIZE_Y / 2)
		*view = WIN_SIZE_Y / 2;
	if (*view < -WIN_SIZE_Y / 2)
		*view = -WIN_SIZE_Y / 2;
}

void	is_rotat(double *angl, double rot)
{
	*angl += (rot);
	if (*angl > 2)
		*angl = *angl - 2;
	else if (*angl < 0)
		*angl = 2 + *angl;
}

void	is_move(t_game *game, int key, double move)
{
	double	x;
	double	y;
	double	angl;

	angl = 0;
	if (key == W)
		angl = game->angle;
	if (key == A)
		angl = game->angle + 1.5;
	if (key == S)
		angl = game->angle + 1;
	if (key == D)
		angl = game->angle + 0.5;
	if (angl > 2)
		angl = angl - 2;
	x = game->x_pos + move * sin(angl * M_PI);
	y = game->y_pos + move * -cos(angl * M_PI);
	if (is_out(game, x, y, 1) == 1 || is_out(game, x, y, -1) == 1)
		return ;
	game->x_pos = x;
	game->y_pos = y;
}
