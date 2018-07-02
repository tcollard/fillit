/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:27:57 by tcollard          #+#    #+#             */
/*   Updated: 2017/12/07 13:43:02 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

int	main(int argc, char **argv)
{
	char	**tetris_tab;
	t_tetri	*lst;
	t_pos	a;
	t_tetri	*begin;

	a.x = 0;
	a.y = 0;
	if (ft_error_arg(argc) == 1)
		return (0);
	if (!(lst = ft_read_src(argv[1])))
		return (0);
	begin = lst;
	a.size = ft_nb_tetris(lst);
	if (!(tetris_tab = tetris(lst, a)))
		return (ft_error_file(3));
	tetris_display(tetris_tab);
	ft_memdel2(tetris_tab);
	ft_lstclear(&begin);
	return (0);
}
