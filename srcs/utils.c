/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:01:21 by marvin            #+#    #+#             */
/*   Updated: 2022/01/03 17:01:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_atoi(char *str, int *n)
{
	int		i;
	int		negative;
	long	n_long;

	i = 0;
	negative = 0;
	if (str[i] == '-')
	{
		negative = 1;
		i++;
	}
	n_long = 0;
	while (str[i] >= '0' && str[i] <= '9' && n_long <= 2147483648)
	{
		n_long = 10 * n_long + str[i] - '0';
		i++;
	}
	if (negative)
		n_long *= -1;
	if (n_long < (long) INT_MIN
		|| n_long > (long) INT_MAX || (i == 1 && negative))
		return (12);
	*n = (int) n_long;
	return (i);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	ft_abs(int a)
{
	if (a >= 0)
		return (a);
	return (-a);
}
