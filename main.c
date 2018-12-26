/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:21:51 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/26 11:21:49 by fratardi         ###   ########.fr       */
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
		//fd = 0;
		fd = open(argv[1], O_RDONLY);
	while ((n = get_next_line(fd, &line) > 0))
	{
		ft_putnbr(n);
		ft_putstr("  ");
		ft_putendl_fd(line, 1);
		free(line);
		line = NULL;
	}
	close(fd);
	return (0);
	(void)argc;
	(void)argv;
}
