/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:28:59 by jocohen           #+#    #+#             */
/*   Updated: 2017/11/27 15:51:22 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_fct_tab(int (*ref_tetris[19])(char **, t_tetri *, t_pos, t_pos))
{
	ref_tetris[0] = ref0;
	ref_tetris[1] = ref1;
	ref_tetris[2] = ref2;
	ref_tetris[3] = ref3;
	ref_tetris[4] = ref4;
	ref_tetris[5] = ref5;
	ref_tetris[6] = ref6;
	ref_tetris[7] = ref7;
	ref_tetris[8] = ref8;
	ref_tetris[9] = ref9;
	ref_tetris[10] = ref10;
	ref_tetris[11] = ref11;
	ref_tetris[12] = ref12;
	ref_tetris[13] = ref13;
	ref_tetris[14] = ref14;
	ref_tetris[15] = ref15;
	ref_tetris[16] = ref16;
	ref_tetris[17] = ref17;
	ref_tetris[18] = ref18;
}
