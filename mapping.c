/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 22:02:30 by tsisadag          #+#    #+#             */
/*   Updated: 2018/05/15 20:10:33 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** create map and malloc max size of map
*/

char	**create_map(int size)
{
	int		row;
	int		col;
	char	**map;

	row = 0;
	if (!(map = (char **)malloc(sizeof(char **) * (26 * 27 * 16))))
		return (NULL);
	while (row < 26 * 26)
	{
		if (!(map[row] = (char *)malloc(sizeof(char *) * (26 * 27 * 16))))
			return (NULL);
		row++;
	}
	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
			map[row][col++] = '.';
		map[row++][col] = '\n';
	}
	return (map);
}
