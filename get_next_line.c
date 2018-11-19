/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:24:59 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/19 08:40:16 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_suite(int fd, char *str, char **line)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];

	if (*str)
		ft_strcpy(*line, str);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	return (str);
}

int		get_next_line(int const fd, char **line)
{
	int			i;
	static char	*str;

	if ((i = 0) || fd == -1 || line == 0)
		return (-1);
	if (!str)
		if (!(str = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))))
			return (-1);
	str = ft_suite(fd, str, line);
	if (str[i])
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (i == 0)
			*line = ft_strdup("");
		else
		{
			*line = ft_strsub(str, 0, i);
			str = &str[i + 1];
		}
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}
