/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_hashtag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:08:07 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/15 19:23:32 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	verif_precision(char *var, int *i, t_flag *tab, char c)
{
	int	len;
	int	x;

	x = 0;
	len = (int)ft_strlen(var);
	if (tab->precision == len)
	{
		while (var[x] == '0' || var[x] == ' ')
			x += 1;
		if ((c == 'o' || c == 'O') && x >= 1)
			*i = 1;
		else if ((c == 'x' || c == 'X') && x >= 2)
			*i = 2;
		if ((c == 'x' || c == 'X') && tab->flag[0] == 1)
			*i = 0;
	}
}

char		*hashtag(char **var, char c, t_flag *tab)
{
	int		i;
	int		nb;
	char	*modif;

	i = 0;
	modif = NULL;
	verif_precision(*var, &i, tab, c);
	nb = ft_atoi(*var);
	if (nb == 0 && ft_strlen(*var) == 1 && ft_isdigit(**var) == 1 && c != 'p')
		return (*var);
	if (c == 'p' && tab->precision == 0 && nb == 0)
		modif = ft_strdup("0x");
	else if (c == 'p' && tab->precision != 0)
		modif = ft_strjoin("0x", &((*var)[i]));
	else if (c == 'o' || c == 'O')
		modif = ft_strjoin("0", &((*var)[i]));
	else if ((c == 'x' || c == 'p') && (tab->precision != 0 || tab->width != 0))
		modif = ft_strjoin("0x", &((*var)[i]));
	else if (c == 'X' && (tab->precision != 0 || tab->width != 0))
		modif = ft_strjoin("0X", &((*var)[i]));
	else
		return (*var);
	free(*var);
	return (modif);
}
