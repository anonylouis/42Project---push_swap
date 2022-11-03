/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:25:39 by marvin            #+#    #+#             */
/*   Updated: 2022/01/08 01:25:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	do_ra_rb(t_stacks *stacks, int nbra, int nbrb)
{
	int	min;
	int	i;

	min = ft_min(nbra, nbrb);
	i = min;
	while (i--)
		rr(stacks);
	if (min == nbrb)
	{
		while (min++ < nbra)
			ra(stacks);
	}
	else
	{
		while (min++ < nbrb)
			rb(stacks);
	}
}

void	do_rra_rrb(t_stacks *stacks, int nbrra, int nbrrb)
{
	int	min;
	int	i;

	min = ft_min(nbrra, nbrrb);
	i = min;
	while (i--)
		rrr(stacks);
	if (min == nbrrb)
	{
		while (min++ < nbrra)
			rra(stacks);
	}
	else
	{
		while (min++ < nbrrb)
			rrb(stacks);
	}
}

void	do_rra_rb(t_stacks *stacks, int nbrra, int nbrb)
{
	while (nbrra--)
		rra(stacks);
	while (nbrb--)
		rb(stacks);
}

void	do_ra_rrb(t_stacks *stacks, int nbra, int nbrrb)
{
	while (nbra--)
		ra(stacks);
	while (nbrrb--)
		rrb(stacks);
}

void	do_n_rb(t_stacks *stacks, int n)
{
	if (n != 0)
		n = n % stacks->len_b;
	if (n <= (stacks->len_b / 2))
	{
		while (n > 0)
		{
			rb(stacks);
			n--;
		}
	}
	else
	{
		n = stacks->len_b - n;
		while (n > 0)
		{
			rrb(stacks);
			n--;
		}
	}
}
