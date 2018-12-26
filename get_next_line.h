/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:08:49 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/26 04:40:06 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
//reste 5 lignes 
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF_SIZE 6000


//# define BUFF_SIZE 8381921
int						get_next_line(const int fd, char **line);
int						ft_checkargs(int argc);
void					ft_putendl(const char *s);
#endif
