/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 04:35:19 by vdarmaya          #+#    #+#             */
/*   Updated: 2017/02/02 04:37:02 by vdarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/filler.h"

void	print_score(char *str)
{
	int		nb1;
	int		nb2;
	char	*buff;

	nb1 = ft_atoi(str + 10);
	get_next_line(0, &buff);
	nb2 = ft_atoi(buff + 10);
	free(buff);
	ft_putchar('\n');
	if (nb1 > nb2)
		ft_putendl("Le joueur 1 gagne !");
	else if (nb1 < nb2)
		ft_putendl("Le joueur 2 gagne !");
	else
		ft_putendl("Egalité !!!");
	ft_putchar('\n');
	ft_putstr(C_BLUE);
	ft_putstr("Score du joueur 1 : ");
	ft_putnbr(nb1);
	ft_putchar('\n');
	ft_putstr(C_RED);
	ft_putstr("Score du joueur 2 : ");
	ft_putnbr(nb2);
	ft_putchar('\n');
	ft_putstr(C_RESET);
}

void	print_tab(char **tab)
{
	int		i;

	i = -1;
	while (tab[++i])
		ft_putendl(tab[i]);
}
