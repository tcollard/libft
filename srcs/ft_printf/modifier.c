/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifier.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:27:43 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/15 20:12:08 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	init_modifier(t_flag *tab)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		tab->length[i] = 0;
		i += 1;
	}
}

void	check_modifier(t_flag *tab)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (i < 6)
	{
		if (tab->length[i] != 0)
			check += 1;
		i += 1;
	}
	if (check > 1)
	{
		init_modifier(tab);
		tab->length[6] = 1;
	}
}

void	add_modifier(char *str, size_t *i, t_flag *tab)
{
	while (str[*i] == 'h' || str[*i] == 'l' || str[*i] == 'j' || str[*i] == 'z')
	{
		if (str[*i] == 'h')
		{
			(str[*i + 1] == 'h') ? tab->length[1] += 1 : 0;
			(str[*i + 1] != 'h') ? tab->length[0] += 1 : 0;
			(str[*i + 1] == 'h') ? *i += 1 : 0;
		}
		if (str[*i] == 'l')
		{
			(str[*i + 1] == 'l') ? tab->length[3] += 1 : 0;
			(str[*i + 1] != 'l') ? tab->length[2] += 1 : 0;
			(str[*i + 1] == 'l') ? *i += 1 : 0;
		}
		(str[*i] == 'j') ? tab->length[4] += 1 : 0;
		(str[*i] == 'z') ? tab->length[5] += 1 : 0;
		*i += 1;
	}
	check_modifier(tab);
}
