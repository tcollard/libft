/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:43:12 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 17:30:55 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;

	if (!(dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	return (ft_strcpy(dup, s));
}
