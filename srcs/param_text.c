/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:18:29 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/05 21:49:57 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_game *game, t_ray *r)
{
	t_pts	*pts;

	pts = game->pts;
	while (pts != NULL)
	{
		if (pts->x == r->pts[0] && pts->y == r->pts[1] && pts->name == '1')
			return (1);
		pts = pts->next;
	}
	return (0);
}

/* r->dist_next[x] or y = distance from the ray start position 
		to the next x or y position
 if x or y < 0 go the next x or y to the left
 if x or y > 0 go the next x or y to the right */
void	get_dir(t_game *game, t_ray *r)
{
	if (r->ray[0] < 0)
	{
		r->next_pts[0] = -1;
		r->dist_next[0] = ((double)game->x_pos - r->pts[0]) * r->delta_dist[0];
	}
	else
	{
		r->next_pts[0] = 1;
		r->dist_next[0] = (r->pts[0] + 1.0 - (double)game->x_pos) \
			* r->delta_dist[0];
	}
	if (r->ray[1] < 0)
	{
		r->next_pts[1] = -1;
		r->dist_next[1] = ((double)game->y_pos - r->pts[1]) * r->delta_dist[1];
	}
	else
	{
		r->next_pts[1] = 1;
		r->dist_next[1] = (r->pts[1] + 1.0 - (double)game->y_pos) \
			* r->delta_dist[1];
	}
}

void	param_text_2(t_game *game, t_ray *r, t_texture *t, int x)
{
	int	y;

	y = -1;
	while (++y < r->start)
		game->img->add[y * WIN_SIZE_X + x] = game->ref_color_c;
	y = r->end - 1;
	while (++y < WIN_SIZE_Y)
		game->img->add[y * WIN_SIZE_X + x] = game->ref_color_f;
	t->posix[0] = (int)(t->posix_wall * (double)TEXTURE_SIZE);
	if ((r->side == 0 && r->ray[0] < 0) || (r->side == 1 && r->ray[1] > 0))
		t->posix[0] = TEXTURE_SIZE - t->posix[0] - 1;
	while (r->start < r->end)
	{
		t->posix[1] = (int)t->start & (TEXTURE_SIZE - 1);
		t->start += t->step;
		game->img->add[r->start * WIN_SIZE_X + x] = (game->textures[t->nb] \
			->add)[t->posix[0] + t->posix[1] * TEXTURE_SIZE];
		r->start++;
	}
}

void	param_text(t_game *game, t_ray *r, t_texture *t)
{
	if (r->side == 0)
	{
		if (r->ray[0] < 0)
			t->nb = WEST;
		else
			t->nb = EAST;
	}
	else
	{
		if (r->ray[1] < 0)
			t->nb = SOUTH;
		else
			t->nb = NORTH;
	}
	if (r->side == 0)
		t->posix_wall = game->y_pos + r->angl_dist * r->ray[1];
	else
		t->posix_wall = game->x_pos + r->angl_dist * r->ray[0];
	t->posix_wall -= floor(t->posix_wall);
	t->step = (double)TEXTURE_SIZE / (double)r->height;
	t->start = t->step * (r->start - WIN_SIZE_Y
			/ 2 + r->height / 2 - game->view);
}
