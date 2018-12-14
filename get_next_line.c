/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:14:27 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/14 04:38:28 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *liner(char *linetoclear)
{
	size_t i;
	char *ret;

	ret = NULL;
	i = 0;
	while (linetoclear[i] != '\0' && linetoclear[i] != '\n')
		i++;
	if(!(ret = ft_strndup(linetoclear, i)))
		return(NULL);
	free(linetoclear);
	return (ret);
}

char *buffrest(char *str)
{
	char *rest;
	rest = NULL;
	rest = ft_strdup(ft_strchr(str, '\n') + 1);
	rest[ft_strlen(rest)] = '\0';
	return(rest);
}

int		get_next_line(const int fd, char **line)
{
	static char *rst = NULL;
	char buf[BUFF_SIZE + 1];
	int n;

	if (!rst)
		rst = ft_strdup("");
	ft_bzero(buf, BUFF_SIZE + 1);
	while( (n = read(fd, &buf, BUFF_SIZE)))
	{	
		rst = ft_strjoin(rst, buf);
		if(ft_strchr(buf, '\n'))
		{
			*line = liner(rst);
				rst = buffrest(buf);
			return(1);
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	*line = rst;
	return(0);
}
