/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:24:59 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/16 16:24:59 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int		i;
	int		find_n;
	int		ret;
	char	buf[BUFF_SIZE + 1];

	if (fd == -1)
		return (-1);
	find_n = 0;
	while (find_n != 1)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		i = -1;
		if (buf[++i] == '\n' && find_n != 1)
			find_n = 1;
		ft_putstr_fd(buf, STDOUT);
	}
	return (1);
}
