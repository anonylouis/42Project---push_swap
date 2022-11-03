/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonylouis <anonylouis@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:50:28 by anonylouis        #+#    #+#             */
/*   Updated: 2022/01/08 19:09:53 by anonylouis       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	aplly_cmd_p(t_stacks *stacks)
{
	int		ret;
	char	buffer[2];

	ret = read(0, buffer, 2);
	if (ret != 2 || buffer[1] != '\n')
		return (0);
	if (buffer[0] == 'a')
		push_a(stacks);
	else if (buffer[0] == 'b')
		push_b(stacks);
	else
		return (0);
	return (1);
}

int	aplly_cmd_s(t_stacks *stacks)
{
	int		ret;
	char	buffer[2];

	ret = read(0, buffer, 2);
	if (ret != 2 || buffer[1] != '\n')
		return (0);
	if (buffer[0] == 'a')
		sa(stacks);
	else if (buffer[0] == 'b')
		sb(stacks);
	else if (buffer[0] == 's')
		ss(stacks);
	else
		return (0);
	return (1);
}

int	aplly_cmd_rr(t_stacks *stacks, char c)
{
	int		ret;
	char	buffer[2];

	ret = read(0, buffer, 1);
	if (ret != 1 || buffer[0] != '\n')
		return (0);
	if (c == 'a')
		rra(stacks);
	else if (c == 'b')
		rrb(stacks);
	else if (c == 'r')
		rrr(stacks);
	else
		return (0);
	return (1);
}

int	aplly_cmd_r(t_stacks *stacks)
{
	int		ret;
	char	buffer[2];

	ret = read(0, buffer, 2);
	if (ret != 2)
		return (0);
	if (buffer[1] == '\n')
	{
		if (buffer[0] == 'a')
			ra(stacks);
		else if (buffer[0] == 'b')
			rb(stacks);
		else if (buffer[0] == 'r')
			rr(stacks);
		else
			return (0);
	}
	else if (buffer[0] == 'r')
		return (aplly_cmd_rr(stacks, buffer[1]));
	else
		return (0);
	return (1);
}

int	read_stdin(t_stacks *stacks)
{
	int		ret;
	char	buffer[3];

	ret = 1;
	while (ret)
	{
		ret = read(0, buffer, 1);
		if (ret > 0)
		{
			if (buffer[0] == 's')
				ret = aplly_cmd_s(stacks);
			else if (buffer[0] == 'p')
				ret = aplly_cmd_p(stacks);
			else if (buffer[0] == 'r')
				ret = aplly_cmd_r(stacks);
			else
				return (0);
			if (ret == 0)
				return (0);
		}
	}
	return (1);
}
