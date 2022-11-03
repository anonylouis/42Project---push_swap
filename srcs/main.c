/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:42:19 by marvin            #+#    #+#             */
/*   Updated: 2021/12/22 14:42:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc > 1)
	{
		stacks = new_stacks(argc, argv);
		if (stacks != NULL)
		{
			if (!sorted(stacks->a, stacks->len_a))
			{
				if (stacks->len_a == 3)
					sort_3_a(stacks);
				else if (stacks->len_a < 8)
					quick_sort_ascending_a(stacks, stacks->len_a);
				else
					if (!insertion_sort(stacks))
						ft_putstr_fd("Error\n", 2);
			}
		}
		else
			ft_putstr_fd("Error\n", 2);
		clear_stacks(stacks);
	}
	return (0);
}
