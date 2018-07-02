/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:36:41 by tcollard          #+#    #+#             */
/*   Updated: 2018/04/18 14:27:37 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr(int n)
{
	char			nb;
	unsigned int	nbl;

	nbl = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		nbl = -n;
	}
	else if (n >= 0)
		nbl = n;
	if (nbl / 10 != 0)
	{
		ft_putnbr(nbl / 10);
		nb = nbl % 10 + 48;
		write(1, &nb, 1);
	}
	else
	{
		nb = nbl + 48;
		write(1, &nb, 1);
	}
}
