/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:25:03 by jocohen           #+#    #+#             */
/*   Updated: 2017/12/06 13:50:16 by tcollard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

size_t	ft_sqrt(size_t nb)
{
	size_t	nb_out;

	if (nb > 0)
	{
		nb_out = 1;
		while (nb_out * nb_out < nb)
		{
			nb_out++;
		}
		return (nb_out);
	}
	return (0);
}
