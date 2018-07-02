/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwhcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:46:27 by jocohen           #+#    #+#             */
/*   Updated: 2018/04/26 18:50:41 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strwhcpy(char *dst, char const *src, unsigned int start,
		unsigned int end)
{
	unsigned int	x;

	x = 0;
	while (src[start] && start < end + 1)
	{
		dst[x] = src[start];
		x += 1;
		start += 1;
	}
	dst[x] = 0;
	return (dst);
}
