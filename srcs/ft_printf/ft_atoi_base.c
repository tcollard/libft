/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 14:31:21 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/12 17:24:52 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_power(int nb, int pow)
{
	int	i;
	int ret;

	i = 1;
	ret = nb;
	if (pow == 0)
		return (1);
	while (i < pow)
	{
		ret *= nb;
		i += 1;
	}
	return (ret);
}

int			ft_atoi_base(char *str, int base)
{
	int		nb;
	int		pow;

	nb = 0;
	pow = (int)ft_strlen(str) - 1;
	while (*str)
	{
		nb += (*str - 48) * ft_power(base, pow);
		str++;
		pow -= 1;
	}
	return (nb);
}
