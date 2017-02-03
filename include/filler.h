/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:11:19 by vdarmaya          #+#    #+#             */
/*   Updated: 2017/02/03 06:50:56 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/include/libft.h"

# define PLAYER info->player
# define ENEMY info->enemy
# define MAP info->map
# define MAPX info->map_size.x
# define MAPY info->map_size.y
# define P info->piece
# define PX info->piece_size.x
# define PY info->piece_size.y
# define SRAD info->srad

# define C_RESET	"\x1B[0m"
# define C_RED		"\x1B[31m"
# define C_BLUE		"\x1B[34m"
# define STIME		50000

typedef struct	s_pos
{
	int			x;
	int			y;
}				t_pos;

typedef struct	s_spos
{
	int			score;
	t_pos		pos;
}				t_spos;

typedef struct	s_srad
{
	int			score;
	int			rad;
}				t_srad;

typedef struct	s_content
{
	char		player;
	char		enemy;
	t_pos		map_size;
	char		**map;
	t_pos		piece_size;
	char		**piece;
	t_srad		**srad;
}				t_content;

int				get_score(t_content *info, t_pos pos);
char			get_map_size(t_content *info, char *str);
char			get_map(t_content *info);
char			get_piece_size(t_content *info, char *str);
char			get_piece(t_content *info);
char			errexit(char *str);
char			go_solve(t_content *info);
char			get_ref_score(t_content *info);
char			errexit_free(char ***str, char **s, int i);
void			go_core(t_content *info);
void			clear_info(t_content *info);
void			trim_piece(t_content *info);
void			print_score(char *str);
void			print_tab(char **tab);
t_srad			distance_point_piece(t_content *info, t_pos pos, t_pos p);
t_srad			get_pos_rad(t_content *info, t_pos pos);

#endif
