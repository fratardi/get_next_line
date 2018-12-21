/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:21:51 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/21 07:18:59 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	size_t		n;

	i = 0;
	line = 0;
	if (!(ft_checkargs(argc)))
		return (0);
	fd = open(argv[1], O_RDONLY);
	while ((n = get_next_line(fd, &line) > 0))
	{
		ft_putnbr(++i);
//		ft_putchar(' ');
	//	ft_putnot r((int)n);
//		ft_putstr("ret : ");
//		ft_putnbr(n);
//		ft_putstr("\n");
		ft_putendl(line);
		free(line);
		line = NULL;
	}
/*	ft_putstr(" 2 ret : ");
	ft_putnbr(n);
	ft_putendl("\n");
	ft_putendl(line);
*/
	close(fd);
	return (0);
}
