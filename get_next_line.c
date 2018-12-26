/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:14:27 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/26 08:11:57 by fratardi         ###   ########.fr       */
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
	if (!linetoclear)
		return (NULL);
	while (linetoclear[i] != '\0' && linetoclear[i] != '\n')
		i++;
	if (!(ret = ft_strndup(linetoclear, i)))
		return (NULL);
	ret[i] = 0;
	return (ret);
}

char	*buffrest(char *str)
{
	char	*rest;

	rest = NULL;
	if (!str)
		return (rest);
	if (!(ft_strchr(str, '\n') + 1))
	{
		free(str);
		return (rest);
	}
	if (ft_strchr(str, '\n'))
		rest = ft_strdup(ft_strchr(str, '\n') + 1);
	free(str);
	return (rest);
}

int		get_next_line(const int fd, char **line)
{
	static void		*rst[OPEN_MAX + 1];
	char			buf[BUFF_SIZE + 1];
	int				n;

	if (fd < 0 || line == (void *)0)
		return (-1);
	while ((n = read(fd, &buf, BUFF_SIZE)) > 0)
	{
		buf[n] = 0;
		rst[fd] = strjoinfree(rst[fd], buf);
		if (ft_strchr(rst[fd], '\n'))
			break ;
	}
	*line = liner(rst[fd]);
	if ((rst[fd] = buffrest(rst[fd])) || *line)
	{
		if (!(**line) && !rst[fd])
			return (0);
		return (1);
	}
	return ((n == 0) ? 0 : -1);
}
