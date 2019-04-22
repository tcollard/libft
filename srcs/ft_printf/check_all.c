/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:38:23 by tcollard          #+#    #+#             */
/*   Updated: 2018/10/18 18:00:20 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	add_width_preci(char *str, size_t *i, t_flag *tab_p)
{
	while (ft_isdigit(str[*i]) == 1 && str[*i] != '\0')
	{
		tab_p->width = tab_p->width * 10 + str[*i] - 48;
		*i += 1;
	}
	if (str[*i] == '.')
	{
		*i += 1;
		tab_p->precision = 0;
		while (ft_isdigit(str[*i]) == 1 && str[*i] != '\0')
		{
			tab_p->precision = tab_p->precision * 10 + str[*i] - 48;
			*i += 1;
		}
	}
}

int		flag_modifier(char *s, size_t *i, t_flag *tab_p)
{
	while (1)
	{
		if (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z')
			add_modifier(s, i, tab_p);
		else if (s[*i] == '-' || s[*i] == '0' || s[*i] == '+' ||
				s[*i] == ' ' || s[*i] == '#')
			add_flag(s, i, tab_p);
		else if (ft_isdigit(s[*i]) == 1 || s[*i] == '.')
			add_width_preci(s, i, tab_p);
		else
			break ;
	}
	return (*i);
}

char	*ft_check(char *s, size_t *i, t_flag *tab_p, va_list *ap)
{
	char	*var;
	size_t	x;

	var = NULL;
	(ft_isdigit(s[*i]) == 1 && s[*i] != '0') ? add_width_preci(s, i, tab_p) : 0;
	x = flag_modifier(s, i, tab_p);
	if (conv_first(s, i, tab_p, &var) == -1)
		return (var);
	*i -= conversion(s[*i], ap, tab_p, &var);
	if (s[*i] != 'C' && s[*i] != 'S' && (s[*i] != 'c' || tab_p->length[2] == 0))
	{
		if (tab_p->precision != -1 && var[0] != '%' && s[*i] != 'c')
			modif_precision(tab_p, &var, s[*i]);
		var = dispatch_flag(tab_p, var, s[*i]);
		if (x > *i && tab_p->flag[2] == 1)
		{
			ft_display(tab_p);
			*i += 1;
			write(1, &s[*i], 1);
			tab_p->ret += 1;
		}
		add_var(tab_p, var);
	}
	*i += 1;
	return (var);
}
