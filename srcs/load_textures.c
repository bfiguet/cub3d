/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:37:17 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/05 16:06:42 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_texture *t)
{
	t->nb = 0;
	t->posix[0] = 0;
	t->posix[1] = 0;
	t->step = 0;
	t->start = 0;
	t->posix_wall = 0;
}

static void	load_text(t_game *game, char *name, int i, int *size)
{
	game->textures[i]->name = mlx_xpm_file_to_image (game->mlx, name,
			size, size);
	if (!game->textures[i]->name)
		print_err(game, "error load texture\n");
	game->textures[i]->add = (int *)mlx_get_data_addr(game->textures[i]->name, \
		&(game->textures[i]->bpp), &(game->textures[i]->size), \
		&(game->textures[i]->endian));
}

void	load_textures(t_game *game)
{
	int	size;

	size = TEXTURE_SIZE;
	load_text(game, game->north, NORTH, &size);
	load_text(game, game->south, SOUTH, &size);
	load_text(game, game->east, EAST, &size);
	load_text(game, game->west, WEST, &size);
}
