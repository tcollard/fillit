/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:04:37 by jocohen           #+#    #+#             */
/*   Updated: 2017/11/28 16:04:52 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_pos	pass_char(char *tetris, char c, int equal)
{
	t_pos	a;

	a.x = 0;
	a.y = 0;
	if (!equal)
		while (tetris[a.x] != c)
			a.x += 1;
	else
	{
		while (tetris[a.x] == c)
			a.x += 1;
	}
	return (a);
}
