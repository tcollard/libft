/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:38:23 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/15 18:42:14 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	add_width_preci(char *str, size_t *i, t_flag *tab)
{
	while (ft_isdigit(str[*i]) == 1 && str[*i] != '\0')
	{
		tab->width = tab->width * 10 + str[*i] - 48;
		*i += 1;
	}
	if (str[*i] == '.')
	{
		*i += 1;
		tab->precision = 0;
		while (ft_isdigit(str[*i]) == 1 && str[*i] != '\0')
		{
			tab->precision = tab->precision * 10 + str[*i] - 48;
			*i += 1;
		}
	}
}

int		flag_modifier(char *s, size_t *i, t_flag *tab)
{
	while (1)
	{
		if (s[*i] == 'h' || s[*i] == 'l' || s[*i] == 'j' || s[*i] == 'z')
			add_modifier(s, i, tab);
		else if (s[*i] == '-' || s[*i] == '0' || s[*i] == '+' ||
				s[*i] == ' ' || s[*i] == '#')
			add_flag(s, i, tab);
		else if (ft_isdigit(s[*i]) == 1 || s[*i] == '.')
			add_width_preci(s, i, tab);
		else
			break ;
	}
	return (*i);
}

char	*ft_check(char *s, size_t *i, t_flag *tab, va_list *ap)
{
	char	*var;
	size_t	x;

	var = NULL;
	(ft_isdigit(s[*i]) == 1 && s[*i] != '0') ? add_width_preci(s, i, tab) : 0;
	x = flag_modifier(s, i, tab);
	if (conv_first(s, i, tab, &var) == -1)
		return (var);
	*i -= conversion(s[*i], ap, tab, &var);
	if (s[*i] != 'C' && s[*i] != 'S' && (s[*i] != 'c' || tab->length[2] == 0))
	{
		if (tab->precision != -1 && var[0] != '%' && s[*i] != 'c')
			modif_precision(tab, &var, s[*i]);
		var = dispatch_flag(tab, var, s[*i]);
		if (x > *i && tab->flag[2] == 1)
		{
			ft_display(tab);
			*i += 1;
			write(1, &s[*i], 1);
			tab->ret += 1;
		}
		add_var(tab, var);
	}
	*i += 1;
	return (var);
}
