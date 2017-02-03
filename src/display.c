/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 01:42:11 by vdarmaya          #+#    #+#             */
/*   Updated: 2017/02/03 07:34:30 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../include/filler.h"
#include "../include/get_next_line.h"

void	add_char(char **print, char *str, char c)
{
	char	*tmp;

	if (!str && c)
	{
		tmp = ft_strjoinchar(*print, c);
		free(*print);
		*print = tmp;
	}
	else if (str && !c)
	{
		tmp = ft_strjoin(*print, str);
		free(*print);
		*print = tmp;
	}
}

void	get_and_prompt2(int y, int *j, char ***print)
{
	char	*str;
	char	*tmp;

	while (y-- > 0)
	{
		get_next_line(0, &str);
		tmp = ft_strchr(str, ' ') + 1;
		add_char(&((*print)[*j]), "| ", 0);
		while (tmp && *tmp)
		{
			if (*tmp == 'O' || *tmp == 'o')
				add_char(&((*print)[*j]), C_BLUE, 0);
			else if (*tmp == 'X' || *tmp == 'x')
				add_char(&((*print)[*j]), C_RED, 0);
			add_char(&((*print)[*j]), NULL, *tmp);
			if (*tmp != '.')
				add_char(&((*print)[*j]), C_RESET, 0);
			++tmp;
		}
		add_char(&((*print)[*j]), " |", 0);
		++(*j);
		ft_strdel(&str);
	}
}

void	get_and_prompt(int x, int y)
{
	int		i;
	int		j;
	char	*str;
	char	**print;

	if (!(print = (char**)malloc(sizeof(char*) * (y + 3))))
		exit(EXIT_FAILURE);
	print[y + 2] = NULL;
	i = -1;
	while (++i < y + 1)
		print[i] = ft_strdup("");
	get_next_line(0, &str);
	free(str);
	j = x;
	while (x-- > -4)
		add_char(&print[0], NULL, '-');
	x = j;
	j = 1;
	get_and_prompt2(y, &j, &print);
	print[j] = ft_strdup(print[0]);
	usleep(STIME);
	system("clear");
	print_tab(print);
	ft_strdelpp(&print);
}

void	go_display(char *str)
{
	int		x;
	int		y;
	char	*tmp;
	char	*tmp2;

	tmp = str + 8;
	y = ft_atoi(tmp);
	if (!y)
	{
		ft_putendl("Invalid map Y.");
		return ;
	}
	tmp2 = ft_itoa(y);
	x = ft_atoi(tmp + ft_strlen(tmp2) + 1);
	free(tmp2);
	if (!x)
	{
		ft_putendl("Invalid map Y.");
		return ;
	}
	get_and_prompt(x, y);
}

int		main(void)
{
	char	*str;

	while (get_next_line(0, &str))
	{
		if (ft_strcont(str, "Plateau "))
			go_display(str);
		if (ft_strcont(str, "=="))
			print_score(str);
		free(str);
	}
	return (0);
}
