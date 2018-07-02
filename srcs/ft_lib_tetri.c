/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 15:23:01 by tcollard          #+#    #+#             */
/*   Updated: 2017/12/11 13:41:53 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

static char		**ft_lib_tetri_fill(char **lib_tetri)
{
	lib_tetri[0] = "......##..##....";
	lib_tetri[1] = "........####....";
	lib_tetri[2] = "#...#...#...#...";
	lib_tetri[3] = ".#..###.........";
	lib_tetri[4] = "#...##..#.......";
	lib_tetri[5] = ".#..##...#......";
	lib_tetri[6] = "###..#..........";
	lib_tetri[7] = "#...#...##......";
	lib_tetri[8] = "..#.###.........";
	lib_tetri[9] = "##...#...#......";
	lib_tetri[10] = "###.#...........";
	lib_tetri[11] = "...#...#..##....";
	lib_tetri[12] = "#...###.........";
	lib_tetri[13] = "##..#...#.......";
	lib_tetri[14] = "###...#.........";
	lib_tetri[15] = ".##.##..........";
	lib_tetri[16] = "#...##...#......";
	lib_tetri[17] = "##...##.........";
	lib_tetri[18] = ".#..##..#.......";
	lib_tetri[19] = 0;
	return (lib_tetri);
}

char			**ft_lib_tetri_init(void)
{
	char	**lib_tetri;
	int		i;

	if (!(lib_tetri = (char **)malloc(sizeof(char *) * 20)))
		return (NULL);
	i = 0;
	return (ft_lib_tetri_fill(lib_tetri));
}
