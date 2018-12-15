/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:14:27 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/15 21:29:20 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*strjointorendre(char *tofree, char *buf)
{
	char *rez;
	int i;
	int j;

	if(!(tofree || buf))
		return(NULL);
	if (tofree && !buf)
		return (ft_strdup(tofree));
	if (!tofree && buf)
		return (ft_strdup(buf));
	j = ft_strlen(buf);
	i = ft_strlen(tofree);
	if(!(rez =(char *)ft_memalloc(sizeof(char) * i + j + 1)))
		return(NULL);
	rez = ft_strcpy(rez, tofree);
	rez = ft_strcat(rez, buf);
	return(rez);
}



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
	
	rest = ft_strdup(ft_strchr(str,'\n') + 1);
//	free(str);
	return(rest);
}

int		get_next_line(const int fd, char **line)
{
	static char *rst = NULL;
	char buf[BUFF_SIZE + 1];
	int n;

	ft_bzero(buf, BUFF_SIZE + 1);
	while( (n = read(fd, &buf, BUFF_SIZE) > 0))
	{
		rst = strjointorendre(rst, buf);
		if(ft_strchr(rst, '\n'))
		{
			*line = liner(rst);
			rst = buffrest(rst);
			return(1);
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	*line = rst;
	return(0);
}
