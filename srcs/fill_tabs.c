/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:52:57 by marvin            #+#    #+#             */
/*   Updated: 2022/01/03 19:52:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_in_tab(int a, int *tab, int n)
{
	int	i;

	i = -1;
	while (++i < n)
	{
		if (a == tab[i])
			return (1);
	}
	return (0);
}

static int	fill_tab_since_n(char *str, int *tab, int n)
{
	int	j;
	int	i;

	j = 0;
	while (str[j])
	{
		i = ft_atoi(str + j, &(tab[n]));
		if (is_in_tab(tab[n], tab, n))
			return (0);
		n++;
		j += i;
		if (str[j] == ' ' && str[j + 1])
			j++;
	}
	return (n);
}

int	fill_tabs(int argc, char **argv, int *a)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (++i < argc)
	{
		n = fill_tab_since_n(argv[i], a, n);
		if (!n)
			return (0);
	}
	return (1);
}
