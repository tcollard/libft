/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwhlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:33:08 by jocohen           #+#    #+#             */
/*   Updated: 2018/01/14 17:45:21 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strwhlen(const char *s, size_t start, size_t end)
{
	size_t	x;

	x = 0;
	if (end == 0)
		while (s[start])
		{
			start += 1;
			x += 1;
		}
	else
		while (s[start] && start < end)
		{
			start += 1;
			x += 1;
		}
	return (x);
}
