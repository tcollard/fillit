/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcollard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 13:04:42 by tcollard          #+#    #+#             */
/*   Updated: 2017/12/06 18:10:33 by jocohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../includes/libft.h"

int	ft_error_arg(int argc)
{
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit [path_source_file]\n");
		return (1);
	}
	return (0);
}

int	ft_error_file(int error)
{
	(void)error;
	ft_putstr("error\n");
	return (0);
}
