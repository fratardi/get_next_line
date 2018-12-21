/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:14:27 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/21 01:11:18 by fratardi         ###   ########.fr       */
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
	if (!(ft_strchr(str, '\n') + 1))
	{
		free(str);
		return (rest);
	}
	else if (ft_strchr(str, '\n'))
		rest = ft_strdup(ft_strchr(str, '\n') + 1);
	free(str);
	return (rest);
}

int		get_next_line(const int fd, char **line)
{
	static void		*rst;
	char			buf[BUFF_SIZE + 1];
	int				n;

	ft_bzero(buf, BUFF_SIZE + 1);
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
	if ((rst = buffrest(rst)))
		return (1);
	free(rst);
	return (0);
}
