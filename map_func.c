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

void		new_piece(t_filler **filler, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	(*filler)->piece = (char **)malloc(((*filler)->x + 1) * sizeof(char *));
	while ((*filler)->old[x + i])
	{
		j = 0;
		(*filler)->piece[i] = ft_strnew(ft_strlen((*filler)->old[x + i]) + 2);
		while ((*filler)->old[x + i][y + j])
		{
			(*filler)->piece[i][j] = (*filler)->old[x + i][y + j];
			++j;
		}
		(*filler)->piece[i][j] = '\0';
		++i;
	}
	(*filler)->piece[i] = NULL;
}

int			first_coord(t_filler **filler)
{
	int i;
	int j;

	(*filler)->x_dec = INT_MAX;
	(*filler)->y_dec = INT_MAX;
	(*filler)->count = 0;
	i = 0;
	while ((*filler)->old[i])
	{
		j = 0;
		while ((*filler)->old[i][j])
		{
			if ((*filler)->old[i][j] == '*')
				++(*filler)->count;
			if ((*filler)->old[i][j] == '*' && i < (*filler)->x_dec)
				(*filler)->x_dec = i;
			if ((*filler)->old[i][j] == '*' && j < (*filler)->y_dec)
				(*filler)->y_dec = j;
			++j;
		}
		++i;
	}
	new_piece(filler, (*filler)->x_dec, (*filler)->y_dec);
	return (1);
}

char		**copy_map(char **map)
{
	int		i;
	char	**tab;

	i = 0;
	while (map[i])
		++i;
	tab = (char **)malloc((i + 3) * sizeof(char *));
	i = 0;
	while (map[i])
	{
		tab[i] = ft_strdup(map[i]);
		++i;
	}
	tab[i] = NULL;
	return (tab);
}

void		free_tab(char ***tab)
{
	int i;

	i = 0;
	while ((*tab)[i])
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		++i;
	}
	free(*tab);
}
