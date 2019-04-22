/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldbl_funcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <jocohen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:36:34 by jocohen           #+#    #+#             */
/*   Updated: 2018/12/13 14:36:36 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_l_dbl		*ft_ldblnew(void const *content, size_t content_size)
{
	t_l_dbl		*lst;

	if (!(lst = (t_l_dbl *)malloc(sizeof(t_l_dbl))))
		return (0);
	if (content)
	{
		if (!(lst->content = (void *)malloc(content_size)))
			return (0);
		ft_memcpy(lst->content, content, content_size);
		lst->content_size = content_size;
	}
	else
	{
		lst->content = 0;
		lst->content_size = 0;
	}
	lst->next = 0;
	lst->prev = 0;
	return (lst);
}

int			ft_ldbldel(t_l_dbl **fp)
{
	t_l_dbl	*tmp;

	while ((*fp))
	{
		tmp = (*fp)->next;
		ft_memdel((void **)&((*fp)->content));
		(*fp)->content_size = 0;
		ft_memdel((void **)fp);
		(*fp) = tmp;
	}
	return (0);
}
