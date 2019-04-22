/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:21:01 by tcollard          #+#    #+#             */
/*   Updated: 2018/10/18 18:01:13 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			conv_first(char *s, size_t *i, t_flag *tab_p, char **str)
{
	char	c;

	c = s[*i];
	if (c == 'p')
	{
		tab_p->flag[0] = 1;
		tab_p->length[2] = 1;
	}
	if (c != 's' && c != 'c' && c != 'p' && c != 'C' && c != 'S' && c != '%'
			&& c != 'U' && c != 'D' && c != 'd' && c != 'x' && c != 'X' &&
			c != 'o' && c != 'O' && c != 'i' && c != 'u')
	{
		if (c == '-' && c == '+')
			add_flag(s, i, tab_p);
		else if (tab_p->width == 0)
		{
			*str = ft_strdup("");
			return (-1);
		}
	}
	return (0);
}

static int	conv_2nd(char c, char **str, va_list *ap, t_flag *tab_p)
{
	if (c == 'C' || c == 'S' || (c == 'c' && tab_p->length[2] == 1)
			|| (c == 's' && tab_p->length[2] == 1))
	{
		conv_wchar(ap, tab_p, c);
		*str = ft_strdup("");
		return (0);
	}
	else if (c == 's')
		return (conv_s(ap, str));
	else if (c == 'c')
		return (conv_c(ap, str, tab_p));
	else if (c == '%')
	{
		*str = ft_strdup("%");
		return (0);
	}
	else if (c == 'U')
		return (conv_ul(ap, str));
	else if (tab_p->length[6] == 1)
		return (conv_ll(ap, str, c));
	else if (tab_p->length[3] == 1 || c == 'D')
		return (conv_ll(ap, str, c));
	return (1);
}

static int	conv_3rd(char c, char **str, va_list *ap, t_flag *tab_p)
{
	if (tab_p->length[2] == 1 || c == 'O' || c == 'p')
		return (conv_l(ap, str, c));
	else if (tab_p->length[1] == 1)
		return (conv_hh(ap, str, c));
	else if (tab_p->length[0] == 1)
		return (conv_h(ap, str, c));
	else if (tab_p->length[4] == 1)
		return (conv_j(ap, str, c));
	else if (tab_p->length[5] == 1)
		return (conv_z(ap, str, c));
	else if (c == 'd' || c == 'x' || c == 'X' || c == 'o' ||
			c == 'i' || c == 'u')
		return (conv_int(ap, str, c));
	return (1);
}

int			conversion(char c, va_list *ap, t_flag *tab_p, char **str)
{
	if (conv_2nd(c, str, ap, tab_p) == 0)
		return (0);
	else if (conv_3rd(c, str, ap, tab_p) == 0)
		return (0);
	else
	{
		*str = ft_strdup("");
		tab_p->width -= 1;
		return (1);
	}
	return (0);
}
