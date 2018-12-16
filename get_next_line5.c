/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 21:31:35 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/16 21:58:35 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *ft_strjoinfree(char *to_free, char *to_join)
{
	char *rez;

	if(!to_free && !to_join)
			return(NULL);
	if(!to_free && to_join)
		return(ft_strdup(to_join));
	if(to_free && !to_join)
		return(to_free);
	if(!(rez = ft_memalloc(sizeof(char)*(ft_strlen(to_free)+ft_strlen(to_join)+1))))
			return(NULL);
	rez = ft_strcpy(rez, to_free);
	rez = ft_strcat(rez, to_join);
	free(to_free);
	return(rez);
}

char *buffrest(char *rest)
{
	char *
}



int		get_next_line(const int fd, char **line)
{
	static char *linefd = NULL;
	char buf[BUFF_SIZE + 1]
	int n;


	if(fd <= 0 || !fd)
		return(-1);
	ft_bzero(buf, BUFF_SIZE + 1);
	while((n = read(fd, &buf, BUFF_SIZE)))
	{
		


	}

}
