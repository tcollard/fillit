/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref0-4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:55:07 by jocohen           #+#    #+#             */
/*   Updated: 2017/12/06 14:14:29 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ref0(char **tetris_full, t_tetri *lst, t_pos a, t_pos b)
{
	if (a.x + 1 < a.size && a.y + 1 < a.size && tetris_full[a.x][a.y])
		if (tetris_full[a.x][a.y] != 46 || tetris_full[a.x + 1][a.y] != 46
	|| tetris_full[a.x][a.y + 1] != 46 || tetris_full[a.x + 1][a.y + 1] != 46)
			return (0);
		else
		{
			tetris_full[a.x][a.y] = lst->tetri[b.x];
			tetris_full[a.x + 1][a.y] = lst->tetri[b.x];
			tetris_full[a.x][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x + 1][a.y + 1] = lst->tetri[b.x];
			lst->index = -(lst->index);
			return (1);
		}
	else
		return (0);
}

int		ref1(char **tetris_full, t_tetri *lst, t_pos a, t_pos b)
{
	if (a.x + 3 < a.size && tetris_full[a.x][a.y])
		if (tetris_full[a.x][a.y] != 46 || tetris_full[a.x + 1][a.y] != 46
	|| tetris_full[a.x + 2][a.y] != 46 || tetris_full[a.x + 3][a.y] != 46)
			return (0);
		else
		{
			tetris_full[a.x][a.y] = lst->tetri[b.x];
			tetris_full[a.x + 1][a.y] = lst->tetri[b.x];
			tetris_full[a.x + 2][a.y] = lst->tetri[b.x];
			tetris_full[a.x + 3][a.y] = lst->tetri[b.x];
			lst->index = -(lst->index);
			return (1);
		}
	else
		return (0);
}

int		ref2(char **tetris_full, t_tetri *lst, t_pos a, t_pos b)
{
	if (a.y + 3 < a.size && tetris_full[a.x][a.y])
		if (tetris_full[a.x][a.y] != 46 || tetris_full[a.x][a.y + 1] != 46
	|| tetris_full[a.x][a.y + 2] != 46 || tetris_full[a.x][a.y + 3] != 46)
			return (0);
		else
		{
			tetris_full[a.x][a.y] = lst->tetri[b.x];
			tetris_full[a.x][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x][a.y + 2] = lst->tetri[b.x];
			tetris_full[a.x][a.y + 3] = lst->tetri[b.x];
			lst->index = -(lst->index);
			return (1);
		}
	else
		return (0);
}

int		ref3(char **tetris_full, t_tetri *lst, t_pos a, t_pos b)
{
	if ((int)a.x - 1 >= 0 && a.x + 1 < a.size && a.y + 1 < a.size &&
			tetris_full[a.x][a.y])
		if (tetris_full[a.x][a.y] != 46 ||
	tetris_full[a.x - 1][a.y + 1] != 46 || tetris_full[a.x][a.y + 1] != 46
				|| tetris_full[a.x + 1][a.y + 1] != 46)
			return (0);
		else
		{
			tetris_full[a.x][a.y] = lst->tetri[b.x];
			tetris_full[a.x - 1][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x + 1][a.y + 1] = lst->tetri[b.x];
			lst->index = -(lst->index);
			return (1);
		}
	else
		return (0);
}

int		ref4(char **tetris_full, t_tetri *lst, t_pos a, t_pos b)
{
	if (a.x + 1 < a.size && a.y + 2 < a.size && tetris_full[a.x][a.y])
		if (tetris_full[a.x][a.y] != 46 || tetris_full[a.x][a.y + 1] != 46
	|| tetris_full[a.x][a.y + 2] != 46 || tetris_full[a.x + 1][a.y + 1] != 46)
			return (0);
		else
		{
			tetris_full[a.x][a.y] = lst->tetri[b.x];
			tetris_full[a.x][a.y + 1] = lst->tetri[b.x];
			tetris_full[a.x][a.y + 2] = lst->tetri[b.x];
			tetris_full[a.x + 1][a.y + 1] = lst->tetri[b.x];
			lst->index = -(lst->index);
			return (1);
		}
	else
		return (0);
}
