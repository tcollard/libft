/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:16:55 by tcollard          #+#    #+#             */
/*   Updated: 2018/10/18 17:58:24 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*plus(char **v, char c, t_flag *t)
{
	char	*modif;
	char	*add;
	int		len;

	len = (int)ft_strlen(*v);
	if (**v == '-' || c == 'x' || c == 'X' || c == 'o' || c == 'O' || c == 'p')
		return (*v);
	if (t->width > len && c != 'u' && t->flag[2] == 0 && t->flag[1] == 0)
	{
		if (!(add = ft_memalloc(t->width - len + 1)))
			return (NULL);
		add = ft_memset(add, ' ', t->width - len);
		add[t->width - len - 1] = '+';
	}
	else if (c != 'u')
	{
		(t->width <= len + 1) ? t->flag[1] = 0 : 0;
		add = ft_strdup("+");
	}
	else
		return (*v);
	modif = ft_strjoin(add, *v);
	free(add);
	(len != 0) ? free(*v) : 0;
	return (modif);
}
