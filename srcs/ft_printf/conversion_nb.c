/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:50:45 by tcollard          #+#    #+#             */
/*   Updated: 2018/03/19 17:21:27 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	conv_hh(va_list *ap, char **var, char c)
{
	int				i;

	i = 0;
	if (c == 'd' || c == 'i')
		*var = ft_itoa((signed char)va_arg(*ap, int));
	else if (c == 'o' || c == 'O')
		*var = ft_itoa_base_ull((unsigned char)va_arg(*ap, int), 8);
	else if (c == 'u')
		*var = ft_itoa_base_ull((unsigned char)va_arg(*ap, int), 10);
	else if (c == 'x' || c == 'X')
	{
		*var = ft_itoa_base_ull((unsigned char)va_arg(*ap, int), 16);
		if (c == 'x')
			while ((*var)[i] != '\0')
			{
				(*var)[i] = ft_tolower((*var)[i]);
				i += 1;
			}
	}
	else
		*var = ft_itoa((unsigned char)va_arg(*ap, int));
	return (0);
}

int	conv_h(va_list *ap, char **var, char c)
{
	int				i;

	i = 0;
	if (c == 'd' || c == 'i')
		*var = ft_itoa((short)va_arg(*ap, int));
	else if (c == 'o' || c == 'O')
		*var = ft_itoa_base_ull((unsigned short)va_arg(*ap, int), 8);
	else if (c == 'u')
		conv_ul(ap, var);
	else if (c == 'x' || c == 'X')
	{
		*var = ft_itoa_base_ull((unsigned short)va_arg(*ap, int), 16);
		if (c == 'x')
			while ((*var)[i] != '\0')
			{
				(*var)[i] = ft_tolower((*var)[i]);
				i += 1;
			}
	}
	else
		*var = ft_itoa((unsigned char)va_arg(*ap, int));
	return (0);
}

int	conv_j(va_list *ap, char **var, char c)
{
	int			i;

	i = 0;
	if (c == 'd' || c == 'i')
		*var = ft_itoa_ll((intmax_t)va_arg(*ap, intmax_t));
	else if (c == 'o' || c == 'O')
		*var = ft_itoa_base_ull((uintmax_t)va_arg(*ap, uintmax_t), 8);
	else if (c == 'u')
		conv_ul(ap, var);
	else if (c == 'X' || c == 'x')
	{
		*var = ft_itoa_base_ull((uintmax_t)va_arg(*ap, uintmax_t), 16);
		if (c == 'x')
			while ((*var)[i] != '\0')
			{
				(*var)[i] = ft_tolower((*var)[i]);
				i += 1;
			}
	}
	else
		*var = ft_itoa((uintmax_t)va_arg(*ap, uintmax_t));
	return (0);
}

int	conv_z(va_list *ap, char **var, char c)
{
	int					i;

	i = 0;
	if (c == 'd' || c == 'i')
		*var = ft_itoa_ll((long long)va_arg(*ap, long long));
	else if (c == 'o' || c == 'O')
		*var = ft_itoa_base_ull((unsigned long long)va_arg(*ap,
					unsigned long long), 8);
	else if (c == 'u')
		*var = ft_itoa_base_ull((unsigned long long)va_arg(*ap,
					unsigned long long), 10);
	else if (c == 'X' || c == 'x')
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
		*var = ft_itoa_ll((unsigned long long)va_arg(*ap, unsigned long long));
	return (0);
}
