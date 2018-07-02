/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:16:55 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/15 19:37:52 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*plus(char **v, char c, t_flag *tab)
{
	char	*modif;
	char	*add;
	int		len;

	len = (int)ft_strlen(*v);
	if (**v == '-' || c == 'x' || c == 'X' || c == 'o' || c == 'O' || c == 'p')
		return (*v);
	if (tab->width > len && c != 'u' && tab->flag[2] == 0 && tab->flag[1] == 0)
	{
		if (!(add = ft_memalloc(tab->width - len + 1)))
			return (NULL);
		add = ft_memset(add, ' ', tab->width - len);
		add[tab->width - len - 1] = '+';
	}
	else if (c != 'u')
	{
		(tab->width <= len + 1) ? tab->flag[1] = 0 : 0;
		add = ft_strdup("+");
	}
	else
		return (*v);
	modif = ft_strjoin(add, *v);
	free(add);
	(len != 0) ? free(*v) : 0;
	return (modif);
}
