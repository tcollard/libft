/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 09:05:21 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/15 10:56:23 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	ft_verif(unsigned long long *len, long long n,
		unsigned long long *nb, int *neg)
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

char		*ft_itoa_ll(long long n)
{
	char				*str;
	unsigned long long	len;
	unsigned long long	nb;
	int					i;
	int					neg;

	i = 0;
	ft_verif(&len, n, &nb, &neg);
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
