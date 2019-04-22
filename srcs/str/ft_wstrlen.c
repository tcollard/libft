/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:39:34 by jocohen           #+#    #+#             */
/*   Updated: 2018/03/08 14:39:59 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	conditions(unsigned int x, size_t n_bits)
{
	size_t	out;

	if (x <= 127 || (x <= 255 && MB_CUR_MAX == 1))
		out = 1;
	else if (n_bits > 7 && n_bits <= 11)
		out = 2;
	else if (n_bits > 11 && n_bits <= 16)
		out = 3;
	else
		out = 4;
	return (out);
}

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t			x;
	size_t			n_bits;
	size_t			out;
	unsigned int	n;

	if (!s)
		return (0);
	out = 0;
	x = 0;
	while (s[x])
	{
		n_bits = 1;
		n = (unsigned int)s[x];
		while (n /= 2)
			n_bits += 1;
		out += conditions((unsigned int)s[x], n_bits);
		x += 1;
	}
	return (out);
}
