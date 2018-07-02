/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:54:39 by tcollard          #+#    #+#             */
/*   Updated: 2018/04/18 14:25:53 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst_char;
	unsigned char	*src_char;

	i = 0;
	dst_char = (unsigned char *)dst;
	src_char = (unsigned char *)src;
	while (i < n)
	{
		dst_char[i] = src_char[i];
		i++;
	}
	return (dst_char);
}
