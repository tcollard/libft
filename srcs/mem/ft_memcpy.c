/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 17:54:39 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 11:24:47 by tcollard         ###   ########.fr       */
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
		i += 1;
	}
	return (dst_char);
}
