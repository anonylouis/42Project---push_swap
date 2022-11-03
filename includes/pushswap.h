/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 14:42:25 by marvin            #+#    #+#             */
/*   Updated: 2021/12/22 14:42:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}		t_stacks;

// STACKS FUNCTIONS
t_stacks	*new_stacks(int argc, char **argv);
void		clear_stacks(t_stacks *stacks);

//ARGUMENTS
int			count_total_int(int argc, char **argv);
int			fill_tabs(int argc, char **argv, int *a);

//OPERATIONS
void		push_a(t_stacks *stacks);
void		push_b(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

// DO ROTATIONS
void		do_ra_rb(t_stacks *stacks, int nbra, int nbrb);
void		do_rra_rrb(t_stacks *stacks, int nbrra, int nbrrb);
void		do_rra_rb(t_stacks *stacks, int nbrra, int nbrb);
void		do_ra_rrb(t_stacks *stacks, int nbra, int nbrrb);
void		do_n_rb(t_stacks *stacks, int n);

//QUICK SORT
int			find_pivot_a(t_stacks *stacks, int n);
int			find_pivot_b(t_stacks *stacks, int n);
void		quick_sort_ascending_a(t_stacks *stacks, int n);
void		quick_sort_descending_b(t_stacks *stacks, int n);

//SORT 2
void		sort_2_a(t_stacks *stacks);
void		sort_2_b(t_stacks *stacks);

// SORT 3
void		sort_3_a(t_stacks *stacks);
void		sort_3_b(t_stacks *stacks);

//QUICK SORT
int			find_pivot_a(t_stacks *stacks, int n);
int			find_pivot_b(t_stacks *stacks, int n);
void		quick_sort_ascending_a(t_stacks *stacks, int n);
void		quick_sort_descending_b(t_stacks *stacks, int n);

// INSERTION SORT
int			nb_rb_to_ins(int *tab, int len, int ins);
int			ft_find_i_max(int *b, int len);
int			insertion_sort(t_stacks *stacks);

// PRINT 
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);

//UTILS
int			sorted(int *tab, int len);
int			ft_atoi(char *str, int *n);
void		ft_swap(int *a, int *b);
int			ft_min(int a, int b);
int			ft_max(int a, int b);
int			ft_abs(int a);

//CHECKER
int			read_stdin(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *ss);

#endif
