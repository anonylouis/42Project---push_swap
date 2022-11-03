/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 03:09:53 by marvin            #+#    #+#             */
/*   Updated: 2022/01/08 03:09:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	regroup_b(t_stacks *stacks, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		push_b(stacks);
	}
}

static int	separation_b(t_stacks *stacks, int pivot, int n)
{
	int	new_n;
	int	i;

	new_n = 0;
	i = -1;
	while (++i < n)
	{
		if ((stacks->b)[0] < pivot)
			rb(stacks);
		else if ((stacks->b)[0] == pivot)
		{
			push_a(stacks);
			ra(stacks);
		}
		else
		{
			new_n++;
			push_a(stacks);
		}
	}
	return (new_n);
}

static void	finish_rotations_b(t_stacks *stacks, int j, int n, int new_n)
{
	j = ft_min(j, n - new_n);
	if (j == n - new_n)
	{
		while (--j)
			rrb(stacks);
	}
	else
	{
		j++;
		while (--j)
			rb(stacks);
	}
}

void	quick_sort_descending_b(t_stacks *stacks, int n)
{
	int	pivot;
	int	j;
	int	new_n;

	if (n <= 1)
		return ;
	if (n == 2)
		sort_2_b(stacks);
	else
	{
		j = stacks->len_b - n;
		pivot = find_pivot_b(stacks, n);
		new_n = separation_b(stacks, pivot, n);
		finish_rotations_b(stacks, j, n, new_n);
		quick_sort_ascending_a(stacks, new_n);
		quick_sort_descending_b(stacks, n - new_n - 1);
		rra(stacks);
		push_b(stacks);
		regroup_b(stacks, new_n);
	}
}
