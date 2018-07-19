/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 13:58:16 by tsisadag          #+#    #+#             */
/*   Updated: 2018/05/17 14:35:53 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	backtracking algorithm
*/

int		backtrack(t_tetrimino *t, char **map, int nb_tet, int nb)
{
	int row;
	int col;
	int row_col[2];

	if (nb == nb_tet)
		return (1);
	row = 0;
	while (row < ft_mapsize(map))
	{
		row_col[0] = row;
		col = -1;
		while (++col < ft_mapsize(map))
		{
			row_col[1] = col;
			if (is_placed(t, map, nb, row_col))
			{
				if (backtrack(t, map, nb_tet, nb + 1))
					return (1);
				else
					delete_tetrimino(map, t[nb].name, ft_mapsize(map));
			}
		}
		row++;
	}
	return (0);
}

/*
**	solve :)
*/

void	solve(t_tetrimino *t, char **map, int nb_tet)
{
	while (!backtrack(t, map, nb_tet, 0))
		map = create_map(ft_mapsize(map) + 1);
	ft_print_map(map);
}
