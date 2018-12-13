/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:14:27 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/13 22:40:50 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


//le liner met le conenu du rest sans le \n dans une string
char *liner(char *linetoclear)
{
	size_t i;
	char *ret;
	ret = NULL;
	i = 0;
//	ft_putendl("ici");
	while(linetoclear[i] != '\n' && linetoclear[i] != '\0')
		i++;
//	ft_putendl("lol ?");
	if(!(ret = ft_strndup(linetoclear, i)))
		return(NULL);
//	ft_putendl("la ? ");
	free(linetoclear);
	return(ret);
}

//apres l'avoir clear rentre dans rst le restant du buffer apres le \n 
char *buffrest(char *str)
{
	char *rest;
	rest = NULL;
//	ft_putendl("trydup ");
	rest = ft_strdup(ft_strchr(str, '\n') + 1);
//	ft_putendl("success dup");
//	ft_putendl(str);
	return(rest);
}

int		get_next_line(const int fd, char **line)
{
	static char *rst;
	char buf[BUFF_SIZE + 1];
//	char *ret;
	size_t n;

if(	rst == NULL)
	rst="";
	ft_bzero(buf, BUFF_SIZE + 1);
// la boucle passe sur le buffer tant que n (la valeur retour de mon read) est superieur a zero
	while(0 < (n = read(fd, &buf, BUFF_SIZE)))
	{	
//concatene a rst le buffer
	/*	ft_putendl(*/rst = ft_strjoin(rst, buf);
// si mon buffer contient un \n
	if(ft_strchr(buf, '\n'))
		{
//			ft_putendl(rst);
//copie dans la ligne le contenu de rst jusqu'au \n  et libere le rst precedent
			*line = liner(rst);
//copie le reste du buffer apres le \n dans rst
		//	ft_putendl("buffrest entree");
			rst = buffrest(buf);
		//	ft_putendl(rst);
//retour correstpondant a la fin d'une ligne
			return(1);
		}
// clear le buffer pour le prochain tour
		ft_bzero(buf, BUFF_SIZE + 1);
	}
//applique
//	rst = ft_strjoin(rst, buf);
	//rst = buffrest(buf);
	*line = liner(rst);
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
