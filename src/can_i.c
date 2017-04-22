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

int			opp_letter(char c, t_filler *filler)
{
	if (c == filler->opp_letter || c == ft_toupper(filler->opp_letter))
		return (1);
	return (0);
}

int			around(char **map, int i, int j, t_filler *filler)
{
	int cool;

	cool = 0;
	if (i > 0)
	{
		if (map[i - 1] && opp_letter(map[i - 1][j], filler))
			++cool;
	}
	if (j > 0)
	{
		if (map[i][j - 1] && opp_letter(map[i][j - 1], filler))
			++cool;
	}
	if (map[i + 1] && opp_letter(map[i + 1][j], filler))
		++cool;
	if (opp_letter(map[i][j + 1], filler))
		++cool;
	return (cool);
}

void		is_cool_var(t_filler **filler, int cool, int x, int y)
{
	(*filler)->my_cool = cool;
	(*filler)->x_answer = x;
	(*filler)->y_answer = y;
}

void		is_cool(t_filler **filler, int x, int y, char **map)
{
	int i;
	int j;
	int cool;
	int touch;

	touch = 1;
	i = 0;
	cool = 0;
	while (map[i + x] && touch != (*filler)->count)
	{
		j = 0;
		while (map[x + i][y + j] && touch != (*filler)->count)
		{
			if (map[i + x][y + j] == (*filler)->letter)
			{
				++touch;
				cool = cool + around(map, i + x, j + y, *filler);
			}
			++j;
		}
		++i;
	}
	if (cool > (*filler)->my_cool || (cool == (*filler)->my_cool &&\
	(*filler)->order != (*filler)->opp_letter))
		is_cool_var(filler, cool, x - (*filler)->x_dec, y - (*filler)->y_dec);
}

int			can_i(t_filler **filler, int x, int y, char **tab)
{
	int touch;

	touch = 0;
	if (!tab[x])
	{
		if ((*filler)->my_cool != INT_MIN)
		{
			ft_printf("%d %d\n", (*filler)->x_answer, (*filler)->y_answer);
			return (1);
		}
		ft_printf("0 0\n");
		count_it(tab, *filler, 0, 0);
		exit(-1);
	}
	check_map_test(tab, x, y, filler);
	replace_map(tab, x, y, filler);
	if (!tab[x][y])
		return (can_i(filler, x + 1, 0, tab));
	return (can_i(filler, x, y + 1, tab));
}
