/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 17:17:57 by tcollard          #+#    #+#             */
/*   Updated: 2017/12/11 13:47:06 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

static void	plur_memdel(void **s, void **s2, void **s3, void **s4)
{
	ft_memdel(s);
	ft_memdel(s2);
	ft_memdel(s3);
	ft_memdel(s4);
}

char		*ft_strctrim(char *s, char c)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == c)
		i++;
	j = i;
	while (s[j])
		j++;
	len = j - 1;
	while (s[len] == c && len)
		len--;
	if (!((!len) ? (str = ft_strnew(0)) :
				(str = ft_strnew((len - i) + 1))))
		if (!str)
			return (NULL);
	j = 0;
	while (i < len + 1 && len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

char		*ft_strreplace(char *str, int index)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = index - 1 + 'A';
		i++;
	}
	return (str);
}

int			ft_cmp_tetri(char *str)
{
	int		i;
	char	*s;
	char	**lib_tetri;
	char	*s2;
	char	*s3;

	i = 0;
	lib_tetri = ft_lib_tetri_init();
	s = ft_del_char(str);
	s2 = ft_strctrim(s, '.');
	while (i < 19)
	{
		s3 = ft_strctrim(lib_tetri[i], '.');
		if (ft_strcmp(s2, s3) == 0)
		{
			plur_memdel((void **)&s2, (void **)&s3, (void **)&lib_tetri,
			(void **)&s);
			return (i);
		}
		ft_memdel((void **)&s3);
		i++;
	}
	plur_memdel((void **)&s2, (void **)&s3, (void **)&lib_tetri, (void **)&s);
	return (-1);
}

char		*ft_del_char(char *str)
{
	int		i;
	int		j;
	char	*s;

	s = (char *)malloc(sizeof(char) * 17);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != '\n')
		{
			s[j] = str[i];
			j++;
		}
		i++;
	}
	s[j] = '\0';
	return (s);
}
