/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mask_wchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 18:25:52 by tcollard          #+#    #+#             */
/*   Updated: 2018/10/18 18:04:37 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		nb_octet_char(wchar_t wc, t_flag *tab_p)
{
	int	nb;

	nb = 0;
	(wc <= 0x7F) ? nb = 1 : 0;
	(wc > 0x7F && wc <= 0x7FF) ? nb = 2 : 0;
	(wc > 0x7FF && wc <= 0xFFFF) ? nb = 3 : 0;
	(wc > 0xFFFF && wc <= 0x10FFFF) ? nb = 4 : 0;
	if ((wc >= 0xD800 && wc <= 0xDFFF) || wc > 0x10FFFF || wc < 0)
	{
		tab_p->ret = -1;
		nb = -1;
	}
	return (nb);
}

int		nb_octet_str(wchar_t *str, t_flag *tab_p)
{
	int	nb;
	int byte;

	nb = 0;
	byte = 0;
	while (*str && tab_p->ret != -1)
	{
		byte = nb_octet_char(*str, tab_p);
		(*str < 256) ? byte = 1 : 0;
		if (byte > MB_CUR_MAX)
		{
			if (tab_p->precision == 0)
				break ;
			tab_p->ret = -1;
			return (-1);
		}
		if (tab_p->precision != -1 && tab_p->precision - byte >= 0)
			tab_p->precision -= byte;
		else if (tab_p->precision != -1)
			break ;
		nb += byte;
		str++;
	}
	return (nb);
}

void	init_mask(char ***oct, int nb_octet)
{
	int	tmp_octet;

	tmp_octet = 0;
	if (!(*oct = (char **)malloc(sizeof(char **) * nb_octet)))
		return ;
	while (tmp_octet < nb_octet)
	{
		if (!((*oct)[tmp_octet] = (char *)ft_memalloc(9)))
			return ;
		(*oct)[tmp_octet] = ft_memset((*oct)[tmp_octet], '0', 8);
		(tmp_octet != 0) ? (*oct)[tmp_octet][0] = '1' : 0;
		tmp_octet += 1;
	}
	(nb_octet > 1) ? (*oct)[0][0] = '1' : 0;
	(nb_octet >= 2) ? (*oct)[0][1] = '1' : 0;
	(nb_octet >= 3) ? (*oct)[0][2] = '1' : 0;
	(nb_octet == 4) ? (*oct)[0][3] = '1' : 0;
}

void	apply_mask(char *str, int x, int nb_octet, t_flag *tab_p)
{
	char	**oct;
	int		tmp_octet;
	int		i;

	tmp_octet = nb_octet - 1;
	init_mask(&oct, nb_octet);
	while (tmp_octet > 0)
	{
		i = 7;
		while (i > 1)
			oct[tmp_octet][i--] = str[x--];
		tmp_octet -= 1;
	}
	if (tmp_octet == 0)
	{
		i = 7;
		while (i > nb_octet - 1 && x >= 0)
			oct[0][i--] = str[x--];
	}
	print_wchar(&oct, nb_octet, tab_p);
}

void	print_wchar(char ***oct, int nb_octet, t_flag *tab_p)
{
	int	i;
	int	value;

	i = 0;
	ft_display(tab_p);
	value = ft_atoi_base((*oct)[i], 2);
	if (nb_octet == 2 && (value == 192 || value == 193))
		tab_p->ret += 1;
	else
		tab_p->ret += nb_octet;
	while (i < nb_octet)
	{
		value = ft_atoi_base((*oct)[i], 2);
		write(1, &value, 1);
		free((*oct)[i]);
		i += 1;
	}
	free(*oct);
}
