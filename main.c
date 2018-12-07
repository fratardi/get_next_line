/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <fratardi>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:50:14 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/07 21:06:14 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"


int		main(int argc, char **argv)
{
	int fd;
	int i;
	char buf[BUFF_SIZE + 1];
	char *rez;
	char *line;
	char **tab;
	int ret;

	i = 0;
	rez = "";
	if(!(ft_checkargs(argc)))
		return(0);
	fd = open(argv[1], O_RDONLY);


	get_next_line(fd, &line);
	ft_putendl(line);
//fonction de lecture et d'affichage du buffer fd en boucle	
/*	while((ret = read(fd, &buf, BUFF_SIZE)))
	{
		buf[ret] = 0;
		rez = ft_strjoin(rez, buf);
	}
	while((get_next_line(fd, &line[i])) != (0 & -1))
		i++;
	tab = ft_strsplit(rez, '\n' & '\t');
	ft_print_table(tab);
*/
//	ft_print_table(line);
//	ft_putnbr(i);
//	close(fd);
	return(0);
}
