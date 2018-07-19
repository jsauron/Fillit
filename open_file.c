/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsisadag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:38:43 by tsisadag          #+#    #+#             */
/*   Updated: 2018/05/15 20:10:57 by tsisadag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** open file and return file descriptor
*/

int		open_file(char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	return (fd);
}
