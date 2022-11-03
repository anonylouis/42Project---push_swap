/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:30:55 by marvin            #+#    #+#             */
/*   Updated: 2021/12/22 15:30:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stacks	*new_stacks(int argc, char **argv)
{
	t_stacks	*stacks;
	int			n;

	stacks = malloc(sizeof(t_stacks));
	if (stacks == NULL)
		return (NULL);
	n = count_total_int(argc, argv);
	stacks->a = malloc(sizeof(int) * n);
	if (n == 0 || stacks->a == NULL)
	{
		free(stacks->a);
		free(stacks);
		return (NULL);
	}
	stacks->b = malloc(sizeof(int) * n);
	if (!(stacks->b) || !fill_tabs(argc, argv, stacks->a))
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks);
		return (NULL);
	}
	stacks->len_a = n;
	stacks->len_b = 0;
	return (stacks);
}

void	clear_stacks(t_stacks *stacks)
{
	if (stacks != NULL)
	{
		free(stacks->a);
		free(stacks->b);
		free(stacks);
	}
}
