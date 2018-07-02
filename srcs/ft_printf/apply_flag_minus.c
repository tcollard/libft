/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_minus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:11:40 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/15 18:43:55 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*minus(char **var, char c, t_flag *tab)
{
	char	*modif;
	char	*add;
	int		len;

	modif = NULL;
	add = NULL;
	len = (int)ft_strlen(*var);
	if ((tab->width > len) || c == 'c')
	{
		if (!(add = ft_memalloc(tab->width - len + 1)))
			return (NULL);
		add = ft_memset(add, ' ', tab->width - len);
		modif = ft_strjoin(*var, add);
		free(add);
		if (len != 0)
			free(*var);
	}
	else
		return (*var);
	return (modif);
}
