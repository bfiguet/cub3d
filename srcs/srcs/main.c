/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:13:26 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/05 21:37:06 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cub3d(t_game *game)
{
	game->img->name = mlx_new_image(game->mlx, WIN_SIZE_X, WIN_SIZE_Y);
	game->img->add = (int *)mlx_get_data_addr(game->img->name,
			&(game->img->bpp), &(game->img->size), &(game->img->endian));
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->name, 0, 0);
	mlx_destroy_image(game->mlx, game->img->name);
	game->img->name = NULL;
}

int	loop(t_game *game)
{
	player_move(game);
	cub3d(game);
	return (0);
}

static int	is_cub_file(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'c' || arg[len - 2] != 'u'
			|| arg[len - 1] != 'b' || arg[len - 4] != '.'))
		return (0);
	return (1);
}

void	print_err(t_game *game, char *s)
{
	ft_putstr_fd("Error: \n", 2);
	ft_putstr_fd(s, 2);
	free_next_line(game);
	free_game(game);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2 || !is_cub_file(av[1]))
	{
		printf("Error\nNeed 2 arguments\n./cub3d and \"<name>.cub\"\n");
		exit(1);
	}
	if (ft_strlen(av[1]) <= 4
		|| ft_strcmp(av[(int)ft_strlen(av[1]) - 4], ".cub") == 0)
	{
		ft_printf("Error\nNeed \"<name>.cub\"\n");
		exit(1);
	}
	game = init_game();
	parse_map(game, av[1]);
	check_map(game);
	init_window(game);
	load_textures(game);
	event_hook(game);
	cub3d(game);
	mlx_loop_hook(game->mlx, loop, game);
	mlx_loop(game->mlx);
	print_err(game, "error mlx_loop\n");
	return (0);
}
