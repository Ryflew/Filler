/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 03:05:00 by vdarmaya          #+#    #+#             */
/*   Updated: 2017/02/03 07:07:18 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/filler.h"

char	errexit(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}

char	errexit_free(char ***str, char **s, int i)
{
	ft_strdel(s);
	while (--i > 0)
		ft_strdel(&(*str[i]));
	free(*(str));
	*str = NULL;
	return (errexit("Invalid str."));
}
