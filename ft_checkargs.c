/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkargs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratardi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 19:22:13 by fratardi          #+#    #+#             */
/*   Updated: 2018/12/11 16:24:02 by fratardi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_checkargs(int argc)
{
	if(argc <= 1)
	{
		ft_putendl("File name is missing.");
		return(0);
	}
	if(argc > 2)
	{
		ft_putendl("Too many arguments.");
		return(0);
	}



	return(1);
}
