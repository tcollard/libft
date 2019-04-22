/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:50:58 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 11:37:50 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "get_next_line.h"

# define ANSI_RED					"\x1b[31m"
# define ANSI_GREEN					"\x1b[32m"
# define ANSI_YELLOW				"\x1b[33m"
# define ANSI_BLUE					"\x1b[34m"
# define ANSI_MAGENTA				"\x1b[35m"
# define ANSI_CYAN					"\x1b[36m"
# define ANSI_WHITE					"\x1b[97m"
# define ANSI_LIGHT_GRAY			"\x1b[47m"
# define ANSI_DARK_GRAY				"\x1b[100m"
# define ANSI_LIGHT_RED				"\x1b[101m"
# define ANSI_LIGHT_GREEN			"\x1b[102m"
# define ANSI_LIGHT_YELLOW			"\x1b[103m"
# define ANSI_LIGHT_BLUE			"\x1b[104m"
# define ANSI_LIGHT_MAGENTA			"\x1b[105m"
# define ANSI_LIGHT_CYAN			"\x1b[106m"

# define ANSI_DEF_BG				"\x1b[49m"
# define ANSI_RESET					"\x1b[0m"

# define ANSI_BOLD					"\e[1m"
# define ANSI_UNDERLINED			"\e[4m"
# define ANSI_BLINK					"\e[5m"
# define ANSI_BLACK					"\e[30m"
# define ANSI_MATRIX				"\e[5;32m"

void				ft_putchar(char b);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putendl(char const *s);
void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memalloc(size_t n);
void				ft_memdel(void **ap);
void				ft_memdel0(char **ap);
void				ft_memdel2(char ***ap);
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *nptr);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_isspace(char c);
int					ft_strequ(char const*s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_recursive_factorial(int nb);
int					ft_sqrt(int nb);
int					ft_count_digit(int nb);
char				*ft_strtrim(char const *s);
char				*ft_strrev(char const *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strcatc(char *s, int c);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
		size_t len);
char				*ft_strnew(size_t size);
char				*ft_itoa(int n);
char				*ft_itoa_base(int nb, int base);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				**ft_strsplit(char const *s, char c);
char				**ft_splitwhitespace(char const *s);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_l_dbl
{
	void			*content;
	size_t			content_size;
	struct s_l_dbl	*next;
	struct s_l_dbl	*prev;
}					t_l_dbl;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lst_push_back(t_list *alst, t_list *lst_end);
void				ft_lst_rev(t_list **alst);
char				*ft_strwhcpy(char *dst, char const *src, unsigned int start,
					unsigned int end);
unsigned int		ft_lstsize(t_list *lst);
t_list				*ft_lstfind(t_list *alst, void *data, int (*cmp)());
char				**ft_twod_dup(const char **t);
t_l_dbl				*ft_ldblnew(void const *content, size_t content_size);
int					ft_ldbldel(t_l_dbl **fp);
void				ft_2(int n_bits, int octet, char **masks, char *bin_char);
int					ft_1(int n_bits, char *bin_char, unsigned int wchar);
int					unicode_display(const wchar_t *input);
char				*ft_path(const char *path, char *file_name);

#endif
