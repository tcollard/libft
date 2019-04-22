/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:46:17 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 16:30:35 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		str[i] = '\0';
		i += 1;
	}
	str[i] = '\0';
	return (str);
}
