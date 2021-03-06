/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:27:43 by tcollard          #+#    #+#             */
/*   Updated: 2017/11/07 13:14:31 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;
	int	sqrt;

	i = 1;
	sqrt = 0;
	if (nb < 1)
		return (0);
	while (i * i <= nb)
	{
		if (i * i == nb)
			sqrt = i;
		i++;
	}
	return (sqrt);
}
