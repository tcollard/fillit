/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:26:12 by tcollard          #+#    #+#             */
/*   Updated: 2017/12/11 14:03:17 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

t_tetri	*ft_tetri_new(char *str, int *index)
{
	t_tetri	*new;

	if (!(new = (t_tetri *)malloc(sizeof(t_tetri))))
		return (NULL);
	*index += 1;
	if (!str)
	{
		new->tetri = NULL;
		new->next = NULL;
		new->ref = 0;
		new->index = 0;
	}
	else if ((new->ref = ft_cmp_tetri(str)) == -1)
		return (NULL);
	else
		str = ft_strreplace(ft_del_char(str), *index);
	new->tetri = str;
	new->next = NULL;
	new->index = *index;
	return (new);
}

t_tetri	*ft_fill_tetri(char *buf, int *index)
{
	t_tetri	*begin;
	char	*str;
	int		i;

	begin = NULL;
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	i = 0;
	while (buf[i])
	{
		if (buf[i] != '\n' || buf[i + 1] != '\n')
			str[i] = buf[i];
		else
			break ;
		i++;
	}
	str[i] = '\0';
	if ((begin = ft_tetri_new(str, index)) == NULL)
		return (NULL);
	if (buf[i])
		if (ft_lst_tetri(begin, (char *)(buf + (i + 2)), index) == NULL)
			return (NULL);
	free(str);
	return (begin);
}

void	*ft_lst_tetri(t_tetri *begin, char *buf, int *index)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = -1;
	if (!(str = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	while (buf[++i])
		if (buf[i] != '\n' || buf[i - 1] != '\n')
			str[j++] = buf[i];
		else
		{
			str[j] = '\0';
			if (ft_tetri_push_back(begin, ft_tetri_new(str, index))
					== NULL || !str)
				return (NULL);
			j = 0;
		}
	str[j] = '\0';
	if (str)
		if (ft_tetri_push_back(begin, ft_tetri_new(str, index)) == NULL)
			return (NULL);
	free(str);
	return ((void *)1);
}

void	*ft_tetri_push_back(t_tetri *begin, t_tetri *new)
{
	t_tetri	*tmp;

	if (!begin || !new)
		return (NULL);
	tmp = begin;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
	return ((void *)1);
}

size_t	ft_nb_tetris(t_tetri *lst)
{
	t_tetri	*tmp;
	size_t	nb;

	nb = 0;
	tmp = lst;
	while (tmp->next)
	{
		nb += 1;
		tmp = tmp->next;
	}
	nb += 1;
	return (nb);
}
