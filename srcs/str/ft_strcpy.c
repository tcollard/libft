/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:40:56 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 09:49:06 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	if (!src)
		return (dest);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i += 1;
	}
	dest[i] = '\0';
	return (dest);
}
