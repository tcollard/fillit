/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:15:54 by jocohen           #+#    #+#             */
/*   Updated: 2017/12/06 14:51:57 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include <stdio.h>

void			tetris_point_fill(char **tetris_full, size_t size)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			tetris_full[x][y] = '.';
			y += 1;
		}
		tetris_full[x][y] = 0;
		x += 1;
	}
	tetris_full[x] = 0;
}

static char		**tetris_initialize(char **tetris, size_t x)
{
	size_t	y;

	y = 0;
	if (!(tetris = (char **)malloc(sizeof(char *) * (x + 1))))
		return (0);
	while (y < x)
	{
		if (!(*(tetris + y) = (char *)malloc(sizeof(char ) * (x + 1))))
			return (0);
		y += 1;
	}
	return (tetris);
}

char			**tetris(t_tetri *lst, t_pos a)
{
	char	**tetris_full;
	size_t	size;

	size = ft_sqrt(a.size * 4);
	tetris_full = 0;
	if (!(tetris_full = tetris_initialize(tetris_full, size)))
		return (0);
	tetris_point_fill(tetris_full, size);
	while (!tetris_fill(lst, tetris_full, a))
	{
		if (!(tetris_full = grow_size(tetris_full)))
			return (0);
		a.x = 0;
		a.y = 0;
	}
	return (tetris_full);
}
