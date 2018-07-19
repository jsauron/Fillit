/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tetrimino.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:40:40 by tsisadag          #+#    #+#             */
/*   Updated: 2018/05/15 20:13:43 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	put all tetriminos in string
*/

char	*str_tetrimino(int fd)
{
	int		i;
	int		f;
	char	c;
	char	*s;

	i = 0;
	s = NULL;
	f = read(fd, &c, 1);
	if (f <= 0)
		error();
	if (f == 1)
	{
		if (!(s = (char *)malloc(sizeof(char) * 546)))
			return (NULL);
		while (f)
		{
			s[i] = c;
			f = read(fd, &c, 1);
			i++;
		}
		s[i] = '\0';
	}
	return (s);
}
