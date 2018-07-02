/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_display.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:04:58 by jocohen           #+#    #+#             */
/*   Updated: 2017/11/27 15:54:21 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	tetris_display(char **tetris)
{
	t_pos	pos;
	size_t	max;

	pos.x = 0;
	pos.y = 0;
	max = 0;
	while (tetris[max])
		max += 1;
	while (pos.y != max)
	{
		ft_putchar(tetris[pos.x][pos.y]);
		if (pos.x + 1 == max)
		{
			ft_putchar('\n');
			pos.x = 0;
			pos.y += 1;
		}
		else
			pos.x += 1;
	}
}
