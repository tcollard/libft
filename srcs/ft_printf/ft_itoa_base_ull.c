/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 18:08:01 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/12 17:25:19 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_itoa_base_ull(unsigned long long nb, int base)
{
	char				*str;
	int					i;
	unsigned long long	nb_save;
	char				*str_base;
	unsigned long long	tmp;

	i = 1;
	if (base < 2 || base > 16)
		return (NULL);
	str_base = "0123456789ABCDEF";
	nb_save = nb;
	tmp = nb_save;
	while ((tmp = tmp / base) != 0)
		i += 1;
	if (!(str = ft_memalloc((size_t)(i + 1))))
		return (NULL);
	while (--i >= 0)
	{
		str[i] = str_base[nb_save % base];
		nb_save = nb_save / base;
	}
	return (str);
}
