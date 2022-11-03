/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 15:07:50 by marvin            #+#    #+#             */
/*   Updated: 2021/12/22 15:07:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	count_total_int_str(char *str)
{
	int	n;
	int	tmp;
	int	j;
	int	i;

	n = 0;
	j = 0;
	while (str[j])
	{
		if (str[j] == '-' || (str[j] >= '0' && str[j] <= '9'))
		{
			i = ft_atoi(str + j, &tmp);
			if (i > 11)
				return (0);
			j += i;
			n++;
			if (str[j] == ' ' && str[j + 1])
				j++;
		}
		else
			return (0);
	}
	return (n);
}

int	count_total_int(int argc, char **argv)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (++i < argc)
	{
		j = count_total_int_str(argv[i]);
		if (j == 0)
			return (0);
		n += j;
	}
	return (n);
}
