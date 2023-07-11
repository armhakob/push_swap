/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   titernik.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 11:34:04 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/27 15:32:14 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	optimizer(int size)
{
	int	log;
	int	sqrt;

	log = 0;
	sqrt = 1;
	while (sqrt < size / sqrt)
		sqrt++;
	while (size)
	{
		size /= 2;
		log++;
	}
	return (sqrt + log - 1);
}

void	fly_titer(t_stack **b, t_stack *nodik)
{
	t_stack	*tmp;
	int		size;
	int		i;

	tmp = *b;
	size = ft_stacksize(*b);
	i = 0;
	while ((*b)->data != nodik->data)
	{
		*b = (*b)->next;
		i++;
	}
	*b = tmp;
	if (i > size / 2)
		while ((*b)->data != nodik->data)
			rrb(b);
	else
		while ((*b)->data != nodik->data)
			rb(b);
}

void	find_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = tmp->data;
	while (*stack)
	{
		if ((*stack)->data > max)
			max = (*stack)->data;
		*stack = (*stack)->next;
	}
	*stack = tmp;
	while (tmp->data != max)
		tmp = tmp->next;
	fly_titer(stack, tmp);
}

void	pushing(t_stack **a, t_stack **b, int *i, int op)
{
	if ((*a)->index <= *i)
	{
		pb(a, b);
		rb(b);
		(*i)++;
	}
	else if ((*a)->index > *i && (*a)->index <= *i + op)
	{
		pb(a, b);
		(*i)++;
	}
	else
		ra(a);
}

void	do_butterfly_detka(t_stack **a, t_stack **b)
{
	int	i;
	int	op;
	int	size;

	i = 0;
	size = ft_stacksize(*a);
	op = optimizer(size);
	while (i < size)
		pushing(a, b, &i, op);
	while (*b)
	{
		find_max(b);
		pa(a, b);
	}
}
