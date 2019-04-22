/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:09:31 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 11:21:57 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char	*str;

	if (!(str = (void *)malloc(size)))
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
