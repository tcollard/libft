/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 14:51:11 by jocohen           #+#    #+#             */
/*   Updated: 2018/10/18 16:42:42 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		**set_masks(int ot)
{
	char	**masks;
	int		x;

	x = 1;
	if (!(masks = (char **)malloc(sizeof(char *) * (ot + 1))))
		return (0);
	if (ot == 2)
		if (!((*masks) = ft_strdup("110xxxxx")))
			return (0);
	if (ot == 3)
		if (!((*masks) = ft_strdup("1110xxxx")))
			return (0);
	if (ot == 4)
		if (!((*masks) = ft_strdup("11110xxx")))
			return (0);
	while (x <= ot)
	{
		if (!(*(masks + x) = ft_strdup("10xxxxxx")))
			return (0);
		x += 1;
	}
	masks[ot] = 0;
	return (masks);
}

void			ft2(int n_bits, int octet, char **masks, char *bin_char)
{
	int		y;
	int		n;

	n = octet - 1;
	while (n >= 0)
	{
		y = 7;
		while (y >= 0)
		{
			if (masks[n][y] == 'x' && n_bits >= 0)
				masks[n][y--] = bin_char[n_bits--];
			else if (masks[n][y] == 'x')
				masks[n][y--] = '0';
			else
				y -= 1;
		}
		n -= 1;
	}
	n = 0;
	while (n < octet)
	{
		y = ft_atoi_base(masks[n], 2);
		write(1, &y, 1);
		n += 1;
	}
}

int				ft1(int n_bits, char *bin_char, unsigned int wchar)
{
	int		octet;
	char	**masks;

	if (wchar <= 127 || (wchar <= 255 && MB_CUR_MAX == 1))
		write(1, &wchar, 1);
	else if (n_bits > 7 && n_bits <= 11)
		octet = 2;
	else if (n_bits > 11 && n_bits <= 16)
		octet = 3;
	else
		octet = 4;
	if (wchar > 255 || (wchar > 127 && MB_CUR_MAX > 1))
	{
		if (!(masks = set_masks(octet)))
			return (0);
		ft2(n_bits - 1, octet, masks, bin_char);
		ft_memdel0(&bin_char);
		ft_memdel2(&masks);
	}
	return (1);
}

int				unicode_display(const wchar_t *input)
{
	size_t			x;
	int				n_bits;
	unsigned int	wchar;
	char			*bin_char;

	x = 0;
	while (input[x])
	{
		n_bits = 0;
		wchar = (unsigned int)input[x];
		if (wchar > 255 || (wchar > 127 && MB_CUR_MAX > 1))
		{
			if (!(bin_char = ft_itoa_base((unsigned int)input[x], 2)))
				return (0);
			n_bits = ft_strlen(bin_char);
		}
		if (!(ft1(n_bits, bin_char, wchar)))
			return (0);
		x += 1;
	}
	if (!input[0])
		write(1, &x, 1);
	return (1);
}
