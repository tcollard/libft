/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_neg.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:21:10 by tcollard          #+#    #+#             */
/*   Updated: 2018/02/28 17:28:40 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_init_base(int base, char **str_base, int *i)
{
	if (base == 16)
	{
		*i = 8;
		*str_base = "0123456789ABCDEF";
	}
	else if (base == 8)
	{
		*i = 11;
		*str_base = "01234567";
	}
	else if (base == 10)
	{
		*i = 10;
		*str_base = "0123456789";
	}
}

char		*ft_itoa_base_neg(int nb, int base)
{
	char	*str;
	int		i;
	long	nb_save;
	char	*str_base;

	ft_init_base(base, &str_base, &i);
	nb_save = nb + 4294967296;
	if (!(str = ft_memalloc((size_t)(i))))
		return (NULL);
	while (--i >= 0)
	{
		str[i] = str_base[nb_save % base];
		nb_save = nb_save / base;
	}
	return (str);
}
