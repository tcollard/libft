/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factoial.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:22:11 by tcollard          #+#    #+#             */
/*   Updated: 2017/11/07 11:50:20 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int fact;

	fact = nb;
	if (nb < 0 || nb > 12)
		fact = 0;
	else if (nb == 0)
		fact = 1;
	else
		fact = fact * ft_recursive_factorial(nb - 1);
	return (fact);
}
