/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:14:27 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/12 00:53:18 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *liner(char *rst)
{
	size_t i;

	i = 0;
	while(rst[i] != '\n')
		i++;
	return(ft_strndup(rst, i));
}

char *freemer(char *str)
{
	char *lol;

	lol = liner(str);
	free(str);
	return(lol);
}



int		get_next_line(const int fd, char **line)
{
	static char *rst;
	char buf[BUFF_SIZE + 1];
	char *p;
	size_t i;

//if(!rst)
	rst = "";
	ft_bzero(buf, BUFF_SIZE + 1);
	i = 0;
	while(read(fd, &buf, BUFF_SIZE))
	{
		rst = ft_strjoin(rst, buf);
		ft_bzero(buf, BUFF_SIZE + 1);
	p = ft_strchr(rst, '\n');
	if(!p)
	{


		*line = ft_strdup(rst);
		rst = freemer(rst);
		line++;
		free(line);
		return(1);
	}
	}
	if(p)
	{
		*line = liner(rst);
//	rst = freemer(rst);
		line++;
		free(*line);
		//line++;
		return(0);
	}
	return(0);
}
///* Le premier paramètre est le file descriptor depuis lequel lire.
//** Le second paramètre est l’adresse d’un pointeur sur caractère qui servira à stocker
//**la ligne lue sur le file descriptor.
//** La valeur de retour peut être 1, 0 ou -1 selon qu’une ligne a été lue, que la lecture est terminée ou bien qu’une erreur est survenue respectivement.
//** Votre fonction get_next_line doit renvoyer son resultat sans le ’\n’.
//** Un appel en boucle à votre fonction get_next_line permettra donc de lire le texte disponible sur un descripteur de fichier une ligne à la fois jusqu’à la fin du texte, quelque soit la taille du texte en question ou d’une de ses lignes.
//** Assurez-vous que votre fonction se comporte bien lorsqu’elle lit depuis un fichier, depuis l’entrée standard, depuis une redirection, etc.
//
// Que faire ??? 
// si le buffer est plus grand que le fichier;
// si mon fichier ne fait qu'une seule et unique ligne
// si mon fichier est vide 
// si mon buffer passe sur un retour et qui'il reste des char dans le buffer 
// si BUFFSIZE < 0 ou = 0
//
//
//				
//						  ......	
//				[bonjour\nje suis]
//
//
//
//
//
//
//
