/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:36:56 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/20 15:06:38 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	init_buff(t_flag *tab)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		tab->buff[i] = '\0';
		i += 1;
	}
}

void	ft_display_prev(t_flag *tab)
{
	if (tab->ret == -1)
		return ;
	tab->ret += tab->save_i;
	write(1, &(tab->buff), tab->save_i);
	init_buff(tab);
	tab->i = 0;
}

void	ft_display(t_flag *tab)
{
	if (tab->ret == -1)
		return ;
	tab->ret += (tab->i);
	write(1, &(tab->buff), tab->i);
	init_buff(tab);
	tab->i = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	tab;
	size_t	i;
	char	*var;

	i = 0;
	va_start(ap, format);
	init_tab(&tab);
	var = NULL;
	while (format[i] != '\0' && tab.ret != -1)
		if (format[i] == '%' && format[i++])
		{
			if (!(var = ft_check((char *)format, &i, &tab, &ap)))
				return (-1);
			reinit_tab(&tab);
			tab.save_i = tab.i;
			free(var);
		}
		else
			ft_ret(&tab, format[i++]);
	(tab.buff[0] != '\0') ? ft_display(&tab) : 0;
	va_end(ap);
	return (tab.ret);
}
