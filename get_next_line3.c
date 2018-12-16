/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 22:34:45 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/16 23:14:32 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *strjoin(char *tofree, char *buf)
{
	char    *rez;
	int     i;
	int     j;

	if (!(tofree || buf))
		return (NULL);
	if (tofree && !buf)
		return (ft_strdup(tofree));
	if (!tofree && buf)
		return (ft_strdup(buf));
	j = ft_strlen(buf);
	i = ft_strlen(tofree);
	if (!(rez = (char *)ft_memalloc(sizeof(char) * i + j + 1)))
		return (NULL);
	rez = ft_strcpy(rez, tofree);
	rez = ft_strcat(rez, buf);
	return (rez);
}

char *liner(char *str)
{
	size_t	i;
	char 	*ret;

	ret = NULL;
	i = 0;
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!(ret = ft_strndup(str, i)))
		return (NULL);
	free(str);
	return (ret);
}

char *buffrest(char *rest)
{
	char 	*tmp;
	size_t 	i;

	if(!(tmp = ft_strchr(rest , '\n') + 1))
		free(rest);
	rest = ft_strdup(tmp);
	return (rest);
}

int		get_next_line(const int fd, char **line)
{
	static char		*rest = NULL;
	char 			buf[BUFF_SIZE + 1];
	size_t 			n;

	ft_bzero(buf, BUFF_SIZE + 1);
	if(ft_strchr(rest, '\n'))
	{
		*line = liner(rest);
		rest = buffrest(rest);
		return(1);
	}
	while((0 < (n = read(fd, buf, BUFF_SIZE))))
	{
		rest = strjoin(rest, buf);
		if(ft_strchr(rest, '\n'))
		{
			*line = liner(rest);
			rest = buffrest(rest);
			return(1);
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	*line = liner(rest);
	return(0);
}
