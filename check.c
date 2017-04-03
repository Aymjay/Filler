/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darabi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:05:02 by darabi            #+#    #+#             */
/*   Updated: 2015/12/12 17:00:46 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		map_initialize(t_filler **filler, char *str, int i, int j)
{
	char *dim;
	char *line;

	get_next_line(0, &line);
	dim = malloc(ft_strlen(line) * sizeof(char));
	while (str[i] == line[i] && line[i])
		++i;
	while (ft_isdigit(line[i]) != 0 && line[i])
		dim[j++] = line[i++];
	dim[j] = '\0';
	(*filler)->x = ft_atoi(dim);
	if (line[i] == ' ')
		++i;
	free(dim);
	dim = malloc(ft_strlen(line) * sizeof(char));
	j = 0;
	while (ft_isdigit(line[i]) != 0 && line[i])
		dim[j++] = line[i++];
	dim[j] = '\0';
	(*filler)->y = ft_atoi(dim);
	free(dim);
	if (line[i] == ':' && line[i + 1] == '\0')
		free(line);
	else
		exit(0);
}

int			piece_initialize(t_filler **filler, char *line, int i, int j)
{
	char *dim;
	char *str;

	str = ft_strdup("Piece ");
	dim = malloc(ft_strlen(line) * sizeof(char));
	while (str[i] == line[i] && line[i])
		++i;
	while (ft_isdigit(line[i]) != 0 && line[i])
		dim[j++] = line[i++];
	dim[j] = '\0';
	(*filler)->x = ft_atoi(dim);
	if (line[i] == ' ')
		++i;
	j = 0;
	free(dim);
	dim = malloc(ft_strlen(line) * sizeof(char));
	while (ft_isdigit(line[i]) != 0 && line[i])
		dim[j++] = line[i++];
	dim[j] = '\0';
	(*filler)->y = ft_atoi(dim);
	free(str);
	free(dim);
	if (line[i] == ':' && line[i + 1] == '\0')
		return (1);
	exit(0);
}

char		*check_this_line_piece(char *str, int y)
{
	int i;

	i = 0;
	while (str[i] == '.' || str[i] == '*')
		++i;
	if (!str[i] && y == i)
		return (ft_strdup(str));
	exit(0);
}

char		**piece_check(int x, int y)
{
	int		i;
	char	*line;
	char	**tab;

	i = 0;
	tab = malloc((x + 1) * sizeof(char *));
	while (i < x)
	{
		get_next_line(0, &line);
		tab[i] = check_this_line_piece(line, y);
		free(line);
		line = NULL;
		++i;
	}
	tab[i] = NULL;
	return (tab);
}
