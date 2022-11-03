/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 15:18:44 by anonylouis        #+#    #+#             */
/*   Updated: 2022/01/08 16:35:00 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sorted(int *tab, int len)
{
	int	i;

	if (len < 2)
		return (1);
	i = 0;
	while (++i < len)
	{
		if (tab[i - 1] > tab[i])
			return (0);
	}
	return (1);
}
