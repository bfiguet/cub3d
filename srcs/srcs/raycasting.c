/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 20:02:41 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/05 21:42:21 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// dir[x] or [y] = direction of player
// map[x] or [y] = angl payer on map
// r->ray[x] or [y] = direction of the ray
// r->pts [x] or [y] = current square of the ray
// delta_dist [x] or [y] = distance to go to the next x or y.
//fabs() --> to get the absolute value
static void	start_ray(t_game *game, t_ray *r, int x)
{
	double	dir[2];
	double	map[2];

	dir[0] = sin(game->angle * M_PI);
	dir[1] = -cos(game->angle * M_PI);
	map[0] = sin((game->angle + 0.5) * M_PI);
	map[1] = -cos((game->angle + 0.5) * M_PI);
	r->ray[0] = dir[0] + map[0] * (2 * x / (double)WIN_SIZE_X - 1);
	r->ray[1] = dir[1] + map[1] * (2 * x / (double)WIN_SIZE_X - 1);
	r->delta_dist[0] = fabs(1 / r->ray[0]);
	r->delta_dist[1] = fabs(1 / r->ray[1]);
	r->pts[0] = (int)game->x_pos;
	r->pts[1] = (int)game->y_pos;
	get_dir(game, r);
}

static void	next_param_ray(t_game *game, t_ray *r)
{
	r->height = (int)(WIN_SIZE_Y / r->angl_dist * 1);
	r->start = -r->height / 2 + WIN_SIZE_Y / 2 + game->view;
	r->end = r->height / 2 + WIN_SIZE_Y / 2 + game->view;
	if (r->start < 0)
		r->start = 0;
	if (r->end >= WIN_SIZE_Y)
		r->end = WIN_SIZE_Y;
}

//the loop will increment 1 until we hit a wall
//- If the dist_next[x] < dist_next[y], x is the closest point from the ray
static void	param_ray(t_game *game, t_ray *r)
{
	int	flag;

	flag = 0;
	r->side = 0;
	while (flag == 0)
	{
		if (r->dist_next[0] < r->dist_next[1])
		{
			r->dist_next[0] += r->delta_dist[0];
			r->pts[0] += r->next_pts[0];
			r->side = 0;
		}
		else
		{
			r->dist_next[1] += r->delta_dist[1];
			r->pts[1] += r->next_pts[1];
			r->side = 1;
		}
		if (is_wall(game, r) != 0)
			flag = 1;
	}
	r->angl_dist = r->dist_next[r->side] - r->delta_dist[r->side];
	next_param_ray(game, r);
}

static void	init_ray(t_ray *r)
{
	r->ray[0] = 0;
	r->ray[1] = 0;
	r->dist_next[0] = 0;
	r->dist_next[1] = 0;
	r->pts[0] = 0;
	r->pts[1] = 0;
	r->delta_dist[0] = 0;
	r->delta_dist[1] = 0;
	r->angl_dist = 0;
	r->next_pts[0] = 0;
	r->next_pts[1] = 0;
	r->side = 0;
	r->height = 0;
	r->start = 0;
	r->end = 0;
}

void	raycasting(t_game *game)
{
	t_ray		r;
	t_texture	t;
	int			x;

	x = -1;
	init_ray(&r);
	init_texture(&t);
	while (++x < WIN_SIZE_X)
	{
		start_ray(game, &r, x);
		param_ray(game, &r);
		param_text(game, &r, &t);
		param_text_2(game, &r, &t, x);
	}
}
