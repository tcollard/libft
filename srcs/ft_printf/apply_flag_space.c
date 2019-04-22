/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_space.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:14:20 by tcollard          #+#    #+#             */
/*   Updated: 2018/10/18 17:59:10 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char		*space(char **var, char c, t_flag *tab_p)
{
	char	*modif;
	char	*add;
	int		len;

	modif = NULL;
	add = NULL;
	len = (int)ft_strlen(*var);
	if (tab_p->width > len)
	{
		if (!(add = ft_memalloc(tab_p->width - len + 1)))
			return (NULL);
		add = ft_memset(add, ' ', tab_p->width - len);
		modif = ft_strjoin(add, *var);
		free(add);
	}
	else if ((c == 'd' || c == 'D' || c == 'i') && *var[0] != '-')
		modif = ft_strjoin(" ", *var);
	else
		return (*var);
	if (len != 0)
		free(*var);
	return (modif);
}
