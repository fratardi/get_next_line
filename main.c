/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:50:14 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/15 21:29:23 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;
	int		n;

	n = 0;
	i = 0;
	line = 0;
	if(!(ft_checkargs(argc)))
		return(0);
	fd = open(argv[1], O_RDONLY);
	while((n = get_next_line(fd, &line) > 0))
	{
//		printf("%p\n", line);
//		printf("[%-4d] %d %-2s\n", ++i, n, line);
//		ft_putchar(' ');
//		ft_putchar(' ');
		//ft_putchar('\n');
		//ft_putendl("get next line ok");
		ft_putnbr(++i);
		//	ft_putchar('\n');
	ft_putendl(line);
		free(line);
	}
	//ft_putnbr(n);
	close(fd);
	return(0);
}
