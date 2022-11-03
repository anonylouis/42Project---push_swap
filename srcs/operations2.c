/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 02:28:49 by marvin            #+#    #+#             */
/*   Updated: 2022/01/08 02:28:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_stacks *stacks)
{
	int	tmp;
	int	i;

	if (stacks->len_a > 1)
	{
		ft_putstr_fd("rra\n", 1);
		tmp = (stacks->a)[stacks->len_a - 1];
		i = stacks->len_a - 1;
		while (--i >= 0)
			(stacks->a)[i + 1] = (stacks->a)[i];
		stacks->a[0] = tmp;
	}
}

void	rrb(t_stacks *stacks)
{
	int	tmp;
	int	i;

	if (stacks->len_b > 1)
	{
		ft_putstr_fd("rrb\n", 1);
		tmp = (stacks->b)[stacks->len_b - 1];
		i = stacks->len_b - 1;
		while (--i >= 0)
			(stacks->b)[i + 1] = (stacks->b)[i];
		stacks->b[0] = tmp;
	}
}

void	rrr(t_stacks *stacks)
{
	int	tmp;
	int	i;

	ft_putstr_fd("rrr\n", 1);
	if (stacks->len_a > 1)
	{
		tmp = (stacks->a)[stacks->len_a - 1];
		i = stacks->len_a - 1;
		while (--i >= 0)
			(stacks->a)[i + 1] = (stacks->a)[i];
		stacks->a[0] = tmp;
	}
	if (stacks->len_b > 1)
	{
		tmp = (stacks->b)[stacks->len_b - 1];
		i = stacks->len_b - 1;
		while (--i >= 0)
			(stacks->b)[i + 1] = (stacks->b)[i];
		stacks->b[0] = tmp;
	}
}
