/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:38:07 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/16 12:43:58 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*occurence;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
	{
		occurence = ((char *)s + i);
		return (occurence);
	}
	return (NULL);
}
