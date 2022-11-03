/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 08:49:12 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/08 16:35:00 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_pivot_a(t_stacks *stacks, int n)
{
	int	n_med;
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		n_med = 0;
		j = -1;
		while (++j < n)
		{
			if ((stacks->a)[j] < (stacks->a)[i])
				n_med++;
		}
		if (n_med == n / 2)
			return ((stacks->a)[i]);
	}
	return ((stacks->a)[0]);
}

int	find_pivot_b(t_stacks *stacks, int n)
{
	int	n_med;
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		n_med = 0;
		j = -1;
		while (++j < n)
		{
			if ((stacks->b)[j] < (stacks->b)[i])
				n_med++;
		}
		if (n_med == n / 2)
			return ((stacks->b)[i]);
	}
	return ((stacks->b)[0]);
}
