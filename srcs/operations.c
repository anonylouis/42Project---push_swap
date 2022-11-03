/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 22:29:27 by marvin            #+#    #+#             */
/*   Updated: 2022/01/03 22:29:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_b(t_stacks *stacks)
{
	int	i;

	if (stacks->len_a)
	{
		ft_putstr_fd("pb\n", 1);
		i = stacks->len_b;
		while (--i >= 0)
			(stacks->b)[i + 1] = (stacks->b)[i];
		(stacks->b)[0] = (stacks->a)[0];
		i = -1;
		while (++i < (stacks->len_a - 1))
			(stacks->a)[i] = (stacks->a)[i + 1];
		stacks->len_a = stacks->len_a - 1;
		stacks->len_b = stacks->len_b + 1;
	}
}

void	push_a(t_stacks *stacks)
{
	int	i;

	if (stacks->len_b)
	{
		ft_putstr_fd("pa\n", 1);
		i = stacks->len_a;
		while (--i >= 0)
			(stacks->a)[i + 1] = (stacks->a)[i];
		(stacks->a)[0] = (stacks->b)[0];
		i = -1;
		while (++i < (stacks->len_b - 1))
			(stacks->b)[i] = (stacks->b)[i + 1];
		stacks->len_b = stacks->len_b - 1;
		stacks->len_a = stacks->len_a + 1;
	}
}

void	ra(t_stacks *stacks)
{
	int	tmp;
	int	i;

	if (stacks->len_a > 1)
	{
		ft_putstr_fd("ra\n", 1);
		tmp = (stacks->a)[0];
		i = -1;
		while (++i < ((stacks->len_a) - 1))
			(stacks->a)[i] = (stacks->a)[i + 1];
		stacks->a[stacks->len_a - 1] = tmp;
	}
}

void	rb(t_stacks *stacks)
{
	int	tmp;
	int	i;

	if (stacks->len_b > 1)
	{
		ft_putstr_fd("rb\n", 1);
		tmp = (stacks->b)[0];
		i = -1;
		while (++i < ((stacks->len_b) - 1))
			(stacks->b)[i] = (stacks->b)[i + 1];
		stacks->b[stacks->len_b - 1] = tmp;
	}
}

void	rr(t_stacks *stacks)
{
	int	tmp;
	int	i;

	ft_putstr_fd("rr\n", 1);
	if (stacks->len_a > 1)
	{
		tmp = (stacks->a)[0];
		i = -1;
		while (++i < ((stacks->len_a) - 1))
			(stacks->a)[i] = (stacks->a)[i + 1];
		stacks->a[stacks->len_a - 1] = tmp;
	}
	if (stacks->len_b > 1)
	{
		tmp = (stacks->b)[0];
		i = -1;
		while (++i < ((stacks->len_b) - 1))
			(stacks->b)[i] = (stacks->b)[i + 1];
		stacks->b[stacks->len_b - 1] = tmp;
	}
}
