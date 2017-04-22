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

void		check_first_line(char **line, t_filler **filler)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup("$$$ exec pX");
	while ((*line)[i] && (*line)[i] == str[i])
		++i;
	if ((*line)[i] == '2')
	{
		(*filler)->letter = 'x';
		(*filler)->opp_letter = 'o';
	}
	else if ((*line)[i] == '1')
	{
		(*filler)->letter = 'o';
		(*filler)->opp_letter = 'x';
	}
	else
		exit(0);
	free(str);
}

void		take_it(t_filler **filler)
{
	char *line;

	map_initialize(filler, "Plateau ", 0, 0);
	get_next_line(0, &line);
	free(line);
	(*filler)->map = map_check(filler);
}

char		**take_dim(char *line)
{
	char	*str;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = malloc(ft_strlen(line));
	while (ft_isdigit(line[i]) != 1)
		++i;
	while (ft_isdigit(line[i]) == 1)
	{
		str[j++] = line[i];
		++i;
	}
	str[j] = '\0';
	tab = (char **)malloc(ft_atoi(str) * sizeof(char *));
	while (ft_isdigit(line[i]) != 1)
		++i;
	while (ft_isdigit(line[i]) == 1)
	{
		str[j++] = line[i];
		++i;
	}
	return (tab);
}

int			main(int argc, char **argv)
{
	t_filler	*filler;
	char		*line;
	char		**map;

	argv[argc] = NULL;
	filler = malloc(1 * sizeof(t_filler));
	get_next_line(0, &line);
	check_first_line(&line, &filler);
	filler->turn = 0;
	while (1)
	{
		++(filler->turn);
		filler->my_cool = INT_MIN;
		take_it(&filler);
		first_coord(&filler);
		map = copy_map(filler->map);
		can_i(&filler, 0, 0, map);
		free_tab(&(filler->piece));
		free_tab(&(filler->map));
		free_tab(&map);
		free_tab(&(filler->old));
	}
	return (1);
}
