/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_nb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:19:27 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/19 17:20:48 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	conv_ul(va_list *ap, char **var)
{
	unsigned long long	nb;
	unsigned long long	tmp;
	int					i;

	i = 1;
	nb = (unsigned long long)va_arg(*ap, unsigned long long);
	tmp = nb;
	while (tmp / 10 != 0)
	{
		tmp = tmp / 10;
		i += 1;
	}
	if (!(*var = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	(*var)[i] = '\0';
	i -= 1;
	while (i >= 0)
	{
		(*var)[i] = nb % 10 + 48;
		nb = nb / 10;
		i -= 1;
	}
	return (0);
}

int	conv_int(va_list *ap, char **var, char c)
{
	int	nb;
	int	x;

	x = 0;
	nb = (long long)va_arg(*ap, long long);
	(c == 'd' || c == 'D' || c == 'i') ? *var = ft_itoa((int)nb) : 0;
	if (nb < 0)
	{
		(c == 'O' || c == 'o') ? *var = ft_itoa_base_neg(nb, 8) : 0;
		(c == 'U' || c == 'u') ? *var = ft_itoa_base_neg(nb, 10) : 0;
		(c == 'X' || c == 'x') ? *var = ft_itoa_base_neg(nb, 16) : 0;
	}
	else
	{
		(c == 'O' || c == 'o') ? *var = ft_itoa_base_ull(nb, 8) : 0;
		(c == 'U' || c == 'u') ? *var = ft_itoa_base(nb, 10) : 0;
		(c == 'X' || c == 'x') ? *var = ft_itoa_base(nb, 16) : 0;
	}
	if (c == 'x')
		while ((*var)[x])
		{
			(*var)[x] = ft_tolower((int)((*var)[x]));
			x += 1;
		}
	return (0);
}

int	conv_ll(va_list *ap, char **var, char c)
{
	int					i;

	i = 0;
	if (c == 'd' || c == 'D' || c == 'i')
		*var = ft_itoa_ll((long long)va_arg(*ap, long long));
	else if (c == 'o' || c == 'O')
		*var = ft_itoa_base_ull((unsigned long long)va_arg(*ap,
					unsigned long long), 8);
	else if (c == 'u')
		conv_ul(ap, var);
	else if (c == 'x' || c == 'X')
	{
		*var = ft_itoa_base_ull((unsigned long long)va_arg(*ap,
					unsigned long long), 16);
		if (c == 'x')
			while ((*var)[i] != '\0')
			{
				(*var)[i] = ft_tolower((*var)[i]);
				i += 1;
			}
	}
	else
		conv_int(ap, var, c);
	return (0);
}

int	conv_l(va_list *ap, char **var, char c)
{
	int				i;

	i = 0;
	if (c == 'd' || c == 'i')
		*var = ft_itoa_ll((long)va_arg(*ap, long));
	else if (c == 'o' || c == 'O')
		*var = ft_itoa_base_ull((unsigned long)va_arg(*ap, unsigned long), 8);
	else if (c == 'u')
		*var = ft_itoa_base_ull((unsigned long)va_arg(*ap, unsigned long), 10);
	else if (c == 'x' || c == 'X' || c == 'p')
	{
		*var = ft_itoa_base_ull((unsigned long)va_arg(*ap, unsigned long), 16);
		if (c == 'x' || c == 'p')
			while ((*var)[i] != '\0')
			{
				(*var)[i] = ft_tolower((*var)[i]);
				i += 1;
			}
	}
	return (0);
}
