/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 14:28:01 by jocohen           #+#    #+#             */
/*   Updated: 2018/01/14 17:21:07 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstfind(t_list *alst, void *data, int (*cmp)())
{
	while (alst)
	{
		if (!(cmp(alst->content, data)))
			return (alst);
		alst = alst->next;
	}
	return (0);
}
