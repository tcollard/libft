/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 14:52:45 by jocohen           #+#    #+#             */
/*   Updated: 2018/04/26 18:48:44 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include <fcntl.h>

# define BUFF_SIZE 50

typedef struct	s_gnl
{
	char		buf[BUFF_SIZE + 1];
	ssize_t		rd;
	long		lwrit;
}				t_gnl;

typedef struct	s_add
{
	long		x;
	long		y;
	long		z;
	char		*str;
}				t_add;

int				get_next_line(const int fd, char **line);

#endif
