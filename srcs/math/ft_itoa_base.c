/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:54:50 by tcollard          #+#    #+#             */
/*   Updated: 2018/04/18 17:15:14 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itoa_base(int nb, int base)
{
	char	*str;
	int		i;
	long	nb_save;
	char	*str_base;
	long	tmp;

	i = 1;
	if (base < 2 || base > 16)
		return (NULL);
	str_base = "0123456789ABCDEFG";
	if (base == 10)
		return (ft_itoa(nb));
	nb_save = nb;
	(nb < 0) ? nb_save = -1 * nb_save : nb_save;
	tmp = nb_save;
	while ((tmp = tmp / base) != 0)
		i += 1;
	if (!(str = ft_memalloc((size_t)(i))))
		return (NULL);
	while (--i >= 0)
	{
		str[i] = str_base[nb_save % base];
		nb_save = nb_save / base;
	}
	return (str);
}
