/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:14:27 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/18 02:21:15 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*strjoin(char *tofree, char *buf)
{
	char	*rez;
	int		i;
	int		j;

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
	if (!(rez = (char *)ft_memalloc(sizeof(char) * i + j + 1)))
		return (NULL);
	rez = ft_strcpy(rez, tofree);
	rez = ft_strcat(rez, buf);
	return (rez);
}

char	*liner(char *linetoclear)
{
	size_t		i;
	char		*ret;

	ret = NULL;
	i = 0;
	while (linetoclear[i] != '\0' && linetoclear[i] != '\n')
		i++;
	if (!(ret = ft_strndup(linetoclear, i)))
		return (NULL);
	free(linetoclear);
	return (ret);
}

char	*buffrest(char *str)
{
	char *rest;

	rest = NULL;
	if (!(ft_strchr(str, '\n') + 1))
	{
		free(str);
//		ft_putendl("la");
		return(rest);
	}	
	if (ft_strchr(str, '\n') + 1)
	{
//		ft_putendl("ou la dans le buffrest");
		rest = ft_strdup(ft_strchr(str, '\n') + 1);
//		ft_putendl("ici");
	}
	return (rest);
}

int		get_next_line(const int fd, char **line)
{
	static char		*rst = NULL;
	char			buf[BUFF_SIZE + 1];
	int				n;


	ft_bzero(buf, BUFF_SIZE + 1);
	while ((n = read(fd, &buf, BUFF_SIZE) > 0))
	{
		if(n < 0)
			return(-1);
		rst = strjoin(rst, buf);
		if (ft_strchr(buf, '\n'))
		{
			*line = liner(rst);
//			ft_putendl("apres le liner dans la boucle");
			rst = buffrest(rst);
			return (1);
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	if (ft_strchr(rst, '\n'))
	{
//		ft_putendl("afterwhile");
		*line = liner(rst);
//		ft_putendl("afterwhile liner");
		rst = buffrest(rst);
//		ft_putendl("afterwhile buff");
		return (1);
	}
//	ft_putendl("after if pass ?");
	*line = liner(rst);
	return (0);
}
