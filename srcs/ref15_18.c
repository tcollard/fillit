/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref15-18.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 16:49:13 by jocohen           #+#    #+#             */
/*   Updated: 2017/12/06 14:16:15 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ref15(char **tetris_full, t_tetri *lst, t_pos a, t_pos b)
{
	if ((int)a.x - 1 >= 0 && a.x + 1 < a.size && a.y + 1 < a.size &&
			tetris_full[a.x][a.y])
		if (tetris_full[a.x][a.y] != 46 || tetris_full[a.x + 1][a.y] != 46
	|| tetris_full[a.x][a.y + 1] != 46 || tetris_full[a.x - 1][a.y + 1] != 46)
			return (0);
		else
		{
			tetris_full[a.x][a.y] = lst->tetri[b.x];
			tetris_full[a.x + 1][a.y] = lst->tetri[b.x];
			tetris_full[a.x][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x - 1][a.y + 1] = lst->tetri[b.x];
			lst->index = -(lst->index);
			return (1);
		}
	else
		return (0);
}

int		ref16(char **tetris_full, t_tetri *lst, t_pos a, t_pos b)
{
	if (a.x + 1 < a.size && a.y + 2 < a.size)
		if (tetris_full[a.x][a.y] != 46 || tetris_full[a.x][a.y + 1] != 46
				|| tetris_full[a.x + 1][a.y + 1] != 46
				|| tetris_full[a.x + 1][a.y + 2] != 46)
			return (0);
		else
		{
			tetris_full[a.x][a.y] = lst->tetri[b.x];
			tetris_full[a.x][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x + 1][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x + 1][a.y + 2] = lst->tetri[b.x];
			lst->index = -(lst->index);
			return (1);
		}
	else
		return (0);
}

int		ref17(char **tetris_full, t_tetri *lst, t_pos a, t_pos b)
{
	if (a.x + 2 < a.size && a.y + 1 < a.size && tetris_full[a.x][a.y])
		if (tetris_full[a.x][a.y] != 46 || tetris_full[a.x + 1][a.y] != 46
				|| tetris_full[a.x + 1][a.y + 1] != 46
				|| tetris_full[a.x + 2][a.y + 1] != 46)
			return (0);
		else
		{
			tetris_full[a.x][a.y] = lst->tetri[b.x];
			tetris_full[a.x + 1][a.y] = lst->tetri[b.x];
			tetris_full[a.x + 1][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x + 2][a.y + 1] = lst->tetri[b.x];
			lst->index = -(lst->index);
			return (1);
		}
	else
		return (0);
}

int		ref18(char **tetris_full, t_tetri *lst, t_pos a, t_pos b)
{
	if ((int)a.x - 1 >= 0 && a.y + 2 < a.size && tetris_full[a.x][a.y])
		if (tetris_full[a.x][a.y] != 46 || tetris_full[a.x][a.y + 1] != 46
				|| tetris_full[a.x - 1][a.y + 1] != 46
				|| tetris_full[a.x - 1][a.y + 2] != 46)
			return (0);
		else
		{
			tetris_full[a.x][a.y] = lst->tetri[b.x];
			tetris_full[a.x][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x - 1][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x - 1][a.y + 2] = lst->tetri[b.x];
			lst->index = -(lst->index);
			return (1);
		}
	else
		return (0);
}
