/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:41:58 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 11:15:25 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	while ((*alst)->next != NULL)
	{
		tmp = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
		(*alst) = tmp;
	}
	del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}
