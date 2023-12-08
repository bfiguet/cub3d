# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/05 19:08:42 by bfiguet           #+#    #+#              #
#    Updated: 2023/11/20 18:13:44 by bfiguet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
INCLUDE = libft.h
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f

SRCS = \
	free_tab.c \
	ft_skip_space.c \
	ft_issymbol.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_mem_free.c \
	ft_memmove.c \
	ft_strcpy.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strcat.c \
	ft_strcat_malloc.c \
	ft_tablen.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strrev.c \
	ft_str_isdigit.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_strndup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strjoin2.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_itoa_no_malloc.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putnbr_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_atol.c \

OBJS = $(SRCS:.c=.o)

BSRC = \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

BONUS = $(BSRC:.c=.o)

FTPRINTF = \
	ft_printf.c \
	ft_printf_utils.c \
	ft_print_hexa.c \
	ft_print_ptr.c \
	ft_print_unsigned.c \

FTGNL = \
	get_next_line.c \
	get_next_line_utils.c \

OFTPRINTF = $(FTPRINTF:.c=.o)
OGNL = $(FTGNL:.c=.o)

all: $(NAME) bonus

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

$(NAME): $(OBJS) $(OFTPRINTF) $(OGNL)
	$(AR)  $(NAME) $^
	ranlib $(NAME)

clean:
	$(RM) $(OBJS) $(BONUS) $(OFTPRINTF) $(OGNL)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(NAME) $(BONUS)
		$(AR) $(NAME) $(BONUS)

.PHONY: 
	all clean fclean re bonus
