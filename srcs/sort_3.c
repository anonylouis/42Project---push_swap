/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 07:27:39 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/08 16:35:00 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//increaing !!!!
void	sort_3_a(t_stacks *stacks)
{
	if ((stacks->a)[0] > (stacks->a)[1])
	{
		if ((stacks->a)[0] > (stacks->a)[2])
			ra(stacks);
		sort_2_a(stacks);
	}
	else
	{
		if ((stacks->a)[1] > (stacks->a)[2])
		{
			if ((stacks->a)[0] < (stacks->a)[2])
			{
				ra(stacks);
				sort_2_a(stacks);
			}
			rra(stacks);
		}
	}
}

//decreasing !!!!
void	sort_3_b(t_stacks *stacks)
{
	if ((stacks->b)[0] < (stacks->b)[1])
	{
		if ((stacks->b)[0] < (stacks->b)[2])
			rb(stacks);
		sort_2_b(stacks);
	}
	else
	{
		if ((stacks->b)[1] < (stacks->b)[2])
		{
			if ((stacks->b)[0] > (stacks->b)[2])
			{
				rb(stacks);
				sort_2_b(stacks);
			}
			rrb(stacks);
		}
	}
}
