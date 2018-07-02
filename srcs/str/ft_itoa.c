/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:46:14 by tcollard          #+#    #+#             */
/*   Updated: 2018/04/18 14:29:39 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void		ft_chck(unsigned int *len, int n, unsigned int *nb, int *neg)
{
	if (n < 0)
	{
		*len = 2;
		*neg = -1;
	}
	else
	{
		*len = 1;
		*neg = 1;
	}
	*nb = n * *neg;
	while (n / 10 != 0)
	{
		n = n / 10;
		(*len)++;
	}
}

char			*ft_itoa(int n)
{
	char			*str;
	unsigned int	len;
	unsigned int	nb;
	int				i;
	int				neg;

	i = 0;
	ft_chck(&len, n, &nb, &neg);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	neg = 0;
	if (n < 0)
	{
		str[i] = '-';
		neg = 1;
	}
	i = len - 1;
	while (i >= neg)
	{
		str[i] = nb % 10 + 48;
		nb = nb / 10;
		i--;
	}
	str[len] = '\0';
	return (str);
}
