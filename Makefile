SHELL	= /bin/bash

CC		=	gcc
NAME	=	cub3d
CFLAGS	=	-Wall -Wextra -Werror
#CFLAGS	+=	-g3 -fsanitize=address
CFLAGS	+=	-g
#valgrind --tool=memcheck --leak-check=yes

MLX_PATH = mlx/
MLX_NAME = libmlx.a
MLX		 = $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

INC		=	-I ./inc/\
			-I ./libft/\
			-I ./mlx/

OBJS		=	$(patsubst srcs%, obj%, $(SRCS:.c=.o))
SRCS = $(addsuffix .c, \
		$(addprefix srcs/,	\
		raycasting \
		player \
		param_text \
		check_colors \
		check_map \
		event_key \
		exit \
		init \
		is_move \
		main \
		parse_map \
		ref_text \
		load_textures \
		parse_utils \
		))	\

all:		obj $(MLX) $(LIBFT) $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $@ $^ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm

$(LIBFT):
		make -C $(LIBFT_PATH)

$(MLX):
		make -C $(MLX_PATH)

obj:
		mkdir -p obj

obj/%.o: 	srcs/%.c Makefile
		$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
		$(MAKE) -C $(LIBFT_PATH) $@
#		$(MAKE) -C $(MLX_PATH) $@
		rm -rf obj

fclean:		clean
		$(MAKE) -C $(LIBFT_PATH) $@
		rm -rf $(NAME)

re:			fclean all

.PHONY: all clean fclean re
