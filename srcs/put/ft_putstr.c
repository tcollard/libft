/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 10:37:07 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 11:34:26 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	if (!s[0])
		write(1, s, 1);
	else
		write(1, s, ft_strlen(s));
}
