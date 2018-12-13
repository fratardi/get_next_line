/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:50:14 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/13 22:38:49 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


int		main(int argc, char **argv)
{
	int fd;
	char *line[9000];
int i;
int n;

n = 0;

i = 0;
	if(!(ft_checkargs(argc)))
		return(0);
	fd = open(argv[1], O_RDONLY);
while( (n = get_next_line(fd, line) > 0))
		{
		ft_putnbr(n);
		ft_putchar(' ');
		ft_putnbr(++i);
		ft_putchar(' ');
//		ft_putchar('\n');
//		ft_putendl("get next line ok");
//		ft_putnbr(fd);i
	//	ft_putchar('\n');
		ft_putendl(*line);
		}
ft_putnbr(n);
	return(0);
}
