/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:50:11 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 10:51:36 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strrev(char const *s)
{
	int		i;
	int		j;
	char	*s_rev;

	i = ft_strlen(s) - 1;
	j = 0;
	if (!(s_rev = ft_memalloc(i + 2)))
		return (NULL);
	while (i >= 0)
	{
		s_rev[j] = s[i];
		i -= 1;
		j += 1;
	}
	return (s_rev);
}
