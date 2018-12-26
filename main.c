/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:21:51 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/26 09:35:48 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int			fd;
	char		*line;
	int			i;
	size_t		n;

	i = 0;
	line = 0;
	if (!(ft_checkargs(argc)))
		return (0);
	fd = OPEN_MAX + 1;
	while ((n = get_next_line(fd, &line) > 0))
	{
		ft_putnbr(++i);
		ft_putstr("  ");
		ft_putendl(line);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
	(void)argc;
	(void)argv;
}
