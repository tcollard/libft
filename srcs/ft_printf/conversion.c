/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:21:01 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/15 20:12:20 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			conv_first(char *s, size_t *i, t_flag *tab, char **str)
{
	char	c;

	c = s[*i];
	if (c == 'p')
	{
		tab->flag[0] = 1;
		tab->length[2] = 1;
	}
	if (c != 's' && c != 'c' && c != 'p' && c != 'C' && c != 'S' && c != '%'
			&& c != 'U' && c != 'D' && c != 'd' && c != 'x' && c != 'X' &&
			c != 'o' && c != 'O' && c != 'i' && c != 'u')
	{
		if (c == '-' && c == '+')
			add_flag(s, i, tab);
		else if (tab->width == 0)
		{
			*str = ft_strdup("");
			return (-1);
		}
	}
	return (0);
}

static int	conv_2nd(char c, char **str, va_list *ap, t_flag *tab)
{
	if (c == 'C' || c == 'S' || (c == 'c' && tab->length[2] == 1)
			|| (c == 's' && tab->length[2] == 1))
	{
		conv_wchar(ap, tab, c);
		*str = ft_strdup("");
		return (0);
	}
	else if (c == 's')
		return (conv_s(ap, str));
	else if (c == 'c')
		return (conv_c(ap, str, tab));
	else if (c == '%')
	{
		*str = ft_strdup("%");
		return (0);
	}
	else if (c == 'U')
		return (conv_ul(ap, str));
	else if (tab->length[6] == 1)
		return (conv_ll(ap, str, c));
	else if (tab->length[3] == 1 || c == 'D')
		return (conv_ll(ap, str, c));
	return (1);
}

static int	conv_3rd(char c, char **str, va_list *ap, t_flag *tab)
{
	if (tab->length[2] == 1 || c == 'O' || c == 'p')
		return (conv_l(ap, str, c));
	else if (tab->length[1] == 1)
		return (conv_hh(ap, str, c));
	else if (tab->length[0] == 1)
		return (conv_h(ap, str, c));
	else if (tab->length[4] == 1)
		return (conv_j(ap, str, c));
	else if (tab->length[5] == 1)
		return (conv_z(ap, str, c));
	else if (c == 'd' || c == 'x' || c == 'X' || c == 'o' ||
			c == 'i' || c == 'u')
		return (conv_int(ap, str, c));
	return (1);
}

int			conversion(char c, va_list *ap, t_flag *tab, char **str)
{
	if (conv_2nd(c, str, ap, tab) == 0)
		return (0);
	else if (conv_3rd(c, str, ap, tab) == 0)
		return (0);
	else
	{
		*str = ft_strdup("");
		tab->width -= 1;
		return (1);
	}
	return (0);
}
