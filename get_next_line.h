/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:08:49 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/13 22:40:08 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 1

/*typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct		s_list 	*next;
}						t_list;
*/
int						get_next_line2(const int fd, char **line);
int						get_next_line(const int fd, char **line);
int						ft_checkargs(int argc);
void					ft_putendl(const char *s);
#endif
