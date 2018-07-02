/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_flag_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 11:24:15 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/15 19:34:41 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*zero_1(char **var, char c, t_flag *tab, int len)
{
	char	*tmp;
	char	*modif;
	char	*add;
	char	z;
	int		i;

	i = 0;
	z = '0';
	tmp = "+";
	if (tab->precision != -1 && c != 'd' && c != 'D' && c != 's' &&
			**var != '%' && len != 0)
		z = ' ';
	((c == 'o' || c == 'O') && tab->flag[0] == 1) ? (i = 1) : i;
	((c == 'x' || c == 'X') && tab->flag[0] == 1) ? (i = 2) : i;
	if (!(add = ft_memalloc(tab->width - len + 1 - i)))
		return (NULL);
	modif = ft_strjoin(tmp, ft_memset(add, z, tab->width - len));
	modif = ft_strjoin(modif, ft_strsub(*var, 1, len));
	return (modif);
}

static char	*zero_2(char **var, t_flag *tab, int len, char c)
{
	int		i;
	char	z;
	char	*modif;
	char	*add;

	i = 0;
	z = '0';
	if (c == 'd' || c == 'D' || c == 'i' || c == 'u')
	{
		if (tab->precision != -1 && c != 'd' && c != 'D' && c != 's'
				&& **var != '%' && len != 0)
			z = ' ';
	}
	((c == 'o' || c == 'O') && tab->flag[0] == 1) ? (i = 1) : i;
	((c == 'x' || c == 'X') && tab->flag[0] == 1) ? (i = 2) : i;
	if (!(add = ft_memalloc(tab->width - len + 1 - i)))
		return (NULL);
	modif = ft_strjoin(ft_memset(add, z, tab->width - len - i), *var);
	free(add);
	free(*var);
	return (modif);
}

static char	*zero_3(char **var, char c, t_flag *tab, int len)
{
	char	*tmp;
	char	*add;
	char	*modif;

	tmp = "0x";
	(c == 'X') ? tmp = "0X" : tmp;
	if (!(add = ft_memalloc(tab->width - len + 1)))
		return (NULL);
	if (ft_atoi(*var) != 0 || (*var)[1] == 'x' || (*var)[1] == 'X')
	{
		modif = ft_strjoin(tmp, ft_memset(add, '0', tab->width - len));
		modif = ft_strjoin(modif, &((*var)[2]));
	}
	else
		modif = ft_strjoin(ft_memset(add, '0', tab->width - len), *var);
	free(add);
	free(*var);
	return (modif);
}

static char	*zero_4(char **var, char c, t_flag *tab, int len)
{
	char	*modif;
	char	*add;
	char	*tmp;
	char	z;

	add = NULL;
	z = '0';
	if (tab->precision != -1 && c != 'd' && c != 'D' && c != 's' &&
			**var != '%' && len != 0)
		z = ' ';
	if ((c == 'x' || c == 'X' || c == 'p') && tab->flag[0] == 1)
		return (zero_3(var, c, tab, len));
	else if ((c == 'o' || c == 'O') && tab->flag[0] == 1)
	{
		tmp = "0";
		if (!(add = ft_memalloc(tab->width - len + 1)))
			return (NULL);
		modif = ft_strjoin(tmp, *var);
		modif = ft_strjoin(ft_memset(add, z, tab->width - len), *var);
	}
	else
		modif = zero_1(var, c, tab, len);
	free(add);
	free(*var);
	return (modif);
}

char		*zero(char **var, char c, t_flag *tab)
{
	char	*modif;
	int		len;
	int		i;

	i = 0;
	modif = ft_strdup(*var);
	len = (int)ft_strlen(*var);
	if ((c == 'd' || c == 'D' || c == 'i' || c == 'u') && tab->precision == -1)
	{
		(**var == '-' || **var == '+') ? (i = 1) : i;
		if (tab->flag[4] == 1)
			tab->precision = tab->width - 1;
		else
			tab->precision = tab->width + i;
		precision_on_int(tab, var, c);
		free(modif);
		return (*var);
	}
	if (tab->width > len && tab->flag[3] == 0 && tab->flag[0] == 0)
		modif = zero_2(var, tab, len, c);
	else if (tab->width > len)
		modif = zero_4(var, c, tab, len);
	return (modif);
}
