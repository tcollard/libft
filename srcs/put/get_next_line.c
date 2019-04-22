/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:53:28 by tcollard          #+#    #+#             */
/*   Updated: 2019/02/15 11:00:08 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

int		remake_line(char **line, t_add *tsf, t_gnl *file)
{
	tsf->x = file->lwrit;
	if (file->lwrit)
	{
		tsf->str = ft_memalloc(file->lwrit + 1);
		ft_memcpy(tsf->str, (*line), file->lwrit);
		ft_memdel((void **)line);
		if (!(tsf->str))
			return (-1);
		if (!((*line) = ft_memalloc(tsf->y + file->lwrit + 1)))
		{
			ft_memdel((void **)&tsf->str);
			return (-1);
		}
		ft_memcpy((*line), tsf->str, file->lwrit);
		ft_memdel((void **)&tsf->str);
	}
	else if (!((*line) = ft_memalloc(tsf->y + 1)))
		return (-1);
	file->lwrit += tsf->y;
	tsf->z = 0;
	while (tsf->z < tsf->y)
		(*line)[(tsf->x)++] = file->buf[(tsf->z)++];
	return (1);
}

int		read_left(t_gnl *file, const int fd, char **line)
{
	t_add	tsf;

	tsf.x = 0;
	while (file->rd != tsf.x && file->buf[tsf.x] != '\n')
		tsf.x += 1;
	if (!((*line) = ft_memalloc(tsf.x + 1)))
		return (-1);
	ft_memmove((*line), file->buf, tsf.x);
	if (file->buf[tsf.x] == '\n')
	{
		file->rd -= (tsf.x + 1);
		ft_memmove(file->buf, file->buf + (tsf.x + 1), file->rd);
		ft_bzero(file->buf + file->rd, tsf.x + 1);
		file->lwrit = 0;
		return (1);
	}
	file->lwrit = tsf.x;
	ft_bzero(file->buf, BUFF_SIZE + 1);
	return (get_next_line(fd, line));
}

int		recall_or_return(char **line, const int fd, t_gnl *file, t_add tsf)
{
	if (file->buf[tsf.y] == '\n' || (file->rd != BUFF_SIZE &&
		file->buf[tsf.y]))
	{
		file->rd = (BUFF_SIZE - (tsf.y + 1));
		ft_memmove(file->buf, file->buf + (tsf.y + 1), file->rd);
		ft_bzero(file->buf + file->rd, tsf.y + 1);
		file->lwrit = 0;
		return (1);
	}
	ft_bzero(file->buf, BUFF_SIZE + 1);
	return (get_next_line(fd, line));
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	file[OPEN_MAX + 1];
	t_add			tsf;

	tsf.y = 0;
	if (fd < 0 || !(line) || fd > OPEN_MAX)
		return (-1);
	if (!(file[fd].buf[0]))
	{
		if ((file[fd].rd = read(fd, file[fd].buf, BUFF_SIZE)) <= 0)
		{
			if (file[fd].lwrit)
			{
				file[fd].lwrit = 0;
				return (1);
			}
			ft_bzero(file[fd].buf, BUFF_SIZE + 1);
			return (file[fd].rd);
		}
		while (tsf.y < BUFF_SIZE && file[fd].buf[tsf.y] != '\n')
			tsf.y += 1;
		if (remake_line(line, &tsf, &(file[fd])) == -1)
			return (-1);
		return (recall_or_return(line, fd, &(file[fd]), tsf));
	}
	return (read_left(&(file[fd]), fd, line));
}
