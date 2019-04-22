/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twod_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 17:07:51 by jocohen           #+#    #+#             */
/*   Updated: 2018/04/18 17:07:54 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	**ft_twod_dup(const char **t)
{
	char	**output;
	size_t	x;
	size_t	y;

	if (!t)
		return (0);
	y = 0;
	x = 0;
	while (t[x])
		x += 1;
	if (!(output = (char **)malloc(sizeof(char *) * (x + 1))))
		return (0);
	while (y != x)
		output[y++] = 0;
	y = 0;
	while (t[y])
	{
		if (!(*(output + y) = ft_strdup(t[y])))
			return (0);
		y += 1;
	}
	return (output);
}
