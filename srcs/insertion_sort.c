/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 03:51:17 by marvin            #+#    #+#             */
/*   Updated: 2022/01/08 03:51:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*reverse_insertion(int *tab_origin, int n)
{
	int	i;
	int	j;
	int	tmp;
	int	*tab;

	tab = malloc(sizeof(int) * n);
	if (tab == NULL)
		return (NULL);
	i = -1;
	while (++i < n)
		tab[i] = tab_origin[i];
	i = -1;
	while (++i < n)
	{
		tmp = tab[i];
		j = i - 1;
		while (j >= 0 && tmp > tab[j])
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = tmp;
	}
	return (tab);
}

int	find_min_rb_rrb_ra_rra(t_stacks *stacks, int nbra, int nbrb)
{
	int	nbrra;
	int	nbrrb;
	int	min;

	if (stacks->len_a > 0)
		nbra = nbra % stacks->len_a;
	if (stacks->len_b > 0)
		nbrb = nbrb % stacks->len_b;
	nbrra = stacks->len_a - nbra;
	nbrrb = stacks->len_b - nbrb;
	min = ft_min(ft_max(nbra, nbrb), ft_max(nbrra, nbrrb));
	min = ft_min(min, nbra + nbrrb);
	min = ft_min(min, nbrra + nbrb);
	return (min);
}

void	do_min_rb_rrb_ra_rra(t_stacks *stacks, int nbra, int nbrb)
{
	int	min;
	int	nbrra;
	int	nbrrb;

	if (stacks->len_a > 0)
		nbra = nbra % stacks->len_a;
	if (stacks->len_b > 0)
		nbrb = nbrb % stacks->len_b;
	nbrra = stacks->len_a - nbra;
	nbrrb = stacks->len_b - nbrb;
	min = find_min_rb_rrb_ra_rra(stacks, nbra, nbrb);
	if (min == ft_max(nbra, nbrb))
		do_ra_rb(stacks, nbra, nbrb);
	else if (min == ft_max(nbrra, nbrrb))
		do_rra_rrb(stacks, nbrra, nbrrb);
	else if (min == nbra + nbrrb)
		do_ra_rrb(stacks, nbra, nbrrb);
	else
		do_rra_rb(stacks, nbrra, nbrb);
}

int	find_best_insertion(t_stacks *stacks)
{
	int	i;
	int	i_min;
	int	nb_move_min;
	int	nb_move;
	int	*tab;

	nb_move_min = -1;
	i_min = -1;
	tab = reverse_insertion(stacks->b, stacks->len_b);
	if (tab == NULL)
		return (-1);
	i = -1;
	while (++i < stacks->len_a)
	{
		nb_move = nb_rb_to_ins(tab, stacks->len_b, (stacks->a)[i]);
		nb_move += ft_find_i_max(stacks->b, stacks->len_b);
		nb_move = find_min_rb_rrb_ra_rra(stacks, i, nb_move);
		if (nb_move < nb_move_min || nb_move_min == -1)
		{
			nb_move_min = nb_move;
			i_min = i;
		}
	}
	free(tab);
	return (i_min);
}

int	insertion_sort(t_stacks *stacks)
{
	int	i;
	int	rb;
	int	*tab;

	while (stacks->len_a > 0)
	{
		i = find_best_insertion(stacks);
		tab = reverse_insertion(stacks->b, stacks->len_b);
		if (tab == NULL || i < 0)
			return (0);
		rb = ft_find_i_max(stacks->b, stacks->len_b);
		rb += nb_rb_to_ins(tab, stacks->len_b, (stacks->a)[i]);
		do_min_rb_rrb_ra_rra(stacks, i, rb);
		push_b(stacks);
		free(tab);
	}
	do_n_rb(stacks, ft_find_i_max(stacks->b, stacks->len_b));
	while (stacks->len_b)
		push_a(stacks);
	return (1);
}
