/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_turn_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 02:51:53 by vdarmaya          #+#    #+#             */
/*   Updated: 2017/02/03 07:06:16 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/get_next_line.h"

char	get_map_size(t_content *info, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (ft_strlen(str) <= 8)
		return (errexit("Invalid map size."));
	tmp = str + 8;
	MAPY = ft_atoi(tmp);
	if (MAPY == 0)
		return (errexit("Invalid map Y."));
	tmp2 = ft_itoa(MAPY);
	if (ft_strlen(tmp) == ft_strlen(tmp2))
	{
		free(tmp2);
		return (errexit("Invalid map size."));
	}
	MAPX = ft_atoi(tmp + ft_strlen(tmp2) + 1);
	free(tmp2);
	if (!MAPX)
		return (errexit("Invalid map X."));
	return (0);
}

char	get_map(t_content *info)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	get_next_line(0, &str);
	free(str);
	if (!(MAP = (char**)malloc(sizeof(char*) * (MAPY + 1))))
		return (errexit("Malloc failed."));
	MAP[MAPY] = NULL;
	i = -1;
	while (++i < MAPY)
	{
		get_next_line(0, &str);
		if (ft_strlen(str) <= 4 || !ft_strchr(str, ' '))
			return (errexit_free(&MAP, &str, i));
		tmp = ft_strchr(str, ' ') + 1;
		if (ft_strlen(tmp) != (size_t)MAPX)
			return (errexit_free(&MAP, &str, i));
		MAP[i] = ft_strdup(tmp);
		free(str);
	}
	if (get_ref_score(info))
		return (errexit("Malloc failed."));
	return (0);
}

char	get_piece_size(t_content *info, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (ft_strlen(str) <= 6)
		return (errexit("Invalid piece size."));
	tmp = str + 6;
	PY = ft_atoi(tmp);
	if (!PY)
		return (errexit("Invalid size piece Y."));
	tmp2 = ft_itoa(PY);
	if (ft_strlen(tmp) == ft_strlen(tmp2))
	{
		free(tmp2);
		return (errexit("Invalid piece size."));
	}
	PX = ft_atoi(tmp + ft_strlen(tmp2) + 1);
	free(tmp2);
	if (!PX)
		return (errexit("Invalid piece X."));
	return (0);
}

char	get_piece(t_content *info)
{
	char	*str;
	int		i;

	if (!(P = (char**)malloc(sizeof(char*) * (PY + 1))))
		return (errexit("Malloc failed."));
	P[PY] = NULL;
	i = -1;
	while (++i < PY)
	{
		get_next_line(0, &str);
		if (ft_strlen(str) != (size_t)PX)
		{
			free(str);
			while (--i > 0)
				free(P[i]);
			free(P);
			P = NULL;
			return (errexit("Invalid piece."));
		}
		P[i] = ft_strdup(str);
		free(str);
	}
	trim_piece(info);
	return (0);
}
