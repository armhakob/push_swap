/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:44:07 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/28 14:02:50 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//list utils
t_stack	*ft_stacknew(int data);
t_stack	*ft_stacklast(t_stack *head);
int		ft_stacksize(t_stack *head);
void	ft_stackadd_back(t_stack **stack, t_stack *data);

//check utils
void	checking(int argc, char **argv, t_stack **a);
void	ft_check(char **nums);
void	check_symb(char *s);
t_stack	*check_and_fill(t_stack *a, char **s);
int		check_dup(char **nums);
int		is_number(const char *str);
char	*ft_strjoin_2(char *s1, char *s2);
int		is_sorted(t_stack *a);
void	is_empty_mari(char **nums);

//indexing
void	free_nums(char **nums);
void	ft_swap(int *a, int *b);
int		partition(int *arr, int low, int high);
void	quick_sort(int *arr, int low, int high);
void	find_index(t_stack **a, int *arr, int n);
void	do_indexing(t_stack **a);

//sort under 12
void	sort_3(t_stack **stack_a);
void	chanaparh(t_stack **a, t_stack *nodik);
void	sort_under_12(t_stack **a, t_stack **b, int size);

//butterfly
int		optimizer(int size);
void	pushing(t_stack **a, t_stack **b, int *i, int op);
void	fly_titer(t_stack **b, t_stack *nodik);
void	find_max(t_stack **stack);
void	do_butterfly_detka(t_stack **a, t_stack **b);

//instructions
int		swap(t_stack **stack);
int		push(t_stack **stack1, t_stack **stack2);
int		rotate(t_stack **stack_a);
int		reverse_rotate(t_stack **stack_a);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
