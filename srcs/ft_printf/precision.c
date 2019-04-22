/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:11:05 by tcollard          #+#    #+#             */
/*   Updated: 2018/10/18 18:05:13 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char	*precision_start(t_flag *tab_p, int len, int i, char c)
{
	char	*start;

	start = NULL;
	if ((c == 'd' || c == 'i') && tab_p->flag[1] == 1)
		if ((tab_p->precision - len - i - 1) <= 0 && i == 1)
			start = ft_memset(ft_memalloc((size_t)(tab_p->precision - len + 1)),
					'0', tab_p->precision - len + 1);
		else
			start = ft_memset(ft_memalloc((size_t)(tab_p->precision - len -
							i - 1)), '0', tab_p->precision - len - i);
	else if (c == 'd' || c == 'p')
		start = ft_memset(ft_memalloc((size_t)(tab_p->precision - len + i)),
				'0', tab_p->precision - len + i);
	else
		start = ft_memset(ft_memalloc((size_t)(tab_p->precision - len + 1 + i)),
				'0', tab_p->precision - len + i);
	return (start);
}

void		precision_on_int(t_flag *tab_p, char **var, char c)
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
	if (tab_p->precision > len)
	{
		start = precision_start(tab_p, len, i, c);
		free(*var);
		(i == 1) ? *start = *tmp : 0;
		if (tmp[0] == '-' || tmp[0] == '+')
			*var = ft_strjoin(start, &tmp[1]);
		else
			*var = ft_strjoin(start, tmp);
	}
	else if (*tmp == '0' && tab_p->precision == 0 && c != 'p')
		*var = ft_strdup("");
	free(tmp);
	free(start);
}

void		modif_precision(t_flag *tab_p, char **var, char c)
{
	char	*tmp;

	tmp = NULL;
	if (c == 's' && tab_p->length[2] == 0)
	{
		if (tab_p->precision != 0)
		{
			tmp = ft_strsub(*var, 0, (size_t)tab_p->precision);
			free(*var);
			*var = ft_strdup(tmp);
			free(tmp);
		}
		else
			*var = ft_strdup("");
	}
	else if (tab_p->precision == 0 && **var != '%' && c != 'd' && c != 'D'
		&& c != 'i' && c != 'u' && c != 'o' && c != 'O' && c != 'x'
		&& c != 'X' && c != 'p')
	{
		*var = ft_strdup("");
	}
	else
		precision_on_int(tab_p, var, c);
}
