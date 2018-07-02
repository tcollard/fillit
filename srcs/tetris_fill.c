/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 12:58:45 by jocohen           #+#    #+#             */
/*   Updated: 2017/12/06 14:21:29 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

static void	remove_tetris(char **tetris_full, t_tetri *lst)
{
	char	c;
	t_pos	a;

	if (!lst)
		return ;
	if (lst->index < 0)
		lst->index = -(lst->index);
	c = lst->index + 64;
	a.size = ft_strlen(*tetris_full) - 1;
	a.y = a.size;
	while ((int)a.y >= 0)
	{
		a.x = a.size;
		while ((int)a.x >= 0)
		{
			if (tetris_full[a.x][a.y] == c)
				tetris_full[a.x][a.y] = '.';
			a.x -= 1;
		}
		a.y -= 1;
	}
}

static int	the_fall(t_tetri *lst, char **tetris_full, t_pos a)
{
	int		(*ref_tetris[19])(char **, t_tetri *, t_pos, t_pos);
	int		x;

	if (!lst)
		return (0);
	ft_fct_tab(ref_tetris);
	x = ref_tetris[lst->ref](tetris_full, lst, a,
	pass_char(lst->tetri, '.', 1));
	return (x);
}

char		**grow_size(char **tetris_full)
{
	size_t	x;
	size_t	y;

	y = 0;
	x = 0;
	while (tetris_full[x])
		x += 1;
	ft_memdel2(tetris_full);
	if (!(tetris_full = (char **)malloc(sizeof(char *) * (x + 2))))
		return (0);
	while (y < x + 1)
	{
		if (!(*(tetris_full + y) =
					(char *)malloc(sizeof(char ) * (x + 2))))
			return (0);
		y += 1;
	}
	tetris_point_fill(tetris_full, x + 1);
	return (tetris_full);
}

int		tetris_fill(t_tetri *lst, char **tetris_full, t_pos a)
{
	t_pos	b;

	a.size = ft_strlen(*tetris_full);
	if (!lst)
		return (1);
	while (a.y < a.size)
	{
		while (a.x < a.size)
		{
			if (the_fall(lst, tetris_full, a))
			{
				b.x = 0;
				b.y = 0;
				b.size = a.size;
				if (tetris_fill(lst->next, tetris_full, b))
					return (1);
				else
					remove_tetris(tetris_full, lst);
			}
			a.x += 1;
		}
		a.x = 0;
		a.y += 1;
	}
	return (0);
}
