/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:31:14 by tcollard          #+#    #+#             */
/*   Updated: 2018/04/18 14:22:50 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*lst_new;

	if (!lst)
		return (NULL);
	lst_new = (*f)(lst);
	lst = lst->next;
	while (lst->next)
	{
		tmp = (*f)(lst);
		ft_lst_push_back(lst_new, tmp);
		lst = lst->next;
	}
	tmp = (*f)(lst);
	ft_lst_push_back(lst_new, tmp);
	lst = lst->next;
	return (lst_new);
}
