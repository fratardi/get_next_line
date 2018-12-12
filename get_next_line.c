/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:14:27 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/12 07:14:38 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


//le liner met le conenu du rest sans le \n dans une string
char *liner(char *rest)
{
	size_t i;

	i = 0;
	while(rest[i] != '\n' && rest[i] != '\0')
		i++;
	return(ft_strndup(rest, i));
}

//apres l'avoir clear rentre dans rst le restant du buffer apres le \n 
char *buffrest(char *str)
{
	char *rest;
	rest = ft_strdup(ft_strchr(str, '\n') + 1);
	free(str);
	return(rest);
}

int		get_next_line(const int fd, char **line)
{
	static char *rst;
	char buf[BUFF_SIZE + 1];

	ft_bzero(buf, BUFF_SIZE + 1);
	while(0 < read(fd, &buf, BUFF_SIZE))
	{	
		rst = ft_strjoin(rst, buf);
		if(ft_strchr(buf, '\n'))
		{
			*line = liner(rst);
			rst = buffrest(rst);
			free (line);
			line++;
			return(1);
		}
		ft_bzero(buf, BUFF_SIZE + 1);
	}
	*line = liner(rst);
	free (line);
	line++;
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
