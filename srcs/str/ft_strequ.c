/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:33:20 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 09:51:30 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	i = ft_strcmp(s1, s2);
	if (!i)
		return (1);
	return (0);
}
