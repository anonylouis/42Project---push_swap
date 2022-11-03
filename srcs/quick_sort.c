/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:39:24 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/08 17:18:45 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	regroup_a(t_stacks *stacks, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		push_a(stacks);
	}
}

static int	separation_a(t_stacks *stacks, int pivot, int n)
{
	int	new_n;
	int	i;

	new_n = 0;
	i = -1;
	while (++i < n)
	{
		if ((stacks->a)[0] > pivot)
			ra(stacks);
		else if ((stacks->a)[0] == pivot)
		{
			push_b(stacks);
			rb(stacks);
		}
		else
		{
			new_n++;
			push_b(stacks);
		}
	}
	return (new_n);
}

static void	finish_rotations_a(t_stacks *stacks, int j, int n, int new_n)
{
	j = ft_min(j, n - new_n);
	if (j == n - new_n)
	{
		while (--j)
			rra(stacks);
	}
	else
	{
		j++;
		while (--j)
			ra(stacks);
	}
}

void	quick_sort_ascending_a(t_stacks *stacks, int n)
{
	int	pivot;
	int	j;
	int	new_n;

	if (n <= 1)
		return ;
	if (n == 2)
		sort_2_a(stacks);
	else
	{
		j = stacks->len_a - n;
		pivot = find_pivot_a(stacks, n);
		new_n = separation_a(stacks, pivot, n);
		finish_rotations_a(stacks, j, n, new_n);
		quick_sort_ascending_a(stacks, n - new_n - 1);
		quick_sort_descending_b(stacks, new_n);
		rrb(stacks);
		push_a(stacks);
		regroup_a(stacks, new_n);
	}
}
