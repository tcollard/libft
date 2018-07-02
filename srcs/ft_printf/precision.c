/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:11:05 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/19 18:05:01 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*precision_start(t_flag *tab, int len, int i, char c)
{
	char	*start;

	start = NULL;
	if ((c == 'd' || c == 'i') && tab->flag[1] == 1)
		if ((tab->precision - len - i - 1) <= 0 && i == 1)
			start = ft_memset(ft_memalloc((size_t)(tab->precision - len + 1)),
					'0', tab->precision - len + 1);
		else
			start = ft_memset(ft_memalloc((size_t)(tab->precision - len -
							i - 1)), '0', tab->precision - len - i);
	else if (c == 'd' || c == 'p')
		start = ft_memset(ft_memalloc((size_t)(tab->precision - len + i)),
				'0', tab->precision - len + i);
	else
		start = ft_memset(ft_memalloc((size_t)(tab->precision - len + 1 + i)),
				'0', tab->precision - len + i);
	return (start);
}

void		precision_on_int(t_flag *tab, char **var, char c)
{
	int		len;
	char	*start;
	char	*tmp;
	int		i;

	len = (int)ft_strlen(*var);
	tmp = ft_strdup(*var);
	start = NULL;
	i = 0;
	(*tmp == '-' || *tmp == '+') ? (i = 1) : i;
	len -= i;
	if (tab->precision > len)
	{
		start = precision_start(tab, len, i, c);
		free(*var);
		(i == 1) ? *start = *tmp : 0;
		if (tmp[0] == '-' || tmp[0] == '+')
			*var = ft_strjoin(start, &tmp[1]);
		else
			*var = ft_strjoin(start, tmp);
	}
	else if (*tmp == '0' && tab->precision == 0 && c != 'p')
		*var = ft_strdup("");
	free(tmp);
	free(start);
}

void		modif_precision(t_flag *tab, char **var, char c)
{
	char	*tmp;

	tmp = NULL;
	if (c == 's' && tab->length[2] == 0)
	{
		if (tab->precision != 0)
		{
			tmp = ft_strsub(*var, 0, (size_t)tab->precision);
			free(*var);
			*var = ft_strdup(tmp);
			free(tmp);
		}
		else
			*var = ft_strdup("");
	}
	else if (tab->precision == 0 && **var != '%' && c != 'd' && c != 'D'
		&& c != 'i' && c != 'u' && c != 'o' && c != 'O' && c != 'x'
		&& c != 'X' && c != 'p')
	{
		*var = ft_strdup("");
	}
	else
		precision_on_int(tab, var, c);
}
