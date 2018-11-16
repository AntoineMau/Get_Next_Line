/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:57:18 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/15 15:34:21 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	**line;

	(void)line;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return	(-1);
	printf("return: %d", get_next_line(fd, line));
	if (close(fd) == -1)
		return (-1);
	return (0);
}
