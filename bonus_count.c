/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darabi <darabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:27:49 by darabi            #+#    #+#             */
/*   Updated: 2016/02/10 14:55:26 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	what_is_it(t_filler *filler, char c, int *me, int *other)
{
	if (c == filler->letter || c == ft_toupper(filler->letter))
		++*me;
	else if (c == filler->opp_letter || c == ft_toupper(filler->opp_letter))
		++*other;
}

void	count_it(char **tab, t_filler *filler, int me, int other)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			what_is_it(filler, tab[i][j], &me, &other);
			++j;
		}
		++i;
	}
	if (me > other)
	{
		ft_putstr_fd("\033[32mWOOT WOOT J'AI GAGNE\033[00m\n", 2);
		ft_putstr_fd("\033[33mJ'ai joué ", 2);
		ft_putnbr_fd(filler->turn - 1, 2);
		ft_putstr_fd(" fois.\n", 2);
		ft_putstr_fd("J'ai ", 2);
		ft_putnbr_fd(me - other, 2);
		ft_putstr_fd(" cases d'avance !\033[00m\n", 2);
	}
}
