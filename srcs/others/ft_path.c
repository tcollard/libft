/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <jocohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 14:51:54 by jocohen           #+#    #+#             */
/*   Updated: 2018/10/18 16:53:01 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_path(const char *path, char *file_name)
{
	size_t	x;
	char	*str;
	size_t	y;

	x = 0;
	y = 0;
	(path) ? x += 1 : 1;
	if (!(str = ft_memalloc(ft_strlen(path) + ft_strlen(file_name) + x + 1)))
		return (0);
	x = 0;
	if (path)
	{
		while (path[x])
		{
			str[x] = path[x];
			x += 1;
		}
		str[x++] = '/';
	}
	while (file_name[y])
		str[x++] = file_name[y++];
	return (str);
}
