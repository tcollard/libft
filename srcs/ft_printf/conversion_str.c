/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:39:38 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/15 17:22:42 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int			conv_s(va_list *ap, char **var)
{
	char *tmp;

	tmp = NULL;
	if (!(tmp = (char *)va_arg(*ap, char*)))
		*var = ft_strdup("(null)");
	else
		*var = ft_strdup(tmp);
	return (0);
}

static void	conv_c_width(char **var, t_flag *tab)
{
	char	*add;
	char	z;

	z = ' ';
	(tab->flag[1] == 1) ? z = '0' : z;
	add = ft_memset(ft_memalloc(tab->width), z, tab->width - 1);
	if (tab->flag[2] == 1)
	{
		ft_display(tab);
		reinit_tab(tab);
		write(1, var[0], 1);
		add_var(tab, add);
	}
	else if (tab->flag[2] == 0)
	{
		add_var(tab, add);
		ft_display(tab);
		reinit_tab(tab);
		write(1, var[0], 1);
	}
	free(add);
}

int			conv_c(va_list *ap, char **var, t_flag *tab)
{
	char	z;

	z = ' ';
	*var = ft_memalloc(2);
	**var = (int)va_arg(*ap, int);
	if (**var == 0)
	{
		tab->ret += 1;
		if (tab->width != 0)
			conv_c_width(var, tab);
		else
		{
			ft_display(tab);
			reinit_tab(tab);
			write(1, var[0], 1);
		}
		*var = ft_strdup("");
	}
	return (0);
}

int			conv_p(va_list *ap, char **var)
{
	char	*str;
	int		x;

	x = 0;
	str = ft_itoa_base_ull((unsigned long long)va_arg(*ap,
				unsigned long long), 16);
	*var = ft_strjoin("0x", str);
	while ((*var)[x] != '\0')
	{
		(*var)[x] = ft_tolower((int)((*var)[x]));
		x += 1;
	}
	return (0);
}
