/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:53:10 by jocohen           #+#    #+#             */
/*   Updated: 2018/01/14 17:21:44 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	n;

	n = 0;
	while (lst->next)
	{
		n += 1;
		lst = lst->next;
	}
	return (n + 1);
}
