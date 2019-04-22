/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:03:47 by tcollard          #+#    #+#             */
/*   Updated: 2018/10/18 18:06:01 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	reinit_tab(t_flag *tab_p)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		tab_p->flag[i] = 0;
		tab_p->length[i] = 0;
		i += 1;
	}
	tab_p->length[i] = 0;
	tab_p->width = 0;
	tab_p->precision = -1;
}

void	init_tab(t_flag *tab_p)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		tab_p->flag[i] = 0;
		tab_p->length[i] = 0;
		i += 1;
	}
	tab_p->length[i] = 0;
	tab_p->width = 0;
	tab_p->precision = -1;
	tab_p->ret = 0;
	tab_p->i = 0;
	tab_p->save_i = 0;
	init_buff(tab_p);
}

void	ft_ret(t_flag *tab_p, char c)
{
	if (tab_p->i < SIZE)
	{
		tab_p->buff[tab_p->i] = c;
		tab_p->i += 1;
	}
	else
	{
		ft_display(tab_p);
		tab_p->buff[0] = c;
		tab_p->i = 1;
	}
}

void	add_var(t_flag *tab_p, char *var)
{
	int	i;

	i = 0;
	while (var[i] != '\0')
	{
		if (tab_p->i < SIZE)
		{
			tab_p->buff[tab_p->i] = var[i];
			tab_p->i += 1;
			i += 1;
		}
		else
		{
			ft_display(tab_p);
			tab_p->i = 0;
		}
	}
}
