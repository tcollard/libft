/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:36:56 by tcollard          #+#    #+#             */
/*   Updated: 2018/10/18 18:04:14 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	init_buff(t_flag *tab_p)
{
	int	i;

	i = 0;
	while (i < SIZE)
	{
		tab_p->buff[i] = '\0';
		i += 1;
	}
}

void	ft_display_prev(t_flag *tab_p)
{
	if (tab_p->ret == -1)
		return ;
	tab_p->ret += tab_p->save_i;
	write(1, &(tab_p->buff), tab_p->save_i);
	init_buff(tab_p);
	tab_p->i = 0;
}

void	ft_display(t_flag *tab_p)
{
	if (tab_p->ret == -1)
		return ;
	tab_p->ret += (tab_p->i);
	write(1, &(tab_p->buff), tab_p->i);
	init_buff(tab_p);
	tab_p->i = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	tab_p;
	size_t	i;
	char	*var;

	i = 0;
	va_start(ap, format);
	init_tab(&tab_p);
	var = NULL;
	while (format[i] != '\0' && tab_p.ret != -1)
		if (format[i] == '%' && format[i++])
		{
			if (!(var = ft_check((char *)format, &i, &tab_p, &ap)))
				return (-1);
			reinit_tab(&tab_p);
			tab_p.save_i = tab_p.i;
			free(var);
		}
		else
			ft_ret(&tab_p, format[i++]);
	(tab_p.buff[0] != '\0') ? ft_display(&tab_p) : 0;
	va_end(ap);
	return (tab_p.ret);
}
