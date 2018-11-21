/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:46:25 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/20 19:36:16 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_give(int fd, char **save, char *line, char *t)
{
	if (ft_strchr(save[fd], '\n'))
		line = ft_strsub(save[fd], 0, ft_strchr(save[fd], '\n') - save[fd]);
	else
		line = ft_strdup(save[fd]);
	if (ft_strchr(save[fd], '\n'))
	{
		t = save[fd];
		save[fd] = ft_strsub(t, ft_strchr(t, '\n') - t + 1, ft_strlen(t));
		free(t);
	}
	else
		ft_strdel(&save[fd]);
	return (line);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*t;
	static char	*save[4096];

	if (fd < 0 || !line || (!save[fd] && !(save[fd] = ft_strnew(1))))
		return (-1);
	while (!ft_strchr(save[fd], '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		t = save[fd];
		save[fd] = ft_strjoin(t, buf);
		free(t);
	}
	if (ret == -1)
		return (-1);
	*line = ft_give(fd, save, *line, t);
	return ((!save[fd] && ft_strlen(*line) == 0) ? 0 : 1);
}
