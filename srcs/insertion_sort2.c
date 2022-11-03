/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:33:36 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/08 16:35:00 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	nb_rb_to_ins(int *tab, int len, int ins)
{
	int	i;
	int	n;

	n = 0;
	i = -1;
	while (++i < len && ins < tab[i])
		n++;
	return (n);
}

int	ft_find_i_max(int *b, int len)
{
	int	i;
	int	i_max;
	int	max;

	if (len == 0)
		return (0);
	i_max = 0;
	max = b[0];
	i = 0;
	while (++i < len)
	{
		if (b[i] > max)
		{
			max = b[i];
			i_max = i;
		}
	}
	return (i_max);
}
