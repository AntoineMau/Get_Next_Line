/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:57:18 by anmauffr          #+#    #+#             */
/*   Updated: 2018/11/19 08:50:38 by anmauffr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

#include <stdio.h>

int		main(int ac, char **av)
{
	int		i;
	int		fd;
	char	*line;

	(void)ac;
	line = (char*)malloc(sizeof(*line) * (10));
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (-1);
	i = 0;
	while (i < atoi(av[2]))
	{
		get_next_line(fd, &line);
		printf("%s\n", line);
		i++;
	}
	free(line);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
