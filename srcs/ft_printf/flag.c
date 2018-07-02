/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:50:35 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/15 19:38:33 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	check_flag(t_flag *tab)
{
	if (tab->flag[3] == 1)
		tab->flag[4] = 0;
	if (tab->flag[2] == 1)
		tab->flag[1] = 0;
}

void	add_flag(char *str, size_t *i, t_flag *tab)
{
	while (str[*i] == '-' || str[*i] == '0' || str[*i] == '+'
			|| str[*i] == ' ' || str[*i] == '#')
	{
		if (str[*i] == '#')
			tab->flag[0] = 1;
		if (str[*i] == '0')
			tab->flag[1] = 1;
		if (str[*i] == '-')
			tab->flag[2] = 1;
		if (str[*i] == '+')
			tab->flag[3] = 1;
		if (str[*i] == ' ')
			tab->flag[4] = 1;
		*i += 1;
	}
	check_flag(tab);
}

char	*dispatch_flag(t_flag *tab, char *v, char c)
{
	char	*add;
	char	*modif;
	char	z;
	int		len;

	z = ' ';
	(tab->flag[3] == 1 && *v != '%' && c != 's') ? v = plus(&v, c, tab) : 0;
	(tab->flag[0] == 1 && *v != '%') ? v = hashtag(&v, c, tab) : 0;
	(tab->flag[1] == 1 && (tab->precision == -1 || c == 's' || *v == '%'))
		? v = zero(&v, c, tab) : 0;
	(tab->flag[2] == 1) ? v = minus(&v, c, tab) : 0;
	(tab->flag[4] == 1) ? v = space(&v, c, tab) : 0;
	len = (int)ft_strlen(v);
	modif = ft_strdup(v);
	if (tab->width > len)
	{
		(len == 0 && tab->flag[1] == 1) ? z = '0' : 0;
		if (!(add = ft_memalloc(tab->width - len + 1)))
			return (NULL);
		free(v);
		v = ft_strjoin(ft_memset(add, z, tab->width - len), modif);
		free(add);
	}
	free(modif);
	return (v);
}
