/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfiguet <bfiguet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:42:35 by bfiguet           #+#    #+#             */
/*   Updated: 2023/11/20 18:13:26 by bfiguet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void			free_tab(char **tab);
void			ft_skip_space(char *str, int *i);
int				ft_issymbol(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_strcpy(char *dest, char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strcat(char *dst, const char *src);
char			*ft_strcat_malloc(char *str1, const char *str2);
char			*ft_strrev(char *str);
int				ft_tablen(char **tab);
int				ft_toupper(int c);
int				t_tolower(int c);
char			*ft_strchr(const char *s, int c);
int				ft_str_isdigit(char *str);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_mem_free(void *ptr);
int				ft_memcmp(const void *s1, const void *s2, size_t size);
char			*ft_strnstr(const char *haystack, const char *needle,
					size_t len);
int				ft_atoi(const char *str);
long long int	ft_atol(const char *str);
int				ft_itoa_no_malloc(int nbr, char *buff);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s1, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin2(char *s1, char const *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(const char *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s1, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putendl(char *s);
void			ft_putendl_fd(char *s, int fd);

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void
					(*del)(void *));
//ft_printf_utils.c
void			ft_putstr(char *s);
int				ft_print_str(char *s);
int				ft_print_nbr(int n);
int				ft_print_percent(void);
//ft_printf.c
int				ft_printchar(int c);
int				ft_flags(va_list args, const char type);
int				ft_printf(const char *s, ...);
//ft_printhexa.c
void			ft_hexa(unsigned int n, const char type);
int				ft_print_hexa(unsigned int n, const char type);
//ft_print_ptr.c
void			ft_ptr(uintptr_t n);
int				ft_print_ptr(unsigned long long ptr);
//ft_print_unsigned.c
char			*ft_uitoa(unsigned int n);
int				ft_print_unsigned(unsigned int n);
//get_next_line.c
char			*ft_read(int fd, char *s);
char			*ft_get_line(char *s);
char			*ft_save( char *s);
char			*get_next_line(int fd);
//get_next_line_utils.c
char			*gnl_chr(char *s, int c);
size_t			gnl_len(char *str);
char			*gnl_join(char *s1, char *s2);

#endif
