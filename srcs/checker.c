/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalvie <lcalvie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:35:21 by anonylouis        #+#    #+#             */
/*   Updated: 2022/11/03 11:19:35 by lcalvie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc > 1)
	{
		stacks = new_stacks(argc, argv);
		if (stacks == NULL)
			ft_putstr_fd("Error\n", 2);
		else
		{
			if (!read_stdin(stacks))
				ft_putstr_fd("Error\n", 2);
			else
			{
				if (sorted(stacks->a, stacks->len_a) && !stacks->len_b)
					ft_putstr_fd("OK\n", 1);
				else
					ft_putstr_fd("KO\n", 1);
			}
		}
		clear_stacks(stacks);
	}
	return (0);
}
