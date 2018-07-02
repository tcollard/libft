/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:05:00 by tcollard          #+#    #+#             */
/*   Updated: 2018/04/18 14:23:31 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lst_rev(t_list **alst)
{
	t_list	*tmp;
	t_list	*tmp_prev;
	t_list	*tmp_next;

	if (!(*alst) || (*alst)->next == NULL)
		return ;
	tmp_prev = *alst;
	tmp = tmp_prev->next;
	tmp_next = tmp->next;
	(*alst)->next = NULL;
	while (tmp_next != NULL)
	{
		tmp->next = tmp_prev;
		tmp_prev = tmp;
		tmp = tmp_next;
		tmp_next = tmp->next;
	}
	tmp->next = tmp_prev;
	*alst = tmp;
}
