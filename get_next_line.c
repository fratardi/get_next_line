/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:14:27 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/21 05:52:57 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoinfree(char *tofree, char *buf)
{
	char		*rez;
	size_t		i;
	size_t		j;

	if (!(tofree || buf))
		return (NULL);
	if (tofree && !buf)
	{
		rez = ft_strdup(tofree);
		free(tofree);
		return (rez);
	}
	if (!tofree && buf)
	{
		rez = ft_strdup(buf);
		return (rez);
	}
	j = ft_strlen(buf);
	i = ft_strlen(tofree);
	if (!(rez = (char *)malloc(sizeof(char) * i + j + 1)))
		return (NULL);
	rez = ft_strcpy(rez, tofree);
	rez = ft_strcat(rez, buf);
	free(tofree);
	return (rez);
}

char	*liner(char *linetoclear)
{
	int		i;
	char	*ret;

	ret = NULL;
	i = 0;
//	if (!linetoclear)
//		return(NULL);
	while (linetoclear[i] != '\0' && linetoclear[i] != '\n')
		i++;
	if (!(ret = ft_strndup(linetoclear, i)))
		return (NULL);
	return (ret);
}

char	*buffrest(char *str)
{
	char	*rest;

	rest = NULL;
	if(!str)
		return(rest);
	if (!(ft_strchr(str, '\n') + 1))
	{
		free(str);
		return (rest);
	}
	if (ft_strchr(str, '\n') && (ft_strchr(str, '\n') + 1))
		rest = ft_strdup(ft_strchr(str, '\n') + 1);
	free(str);
	return (rest);
}

#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	static void		*rst;
	char			buf[BUFF_SIZE + 1];
	size_t			n;

	ft_bzero(buf, BUFF_SIZE + 1);
	if(fd < 0)
		return(-1);
	while ((n = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		rst = strjoinfree(rst, buf);
		if (ft_strchr(rst, '\n'))
		{
			*line = liner(rst);
			rst = buffrest(rst);
			return (1);
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	*line = liner(rst);
	printf("line >>%p<<\tline : >>%s<<\n", line, *line);
	if ((rst = buffrest(rst)) || *line)
		return (1);
	write(1, "proute ca mere\n", 14);
	free(rst);
	rst = NULL;
	return (0);
}
