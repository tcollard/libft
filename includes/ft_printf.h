/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 09:57:07 by tcollard          #+#    #+#             */
/*   Updated: 2018/10/18 17:58:42 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <limits.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include "libft.h"

# define SIZE 60

typedef struct	s_flag
{
	int		flag[5];
	int		length[7];
	int		width;
	int		precision;
	int		ret;
	int		i;
	int		save_i;
	char	buff[SIZE];
}				t_flag;

int				ft_printf(const char *format, ...);

void			init_tab(t_flag *tab_p);
void			reinit_tab(t_flag *tab_p);
void			ft_ret(t_flag *tab_p, char c);
void			add_var(t_flag *tab_p, char *var);

void			add_modifier(char *str, size_t *i, t_flag *tab_p);
void			check_modifier(t_flag *tab_p);
void			inti_modifier(t_flag *tab_p);
int				flag_modifier(char *s, size_t *i, t_flag *tab_p);

char			*dispatch_flag(t_flag *tab_p, char *v, char c);
void			add_flag(char *str, size_t *i, t_flag *tab_p);
char			*hashtag(char **var, char c, t_flag *tab_p);
char			*minus(char **var, char c, t_flag *tab_p);
char			*space(char **var, char c, t_flag *tab_p);
char			*plus(char **v, char c, t_flag *t);
char			*zero(char **var, char c, t_flag *tab_p);

void			add_width_preci(char *str, size_t *i, t_flag *tab_p);
void			precision_on_int(t_flag *tab_p, char **var, char c);

int				conversion(char c, va_list *ap, t_flag *tab_p, char **str);
int				conv_first(char *s, size_t *i, t_flag *tab_p, char **str);
int				conv_s(va_list *ap, char **var);
int				conv_c(va_list *ap, char **var, t_flag *tab_p);
int				conv_p(va_list *ap, char **var);
int				conv_ul(va_list *ap, char **var);
int				conv_ll(va_list *ap, char **var, char c);
int				conv_l(va_list *ap, char **var, char c);
int				conv_int(va_list *ap, char **var, char c);
int				conv_hh(va_list *ap, char **var, char c);
int				conv_h(va_list *ap, char **var, char c);
int				conv_j(va_list *ap, char **var, char c);
int				conv_z(va_list *ap, char **var, char c);

int				nb_octet_str(wchar_t *str, t_flag *tab_p);
int				nb_octet_char(wchar_t wc, t_flag *tab_p);
void			conv_wchar(va_list *ap, t_flag *tab_p, char c);
int				conv_wc(wchar_t c, t_flag *tab_p, int nb_octet);
void			intit_mask(char ***octet, int nb_octet);
void			apply_mask(char *str, int x, int nb_octet, t_flag *tab_p);
void			print_wchar(char ***oct, int nb_octet, t_flag *tab_p);

void			modif_flag(t_flag *tab_p, char **var, char c);
void			modif_width(t_flag *tab_p, char **var, char c);
void			modif_precision(t_flag *tab_p, char **var, char c);

char			*ft_check(char *s, size_t *i, t_flag *tab_p, va_list *ap);
void			check_flag(t_flag *tab_p);

void			init_buff(t_flag *tab_p);
void			ft_display(t_flag *tab_p);
void			ft_display_prev(t_flag *tab_p);

int				ft_atoi_base(char *str, int base);
char			*ft_itoa_ll(long long n);
char			*ft_itoa_base_ull(unsigned long long nb, int base);
char			*ft_itoa_base_neg(int nb, int base);

#endif
