/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetrimino.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:44:49 by tsisadag          #+#    #+#             */
/*   Updated: 2018/05/15 21:04:42 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	validate correct amount of tetrimino
*/

int		is_valid_amount(char *s)
{
	int		amount;

	amount = count_tetrimino(s);
	if (amount < 1 || amount > 26)
		return (0);
	return (1);
}

/*
** validate correct symbols
*/

int		is_valid1(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

/*
** validate amount of symbols
*/

int		is_valid2(char *s)
{
	int c_hash;
	int c_dot;
	int c_nl;
	int i;

	c_hash = 0;
	c_dot = 0;
	c_nl = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '#')
			c_hash++;
		if (s[i] == '.')
			c_dot++;
		if (s[i] == '\n')
			c_nl++;
		i++;
	}
	if (c_hash % 4 != 0 || c_dot != c_hash / 4 * 12
		|| c_nl != c_hash + c_hash / 4 - 1)
		return (0);
	return (1);
}

/*
** validate shape
*/

int		is_valid3(char *s)
{
	int		i;
	int		sum;
	int		next;

	i = -1;
	while (s[++i])
	{
		next = 21;
		sum = 0;
		while (--next > 0)
		{
			if (s[i] == '#')
			{
				(next < 16 && s[i - 5] == '#') ? sum++ : sum;
				(next > 5 && s[i + 5] == '#') ? sum++ : sum;
				(s[i - 1] == '#') ? sum++ : sum;
				(s[i + 1] == '#') ? sum++ : sum;
			}
			i++;
		}
		if ((sum != 6 && sum != 8) || (s[i] != '\n' && s[i + 1]))
			return (0);
	}
	return (1);
}

/*
** validate everything
*/

int		is_valid(char *s)
{
	if (is_valid_amount(s) && is_valid1(s)
		&& is_valid2(s) && is_valid3(s))
		return (1);
	return (0);
}
