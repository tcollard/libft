/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:27:59 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 09:58:27 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (!(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i += 1;
	}
	str[i] = '\0';
	return (str);
}
