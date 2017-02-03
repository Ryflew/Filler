/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 23:21:12 by vdarmaya          #+#    #+#             */
/*   Updated: 2017/02/03 06:23:28 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "../include/filler.h"
#include "../include/get_next_line.h"

void	go_algo(t_content *info, t_pos pos, t_spos *best)
{
	int		score;

	score = get_score(info, pos);
	if (score > best->score)
	{
		best->score = score;
		best->pos = pos;
	}
}

int		try_put(t_content *info, int x, int y)
{
	int		i;
	int		j;
	int		same;
	char	enemy;

	same = 0;
	enemy = (PLAYER == 'O') ? 'X' : 'O';
	i = -1;
	while (P[++i] && ((y + i) <= MAPY))
	{
		j = -1;
		while (P[i][++j] && ((x + j) <= MAPX))
		{
			if ((MAP[y + i][x + j] == enemy || MAP[y + i][x + j] == enemy + 32)
				&& P[i][j] == '*')
				return (0);
			else if ((MAP[y + i][x + j] == PLAYER || \
					MAP[y + i][x + j] == PLAYER + 32) && P[i][j] == '*')
				++same;
		}
	}
	if (same == 1)
		return (1);
	return (0);
}

char	go_solve(t_content *info)
{
	char	value;
	t_pos	pos;
	t_spos	best;

	value = 1;
	pos = (t_pos){-1, -1};
	best = (t_spos){INT_MIN, (t_pos){0, 0}};
	while ((++(pos.y) + PY) <= MAPY)
	{
		pos.x = -1;
		while ((++(pos.x) + PX) <= MAPX)
		{
			if (try_put(info, pos.x, pos.y))
			{
				go_algo(info, pos, &best);
				value = 0;
			}
		}
	}
	ft_putnbr(best.pos.y);
	ft_putchar(' ');
	ft_putnbr(best.pos.x);
	ft_putchar('\n');
	return (value);
}

void	go_core(t_content *info)
{
	char	*str;

	while (get_next_line(0, &str))
	{
		if (ft_strcont(str, "Plateau "))
		{
			clear_info(info);
			if (get_map_size(info, str) || get_map(info))
				break ;
		}
		else if (ft_strcont(str, "Piece "))
		{
			if (get_piece_size(info, str) || get_piece(info) || go_solve(info))
				break ;
		}
		else
		{
			ft_putendl_fd("Bad info.", 2);
			break ;
		}
		free(str);
	}
	free(str);
}
