/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 12:05:30 by tcollard          #+#    #+#             */
/*   Updated: 2018/04/18 14:35:25 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i + 1])
		i++;
	j = i;
	while (s[j])
		j++;
	len = j - 1;
	while ((s[len] == ' ' || s[len] == '\n' || s[len] == '\t') && len)
		len--;
	if (!((!len) ? (str = ft_strnew(0)) :
				(str = ft_strnew((len - i) + 1))))
		if (!str)
			return (NULL);
	j = 0;
	while (i < len + 1 && len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
