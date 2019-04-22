/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:13:39 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 11:03:38 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i += 1;
	}
	str[i] = '\0';
	return (str);
}
