/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 22:22:24 by tsisadag          #+#    #+#             */
/*   Updated: 2018/05/17 14:28:35 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_tetrimino
{
	char	name;
	char	**square;
	int		**coord;
}				t_tetrimino;

/*
**	parsing
*/

int				open_file(char *file);
char			*str_tetrimino(int fd);
void			set_tetrimino(t_tetrimino *tetri, char *s, char c);
t_tetrimino		*parse(char *s);
void			allocate_coord(t_tetrimino *t);
void			allocate_square(t_tetrimino *t);
void			save_coordinates(t_tetrimino *t, int nb_tet, int nb);

/*
**	validation
*/

int				is_valid_amount(char *s);
int				is_valid1(char *s);
int				is_valid2(char *s);
int				is_valid3(char *s);
int				is_valid(char *s);
int				count_tetrimino(char *s);

/*
**	solve
*/

void			solve(t_tetrimino *t, char **map, int nb_tet);
int				backtrack(t_tetrimino *t, char **map, int nb_tet, int nb);
char			**delete_tetrimino(char **map, char c, int size);
int				is_placed(t_tetrimino *t, char **map, int nb, int *row_col);

/*
**	tools
*/

char			**create_map(int size);
int				ft_mapsize(char **map);
void			error(void);
void			ft_print_map(char **map);
void			ft_putchar(char c);
void			ft_putstr(char *str);

#endif
