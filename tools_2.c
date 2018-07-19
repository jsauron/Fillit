/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:43:03 by tsisadag          #+#    #+#             */
/*   Updated: 2018/05/17 14:49:00 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** count number of tetriminos; use only after validation
*/

int		count_tetrimino(char *s)
{
	int i;
	int counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] == '#')
			counter++;
		i++;
	}
	return (counter / 4);
}

/*
**	check if tetrimino is successfully placed
*/

int		is_placed(t_tetrimino *t, char **map, int nb, int *row_col)
{
	int diffr;
	int diffc;

	diffr = row_col[0] - t[nb].coord[0][0];
	diffc = row_col[1] - t[nb].coord[0][1];
	if (map[row_col[0]][row_col[1]] == '.' &&
			map[t[nb].coord[1][0] + diffr][t[nb].coord[1][1] + diffc] == '.' &&
			map[t[nb].coord[2][0] + diffr][t[nb].coord[2][1] + diffc] == '.' &&
			map[t[nb].coord[3][0] + diffr][t[nb].coord[3][1] + diffc] == '.')
	{
		map[row_col[0]][row_col[1]] = t[nb].name;
		map[t[nb].coord[1][0] + diffr][t[nb].coord[1][1] + diffc] = t[nb].name;
		map[t[nb].coord[2][0] + diffr][t[nb].coord[2][1] + diffc] = t[nb].name;
		map[t[nb].coord[3][0] + diffr][t[nb].coord[3][1] + diffc] = t[nb].name;
		return (1);
	}
	return (0);
}

/*
**	malloc coordinates tab
*/

void	allocate_coord(t_tetrimino *t)
{
	int row;

	row = 0;
	t->coord = (int **)malloc(sizeof(int **) * 4);
	while (row < 4)
	{
		t->coord[row] = (int *)malloc(sizeof(int *) * 2);
		row++;
	}
}

/*
**	malloc tetrimino square in structure
*/

void	allocate_square(t_tetrimino *t)
{
	int row;

	row = 0;
	t->square = (char **)malloc(sizeof(char **) * 4);
	while (row < 4)
	{
		t->square[row] = (char *)malloc(sizeof(char *) * 5);
		row++;
	}
}

/*
**  delete one tetrimino from map
*/

char	**delete_tetrimino(char **map, char c, int size)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			if (map[row][col] == c)
				map[row][col] = '.';
			col++;
		}
		row++;
	}
	return (map);
}
