/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 15:45:49 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/16 11:18:14 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	nb;
	int	x;

	nb = 0;
	neg = 1;
	x = 0;
	while (*nptr && *nptr != '\0' && (*nptr == ' ' || *nptr == '\n'
	|| *nptr == '\t' || *nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (*(nptr - 1) == '-')
			neg = -1;
		nb = nb * 10 + *nptr - 48;
		nptr++;
		if (x > 11 && neg == -1 && *(nptr - x) != '0')
			return (0);
		if (x > 11 && neg > 0 && *(nptr - x) != '0')
			return (-1);
		x++;
	}
	return (nb * neg);
}
