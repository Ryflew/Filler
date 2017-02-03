/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 00:41:03 by vdarmaya          #+#    #+#             */
/*   Updated: 2017/02/02 01:39:21 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/filler.h"

void	clear_info(t_content *info)
{
	int		i;

	MAPX = 0;
	MAPY = 0;
	if (MAP)
		ft_strdelpp(&(MAP));
	PX = 0;
	PY = 0;
	if (P)
		ft_strdelpp(&(P));
	i = -1;
	if (SRAD)
	{
		while (SRAD[++i])
			free(SRAD[i]);
		free(SRAD);
		SRAD = NULL;
	}
}

char	need_trim(t_content *info)
{
	int		i;
	int		value;

	i = -1;
	value = 0;
	while (++i < PY)
		if (P[i][PX - 1] != '.')
			++value;
	if (!value)
		return (1);
	value = 0;
	i = -1;
	while (++i < PX)
		if (P[PY - 1][i] != '.')
			++value;
	if (!value)
		return (1);
	return (0);
}

int		get_piece_y(t_content *info)
{
	int		y;

	y = PY;
	while (--y >= 0)
	{
		if (ft_strchr(P[y], '*'))
			return (y + 1);
	}
	return (0);
}

int		get_piece_x(t_content *info)
{
	int		x;
	int		y;

	x = PX;
	while (--x >= 0)
	{
		y = -1;
		while (++y < PY)
			if (P[y][x] == '*')
				return (x + 1);
	}
	return (0);
}

void	trim_piece(t_content *info)
{
	char	**new_piece;
	int		i;
	int		y_out;
	int		x_out;

	if (need_trim(info))
	{
		y_out = get_piece_y(info);
		if (!(new_piece = (char**)malloc(sizeof(char*) * (y_out + 1))))
			return ;
		new_piece[y_out] = NULL;
		x_out = get_piece_x(info);
		i = -1;
		while (++i < y_out)
			new_piece[i] = ft_strsub(P[i], 0, x_out);
		PX = x_out;
		PY = y_out;
		ft_strdelpp(&(P));
		P = new_piece;
	}
}
