/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:44:49 by tcollard          #+#    #+#             */
/*   Updated: 2018/04/18 14:31:44 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len_dst;

	len_dst = ft_strlen(dst);
	if (size > len_dst)
	{
		ft_strncpy(&dst[len_dst], src, (size - len_dst - 1));
		if (dst[size - 1])
			dst[size - 1] = '\0';
	}
	else if (size <= len_dst)
		return (ft_strlen(src) + size);
	return (len_dst + ft_strlen(src));
}
