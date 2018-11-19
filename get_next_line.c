/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:24:59 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/19 10:43:45 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_new_line(char **s, char **line, int fd, int ret)
{
	int		len;

	len = 0;
	while (s[fd][len] && s[fd][len] != '\n')
		len++;
	if (s[fd][len] == '\n')
	{
		line = ft_strsub(s[fd], 0, len);
		s[fd] = ft_strdup(s[fd] + len + 1);
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (!s[fd][len])
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[255];
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (fd < 0 || !line)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		s[fd] = ft_strjoin(s[fd], buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!s[fd] || !s[fd][0]))
		return (0);
	return (ft_new_line(s, line, fd, ret));
}
