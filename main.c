/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:35:50 by tsisadag          #+#    #+#             */
/*   Updated: 2018/05/15 20:07:50 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	int			fd;
	char		*str_tet;
	int			nb_tet;
	char		**map;
	t_tetrimino *t;

	if (ac == 2)
	{
		if (!(fd = open_file(av[1])))
			error();
		str_tet = str_tetrimino(fd);
		nb_tet = count_tetrimino(str_tet);
		if (is_valid(str_tet))
		{
			t = parse(str_tet);
			map = create_map(2);
			save_coordinates(t, nb_tet, -1);
			solve(t, map, nb_tet);
		}
		else
			error();
	}
	else
		ft_putstr("usage: ./fillit input_file\n");
	return (0);
}
