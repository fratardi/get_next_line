/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:50:14 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/12 06:46:10 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


int		main(int argc, char **argv)
{
	int fd;
	char *line[9000];
//	char **tab;
//	char *buf;
//	char *rez;
int i;
int ret;

ret = 0;

i = 0;
	if(!(ft_checkargs(argc)))
		return(0);
	fd = open(argv[1], O_RDONLY);
while( 0 < get_next_line(fd, line))
	;				
		ft_print_table(line);
		
	return(0);
}
