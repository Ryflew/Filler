/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radius.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 01:17:43 by vdarmaya          #+#    #+#             */
/*   Updated: 2017/02/02 01:39:14 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <limits.h>
#include "../include/filler.h"

int		dist(t_pos pos1, t_pos pos2)
{
	pos1.x -= pos2.x;
	pos1.y -= pos2.y;
	return (MAX(ABS(pos1.x), ABS(pos1.y)));
}

t_srad	distance_point_piece(t_content *info, t_pos pos, t_pos p)
{
	int		rad;
	t_srad	best_rad;
	t_pos	piece_pos;

	best_rad.rad = INT_MAX;
	best_rad.score = 0;
	piece_pos = (t_pos){-1, -1};
	while (++(piece_pos.y) < PY)
	{
		piece_pos.x = -1;
		while (++(piece_pos.x) < PX)
		{
			rad = dist(p, (t_pos){pos.x + piece_pos.x, pos.y + piece_pos.y});
			if (best_rad.rad > rad)
				best_rad.rad = rad;
			else if (best_rad.rad == rad)
				++(best_rad.score);
		}
	}
	return (best_rad);
}

int		get_rad_score2(t_content *info, t_pos pos)
{
	if (pos.x >= 0 && pos.y >= 0 && pos.x < MAPX && pos.y < MAPY)
	{
		if (MAP[pos.y][pos.x] == PLAYER)
			return (1);
		if (MAP[pos.y][pos.x] == ENEMY)
			return (-1);
	}
	return (0);
}

int		get_rad_score(t_content *info, t_pos pos, int rad)
{
	int		score;
	t_pos	p;

	if (!rad)
		return (get_rad_score2(info, pos));
	score = 0;
	p.x = pos.x - rad;
	p.y = pos.y - rad;
	while (p.x < pos.x + rad)
		score += get_rad_score2(info, (t_pos){p.x++, p.y});
	while (p.y < pos.y + rad)
		score += get_rad_score2(info, (t_pos){p.x, p.y++});
	while (p.x > pos.x - rad)
		score += get_rad_score2(info, (t_pos){p.x--, p.y});
	while (p.y > pos.y - rad)
		score += get_rad_score2(info, (t_pos){p.x, p.y--});
	return (score);
}

t_srad	get_pos_rad(t_content *info, t_pos pos)
{
	int		rad;
	int		maxrad;
	int		score;

	rad = -1;
	maxrad = MAX(MAPX, MAPY);
	while (++rad < maxrad)
	{
		score = get_rad_score(info, pos, rad);
		if (score < 0)
			return ((t_srad){-1, rad});
		if (score > 0)
			return ((t_srad){1, rad});
	}
	return ((t_srad){0, rad});
}
