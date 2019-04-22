/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:39:56 by jocohen           #+#    #+#             */
/*   Updated: 2018/03/09 16:12:06 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_putwstr(wchar_t const *s)
{
	if (!s)
		return (0);
	if (!(unicode_display(s)))
		return (0);
	return (1);
}