/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 09:34:05 by vdarmaya          #+#    #+#             */
/*   Updated: 2017/02/03 06:34:52 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/filler.h"

int		get_pos_score(t_content *info, t_pos pos, t_pos p)
{
	t_srad	piece_srad;

	if (SRAD[p.y][p.x].score > 0)
		return (1);
	if (!SRAD[p.y][p.x].rad)
		return (-1);
	piece_srad = distance_point_piece(info, pos, p);
	if (SRAD[p.y][p.x].rad < piece_srad.rad)
		return (-1);
	if (SRAD[p.y][p.x].rad > piece_srad.rad)
		return (1);
	if (SRAD[p.y][p.x].score > piece_srad.score)
		return (-1);
	if (SRAD[p.y][p.x].score < piece_srad.score)
		return (1);
	return (0);
}

int		get_score(t_content *info, t_pos pos)
{
	int		total;
	t_pos	p;

	total = 0;
	p = (t_pos){-1, -1};
	while (++(p.y) < MAPY)
	{
		p.x = -1;
		while (++(p.x) < MAPX)
			total += get_pos_score(info, pos, p);
	}
	return (total);
}

char	get_ref_score(t_content *info)
{
	t_pos	pos;

	if (!(SRAD = (t_srad**)malloc(sizeof(t_srad*) * MAPY + 1)))
		return (1);
	SRAD[MAPY] = NULL;
	pos = (t_pos){-1, -1};
	while (++(pos.y) < MAPY)
	{
		if (!(SRAD[pos.y] = (t_srad*)malloc(sizeof(t_srad) * MAPX)))
			return (1);
		pos.x = -1;
		while (++(pos.x) < MAPX)
			SRAD[pos.y][pos.x] = get_pos_rad(info, pos);
	}
	return (0);
}
