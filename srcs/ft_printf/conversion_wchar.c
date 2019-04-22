/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_wchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:21:27 by tcollard          #+#    #+#             */
/*   Updated: 2018/10/18 19:07:51 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*ft_width(int nb_octet, t_flag *tab_p, char c)
{
	char	*width;
	char	z;

	(void)c;
	width = NULL;
	z = ' ';
	if (tab_p->width > nb_octet)
	{
		if (!(width = ft_memalloc((size_t)(tab_p->width - nb_octet + 1))))
		{
			tab_p->ret = -1;
			return (NULL);
		}
		(tab_p->flag[1] == 1) ? z = '0' : z;
		width = ft_memset(width, z, tab_p->width - nb_octet);
		(tab_p->flag[2] == 0) ? add_var(tab_p, width) : 0;
	}
	return (width);
}

void		conv_wchar_s(va_list *ap, t_flag *tab_p, char c)
{
	int		nb_octet;
	wchar_t	*str;
	char	*width;

	nb_octet = 0;
	if (!(str = (wchar_t *)va_arg(*ap, wchar_t*)))
		add_var(tab_p, "(null)");
	else if ((nb_octet = nb_octet_str(str, tab_p)) == -1)
		return ;
	width = ft_width(nb_octet, tab_p, c);
	while (str && *str && nb_octet > 0)
	{
		if (*str < 256)
		{
			ft_display(tab_p);
			write(1, str, 1);
			tab_p->ret += 1;
			nb_octet -= 1;
		}
		else
			nb_octet = conv_wc(*str, tab_p, nb_octet);
		str++;
	}
	(tab_p->flag[2] == 1 && width) ? add_var(tab_p, width) : 0;
}

void		conv_wchar_c(va_list *ap, t_flag *tab_p, char c)
{
	wchar_t	wc;
	char	*width;
	int		nb_octet;

	nb_octet = 0;
	wc = (wchar_t)va_arg(*ap, wchar_t);
	if ((nb_octet = nb_octet_char(wc, tab_p)) == -1)
		return ;
	(wc < 256) ? (width = ft_width(1, tab_p, c)) : 0;
	(wc < 256) ? 0 : (width = ft_width(nb_octet, tab_p, c));
	if (nb_octet <= MB_CUR_MAX)
		conv_wc(wc, tab_p, nb_octet);
	else if (wc < 256)
	{
		write(1, &wc, 1);
		tab_p->ret += 1;
	}
	else
	{
		ft_display_prev(tab_p);
		tab_p->ret = -1;
	}
	(tab_p->flag[2] == 1 && tab_p->width > nb_octet) ?
		add_var(tab_p, width) : 0;
	ft_display(tab_p);
}

void		conv_wchar(va_list *ap, t_flag *tab_p, char c)
{
	if (c == 'C' || (c == 'c' && tab_p->length[2] == 1))
		conv_wchar_c(ap, tab_p, c);
	else
		conv_wchar_s(ap, tab_p, c);
	reinit_tab(tab_p);
}

int			conv_wc(wchar_t c, t_flag *tab_p, int nb)
{
	char	*binaire;
	int		len;
	int		nb_octet;

	nb_octet = 0;
	binaire = ft_itoa_base((int)c, 2);
	len = (int)ft_strlen(binaire);
	(c <= 0x7F) ? nb_octet = 1 : 0;
	(c > 0x7F && c <= 0x7FF) ? nb_octet = 2 : 0;
	(c > 0x7FF && c <= 0xFFFF) ? nb_octet = 3 : 0;
	(c > 0xFFFF && c <= 0x10FFFF) ? nb_octet = 4 : 0;
	if ((c >= 0xD800 && c <= 0xDFFF) || c > 0x10FFFF ||
			c < 0 || nb_octet > MB_CUR_MAX)
	{
		tab_p->ret = -1;
		return (-1);
	}
	nb -= nb_octet;
	(nb >= 0) ? apply_mask(binaire, len - 1, nb_octet, tab_p) : 0;
	return (nb);
}
