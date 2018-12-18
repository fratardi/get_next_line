/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 02:22:35 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/18 03:25:59 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



//fonction qui joint deux chaines dans une autre et qui libere la front

void	ft_joinfree(char *tofree, char  *buff)
{
	char *rendu;
	


}




// fonctionquiappliquelaligne

void	ft_liner(char *str, char *ligne)
{
	size_t i;

	i = 0;
		while(str[i] && str[i]!= '\n')
			i++;
		*ligne = *ft_strndup(str,i);
}



//fontionquiclearleresterdela partie avant le \n

void	ft_fonction(char *reste)
{
	char *tmp;

	tmp = NULL;
	if(ft_strchr(reste , '\n') + 1)
	{
	tmp = (char *)ft_memalloc(sizeof(char) * (ft_strlen(ft_strchr(reste , '\n') + 1)));
	tmp  = ft_strcpy(tmp , ft_strchr(reste , '\n') + 1);
	free (reste);
	reste = tmp;
	}
	else 
		free (reste);
}
int		get_next_line(const int fd, char **line)
{
	static char 	*bufrest = NULL;
	int 			n;
	char buf[BUFF_SIZE + 1];

	ft_bzero(buf, BUFF_SIZE + 1);
	while(0 < (n = read(fd, &buf, BUFF_SIZE)))
	{
		ft_putendl("bonjour");
			ft_joinfree(bufrest, buf);
		ft_putendl("ok");
		if(ft_strchr(bufrest, '\n'))
		{
			ft_liner(bufrest, *line);
			ft_fonction(bufrest);
			ft_putendl(*line);
			return(1);
		}
		ft_bzero(bufrest, BUFF_SIZE + 1);
	}
	if(ft_strchr(bufrest, '\n'))
	{
		ft_liner(bufrest, *line);
		ft_fonction(bufrest);
		return(1);
	}
	ft_liner(bufrest, *line);
	return(0);
}
