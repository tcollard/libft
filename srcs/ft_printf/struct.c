/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:03:47 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/20 15:06:40 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	reinit_tab(t_flag *tab)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		tab->flag[i] = 0;
		tab->length[i] = 0;
		i += 1;
	}
	tab->length[i] = 0;
	tab->width = 0;
	tab->precision = -1;
}

void	init_tab(t_flag *tab)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		tab->flag[i] = 0;
		tab->length[i] = 0;
		i += 1;
	}
	tab->length[i] = 0;
	tab->width = 0;
	tab->precision = -1;
	tab->ret = 0;
	tab->i = 0;
	tab->save_i = 0;
	init_buff(tab);
}

void	ft_ret(t_flag *tab, char c)
{
	if (tab->i < SIZE)
	{
		tab->buff[tab->i] = c;
		tab->i += 1;
	}
	else
	{
		ft_display(tab);
		tab->buff[0] = c;
		tab->i = 1;
	}
}

void	add_var(t_flag *tab, char *var)
{
	int	i;

	i = 0;
	while (var[i] != '\0')
	{
		if (tab->i < SIZE)
		{
			tab->buff[tab->i] = var[i];
			tab->i += 1;
			i += 1;
		}
		else
		{
			ft_display(tab);
			tab->i = 0;
		}
	}
}
