/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:50:21 by tsisadag          #+#    #+#             */
/*   Updated: 2018/05/15 20:12:56 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	parse tetrimino
*/

void			set_tetrimino(t_tetrimino *tetri, char *s, char c)
{
	int	i;
	int	row;
	int col;

	i = 0;
	col = 0;
	tetri->name = c;
	allocate_square(tetri);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 5)
		{
			if (s[i] == '#')
				tetri->square[row][col] = c;
			else
				tetri->square[row][col] = s[i];
			col++;
			i++;
		}
		row++;
	}
	allocate_coord(tetri);
}

/*
**	parse tetriminos from string to array of structure
*/

t_tetrimino		*parse(char *s)
{
	int			amount;
	int			i;
	char		c;
	t_tetrimino	*t;

	c = 'A';
	i = 0;
	amount = count_tetrimino(s);
	if (!(t = (t_tetrimino *)malloc(sizeof(t_tetrimino) * (amount + 1))))
		return (NULL);
	while (amount > 0)
	{
		set_tetrimino(t + i, s, c);
		amount--;
		c++;
		i++;
		s += 21;
	}
	return (t);
}

/*
**	save coordinates in structure
*/

void			save_coordinates(t_tetrimino *t, int nb_tet, int nb)
{
	int		row;
	int		col;
	int		r;

	while (++nb < nb_tet)
	{
		row = 0;
		r = 0;
		while (row < 4)
		{
			col = 0;
			while (col < 5 && r < 4)
			{
				if (t[nb].square[row][col] == t[nb].name)
				{
					t[nb].coord[r][0] = row;
					t[nb].coord[r][1] = col;
					r++;
				}
				col++;
			}
			row++;
		}
	}
}
