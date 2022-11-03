/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:36:38 by lcalvie           #+#    #+#             */
/*   Updated: 2022/01/08 16:35:00 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

//increaing !!!!
void	sort_2_a(t_stacks *stacks)
{
	if ((stacks->a)[0] > (stacks->a)[1])
	{
		ft_putstr_fd("sa\n", 1);
		ft_swap(&((stacks->a)[0]), &((stacks->a)[1]));
	}
}

//decreasing !!!!
void	sort_2_b(t_stacks *stacks)
{
	if ((stacks->b)[0] < (stacks->b)[1])
	{
		ft_putstr_fd("sb\n", 1);
		ft_swap(&((stacks->b)[0]), &((stacks->b)[1]));
	}
}
