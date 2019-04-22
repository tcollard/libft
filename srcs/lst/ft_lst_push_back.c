/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:56:56 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/21 11:12:43 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_lst_push_back(t_list *alst, t_list *lst_end)
{
	t_list	*tmp;

	if (!alst || !lst_end)
		return ;
	tmp = alst;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = lst_end;
}
