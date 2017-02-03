/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:12:25 by vdarmaya          #+#    #+#             */
/*   Updated: 2017/02/03 07:23:51 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/filler.h"
#include "../include/get_next_line.h"

char	get_player(t_content *info)
{
	char	*str;
	char	c;

	get_next_line(0, &str);
	c = ft_atoi(str + 10);
	ft_strdel(&str);
	if (!(c == 1 || c == 2))
		return (1);
	PLAYER = (c == 1) ? 'O' : 'X';
	ENEMY = (c == 1) ? 'X' : 'O';
	return (0);
}

int		main(void)
{
	t_content	info;

	info = (t_content){0, 0, (t_pos){0, 0}, NULL, (t_pos){0, 0}, NULL, NULL};
	if (get_player(&info))
		ft_putstr_fd("Bad player info.\n", 2);
	else
		go_core(&info);
	clear_info(&info);
	return (0);
}
