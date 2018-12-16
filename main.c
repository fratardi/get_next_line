/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:21:51 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/16 22:22:53 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		n;

	n = 0;
	i = 0;
	line = 0;
	if (!(ft_checkargs(argc)))
		return (0);
	fd = open(argv[1], O_RDONLY);
	while ((n = get_next_line(fd, &line) > 0))
	{
		ft_putnbr(++i);
		ft_putendl(line);
		free(line);
	}
	close(fd);
	return (0);
}
