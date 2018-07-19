/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 23:24:43 by jsauron           #+#    #+#             */
/*   Updated: 2018/05/17 14:48:31 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

/*
**	if error occurs, exit program
*/

void	error(void)
{
	ft_putstr("error\n");
	exit(0);
}

/*
**	calculate size of map
*/

int		ft_mapsize(char **map)
{
	int col;

	col = 0;
	while (map[0][col] != '\n')
		col++;
	return (col);
}

/*
**  print map and exit the program
*/

void	ft_print_map(char **map)
{
	int row;

	row = 0;
	while (row < ft_mapsize(map))
	{
		ft_putstr(map[row]);
		row++;
	}
	exit(0);
}
