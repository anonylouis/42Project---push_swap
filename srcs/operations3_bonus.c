/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:31:30 by anonylouis        #+#    #+#             */
/*   Updated: 2022/01/08 18:36:25 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_stacks *stacks)
{
	if (stacks->len_a >= 2)
		ft_swap(&((stacks->a)[0]), &((stacks->a)[1]));
}

void	sb(t_stacks *stacks)
{
	if (stacks->len_b >= 2)
		ft_swap(&((stacks->b)[0]), &((stacks->b)[1]));
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
