/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:14:36 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/27 11:32:54 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a > b && a < c)
		sa(stack_a);
	else if (a < b && a > c)
		rra(stack_a);
	else if (a > b && a > c && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a < b && a < c && b > c)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (a > b && a > c && b < c)
		ra(stack_a);
}

void	chanaparh(t_stack **a, t_stack *nodik)
{
	t_stack	*tmp;
	int		size;
	int		i;

	tmp = *a;
	size = ft_stacksize(*a);
	i = 0;
	while ((*a)->data != nodik->data)
	{
		*a = (*a)->next;
		i++;
	}
	*a = tmp;
	if (i > size / 2)
		while ((*a)->data != nodik->data)
			rra(a);
	else
		while ((*a)->data != nodik->data)
			ra(a);
}

void	sort_under_12(t_stack **a, t_stack **b, int size)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	while (size > 3)
	{
		tmp = *a;
		while (tmp->index != i)
			tmp = tmp->next;
		chanaparh(a, tmp);
		size--;
		i++;
		pb(a, b);
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}
