/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:14:26 by tcollard          #+#    #+#             */
/*   Updated: 2018/04/18 14:27:51 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			nb;
	unsigned int	nbl;

	nbl = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbl = -n;
	}
	else if (n >= 0)
		nbl = n;
	if (nbl / 10 != 0)
	{
		ft_putnbr_fd(nbl / 10, fd);
		nb = nbl % 10 + 48;
		ft_putchar_fd(nb, fd);
	}
	else
	{
		nb = nbl + 48;
		ft_putchar_fd(nb, fd);
	}
}
