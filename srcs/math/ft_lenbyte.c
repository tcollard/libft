/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenbyte.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:28:03 by jocohen           #+#    #+#             */
/*   Updated: 2018/03/08 14:32:26 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_lenbyte(unsigned int c)
{
	size_t			x;
	unsigned int	y;

	y = c;
	x = 1;
	while (y /= 2)
		x += 1;
	if (c <= 127 || (c <= 255 && MB_CUR_MAX == 1))
		return (1);
	else if (x > 7 && x <= 11)
		return (2);
	else if (x > 11 && x <= 16)
		return (3);
	else
		return (4);
}
