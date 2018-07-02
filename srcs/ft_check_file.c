/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:05:39 by tcollard          #+#    #+#             */
/*   Updated: 2017/12/11 14:15:39 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

int			ft_check_nb_char(char *buf)
{
	int	i;
	int nb_char;

	i = 0;
	while (buf[i])
	{
		nb_char = 0;
		while (buf[i] != '\n')
		{
			nb_char++;
			i++;
		}
		if (nb_char != 4 && buf[i - 1] != '\n')
			return (1);
		i++;
	}
	return (0);
}

int			ft_check_nb_line(char *buf)
{
	int	i;
	int	nb_line;

	i = 0;
	nb_line = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' && buf[i - 1] != '\n')
			nb_line++;
		if (((buf[i] == '\n' && buf[i - 1] == '\n') || (buf[i] == '\n'
			&& !buf[i + 1])) && nb_line != 4)
			return (1);
		else if (buf[i] == '\n' && buf[i - 1] == '\n')
			nb_line = 0;
		i++;
	}
	return (0);
}

t_tetri		*ft_check_is_tetri(char *buf)
{
	t_tetri	*begin;
	int		index;

	if (ft_check_nb_char(buf) == 1 || ft_check_nb_line(buf) == 1)
	{
		ft_error_file(2);
		return (NULL);
	}
	index = 0;
	if ((begin = ft_fill_tetri(buf, &index)) == NULL)
	{
		ft_lstclear(&begin);
		ft_error_file(4);
		return (NULL);
	}
	return (begin);
}

t_tetri		*ft_read_src(char *pathname)
{
	int		fd;
	int		size;
	char	buf[1000];
	t_tetri	*lst;

	size = 1000;
	fd = open(pathname, O_RDONLY);
	if (fd == -1)
	{
		ft_error_file(1);
		return (NULL);
	}
	while (size == 1000)
	{
		size = read(fd, buf, 999);
		buf[size] = '\0';
		if (!(lst = ft_check_is_tetri(buf)))
			return (0);
		size++;
	}
	close(fd);
	return (lst);
}

void		ft_lstclear(t_tetri **begin)
{
	t_tetri	*tmp;

	while (*begin)
	{
		ft_memdel((void**)&(*begin)->tetri);
		tmp = *begin;
		*begin = (*begin)->next;
		free(tmp);
	}
}
