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

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct		s_filler
{
	char			**map;
	int				turn;
	int				x;
	int				y;
	char			**piece;
	char			**old;
	int				x_dec;
	int				y_dec;
	int				x_answer;
	int				y_answer;
	int				count;
	int				letter;
	int				opp_letter;
	int				my_cool;
	char			order;
}					t_filler;

int					check_it(char ***map, char ***piece);
void				map_initialize(t_filler **filler, char *str, int i, int j);
char				**map_check(t_filler **filler);
int					first_coord(t_filler **filler);
int					can_i(t_filler **filler, int x, int y, char **tab);
void				check_map_test(char **tab, int x, int y, t_filler **filler);
void				is_cool(t_filler **filler, int x, int y, char **map);
void				replace_map(char **map, int x, int y, t_filler **filler);
char				**copy_map(char **map);
void				free_tab(char ***tab);
void				count_it(char **tab, t_filler *filler,\
					int me, int other);
int					piece_initialize(t_filler **filler, \
					char *line, int i, int j);
char				**piece_check(int x, int y);
#endif
