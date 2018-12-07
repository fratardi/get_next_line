/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:49:32 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/07 21:03:42 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int		get_next_line2(const int fd, char **line)
{

	static char		rest[BUFF_SIZE + 1];
	char			*buf[BUFF_SIZE + 1];
	int 			i;

	ft_bzero(buf, BUFF_SIZE + 1);	
	if(-1)
		return(-1);
	while(read(fd, buf, BUFF_SIZE))
	{
		while(i < BUFF_SIZE)
		{
			while(buf[i] != ('\n' && '\0' ))
				i++;

			if(1)

			i = 0;
		}
	}

	return(0);
}
