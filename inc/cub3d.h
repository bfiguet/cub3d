/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:13:16 by bfiguet           #+#    #+#             */
/*   Updated: 2023/12/08 17:47:38 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//INCLUDES//
# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define WIN_SIZE_X		1080
# define WIN_SIZE_Y		720

# if defined(__APPLE__) && defined(__MACH__)
#  define W 13 //advance
#  define S 1 //back
#  define D 2 //right
#  define A 0 //left
#  define RIGHT 124
#  define LEFT 123
#  define UP 126
#  define DOWN 125
#  define ESC 53
#  define BUTTON 79
#  define CLOSE 17
# else
#  define W 119 //advance
#  define S 115 //back
#  define D 100 //right
#  define A 97 //left
#  define RIGHT 65363
#  define LEFT 65361
#  define UP 65364
#  define DOWN 65362 
#  define ESC 65307
#  define BUTTON 79
#  define CLOSE 33
# endif

# define NB_KEY 8
# define KEY_W 0
# define KEY_A 1
# define KEY_S 2
# define KEY_D 3
# define KEY_LEFT 4
# define KEY_RIGHT 5
# define KEY_UP 6
# define KEY_DOWN 7

# define MOVE 0.1
# define ANGL 0.02
# define VIEW 10

//TEXTURE//
# define TEXTURE_SIZE	64
# define NB_TEXTURE 4
# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

//pts on map
typedef struct s_pts
{
	char			name;
	int				x;
	int				y;
	struct s_pts	*next;
}				t_pts;

typedef struct s_ray
{
	double		ray[2];
	double		dist_next[2];
	int			pts[2];
	double		delta_dist[2];
	double		angl_dist;
	int			next_pts[2];
	int			side;
	int			height;
	int			start;
	int			end;

}				t_ray;

typedef struct s_texture
{
	int			nb;
	int			posix[2];
	double		step;
	double		start;
	double		posix_wall;	
}				t_texture;

typedef struct s_img
{
	void		*name;
	int			*add;
	int			bpp;
	int			size;
	int			endian;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	int			key[NB_KEY];
	void		*win;
	int			status;
	int			x_len;
	int			y_len;
	double		x_pos;
	double		y_pos;
	double		angle;
	t_pts		*pts;
	t_img		*img;
	t_img		*textures[NB_TEXTURE];
	char		**color;
	int			pos_player;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*color_c;
	char		*color_f;
	int			ref_color_f;
	int			ref_color_c;
	int			view;
	int			map;
}				t_game;

//MAIN.C
void	cub3d(t_game *game);
int		loop(t_game *game);

//PAYCASTING.C
void	raycasting(t_game *game);

//CHECK_COLORS.C
void	check_colors(t_game *game, char *code);
int		get_code(t_game *game, char *code);

//CHECK_MAP.C
void	push_pts(t_game *game, t_pts *tmp);
void	check_map(t_game *game);

//EVENT_KEY.C
void	event_hook(t_game *game);

//PLAYER.C
void	posix_player(t_game *game, char *line, int i, int nb_l);
void	player_move(t_game *game);

//EXIT.C
void	free_img(t_game *game, t_img *img);
void	free_game(t_game *game);
void	print_err(t_game *game, char *s);

//INIT.C
t_img	*init_img(void);
t_pts	*init_pts(t_game *game, char *s);
void	init_window(t_game *game);
t_game	*init_game(void);

//IS_MOVE.C
void	change_view(int *view, int val);
void	is_rotat(double *angl, double rot);
void	is_move(t_game *game, int key, double move);

//PARAM_TEXT.C
int		is_wall(t_game *game, t_ray *r);
void	get_dir(t_game *game, t_ray *r);
void	param_text_2(t_game *game, t_ray *r, t_texture *t, int x);
void	param_text(t_game *game, t_ray *r, t_texture *t);

//PARSE_MAP.C
void	parse_map(t_game *game, char *av);

//REF_TEXT.C
void	ref_text(t_game *game, char *line);

//LOAD_TEXTURES.C
void	init_texture(t_texture *t);
void	load_textures(t_game *game);

//PARSE_UTILS.C
int		is_map(t_game *game, char *line);
int		is_empty(const char *s);
char	*dup_val(t_game *game, char *line, int i);
char	remove_spaces_from_str(char *string, int j);
int		is_xpm_file(char *arg);

#endif
