/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darabi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:30:11 by darabi            #+#    #+#             */
/*   Updated: 2015/12/02 15:35:24 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		replace_map(char **map, int x, int y, t_filler **filler)
{
	int i;
	int j;

	i = 0;
	while ((*filler)->piece[i] && map[x + i])
	{
		j = 0;
		while ((*filler)->piece[i][j] && map[x + i][y + j])
		{
			if (map[x + i][y + j] == (*filler)->letter)
				map[x + i][y + j] = '.';
			++j;
		}
		++i;
	}
}

void		init_var(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

int			checking_it(t_filler *filler, char c, char p, int *one)
{
	if (c && (c == filler->letter ||\
	c == ft_toupper(filler->letter)) && p == '*')
	{
		++*one;
		return (1);
	}
	return (0);
}

void		check_map_test(char **tab, int x, int y, t_filler **filler)
{
	int i;
	int j;
	int one;
	int touch;

	init_var(&touch, &one, &i);
	while (tab[x + i] && (*filler)->piece[i])
	{
		j = 0;
		while (tab[x + i][y + j] && (*filler)->piece[i][j])
		{
			if (checking_it(*filler, tab[x + i][y + j],\
			(*filler)->piece[i][j], &one))
				tab[x + i][y + j] = ft_toupper((*filler)->letter);
			else if (tab[x + i][y + j] == '.' && (*filler)->piece[i][j] == '*')
			{
				++touch;
				tab[x + i][y + j] = (*filler)->letter;
			}
			++j;
		}
		++i;
	}
	if (one == 1 && (one + touch) == (*filler)->count)
		is_cool(filler, x, y, tab);
}
