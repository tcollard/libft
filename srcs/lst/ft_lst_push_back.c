/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:56:56 by tcollard          #+#    #+#             */
/*   Updated: 2018/04/18 14:23:06 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lst_push_back(t_list *alst, t_list *lst_end)
{
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = alst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = lst_end;
}
