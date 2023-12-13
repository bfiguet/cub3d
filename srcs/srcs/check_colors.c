/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:57:19 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/05 16:08:33 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*parse_color(t_game *game, char *code)
{
	if (ft_isdigit(*code) != 1)
		print_err(game, "color value doesn't exist\n");
	while (ft_isdigit(*code) == 1)
		code++;
	return (code);
}

static char	*parse_comma(t_game *game, char *code)
{
	while (ft_isspace(*code))
		code++;
	if (*code != ',')
		print_err(game, "error color value\n");
	code++;
	while (ft_isspace(*code))
		code++;
	return (code);
}

int	get_code(t_game *game, char *code)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(code);
	while (*code != ',')
		code++;
	code++;
	g = ft_atoi(code);
	while (*code != ',')
		code++;
	code++;
	b = ft_atoi(code);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		print_err(game, "error color value\n");
	return (r << 16 | g << 8 | b);
}

void	check_colors(t_game *game, char *code)
{
	code = parse_color(game, code);
	code = parse_comma(game, code);
	code = parse_color(game, code);
	code = parse_comma(game, code);
	code = parse_color(game, code);
	if (*code != '\0')
		print_err(game, "error color value\n");
}
