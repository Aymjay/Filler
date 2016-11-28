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

char	*check_part(char *tab, int count, int y)
{
	if (count == y)
	{
		tab[count] = '\0';
		return (tab);
	}
	return (0);
}

char	*check_this_line(char *str, int y, int *first, t_filler **filler)
{
	int		i;
	int		count;
	char	*tab;

	tab = malloc(ft_strlen(str) * sizeof(char));
	count = 0;
	i = 0;
	while (ft_isdigit(str[i]) == 1 && str[i])
		++i;
	if (str[i] && str[i] == ' ')
		++i;
	while (str[i] && (str[i] == 'X' || str[i] == 'x' ||\
	str[i] == 'o' || str[i] == 'O' || str[i] == '.'))
	{
		if (str[i] != '.' && *first == 0)
		{
			*first = 1;
			(*filler)->order = ft_tolower(str[i]);
		}
		tab[count] = str[i];
		++i;
		++count;
	}
	return (check_part(tab, count, y));
}

char	**map_check(t_filler **filler)
{
	char	*line;
	int		i;
	char	**tab;
	int		first;

	first = 0;
	i = 0;
	get_next_line(0, &line);
	tab = malloc(((*filler)->x + 1) * sizeof(char *));
	while (i < (*filler)->x && line)
	{
		if (!(tab[i] = check_this_line(line, (*filler)->y, &first, filler)))
			exit(0);
		free(line);
		line = NULL;
		get_next_line(0, &line);
		++i;
	}
	tab[i] = NULL;
	piece_initialize(filler, line, 0, 0);
	free(line);
	(*filler)->old = piece_check((*filler)->x, (*filler)->y);
	return (tab);
}
