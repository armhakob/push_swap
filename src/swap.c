/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:48:49 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/27 15:33:32 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack **stack)
{
	int	tmp;

	if (!stack || !(*stack) || !((*stack)->next))
		return (0);
	tmp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = tmp;
	tmp = (*stack)->index;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->index = tmp;
	return (1);
}

void	sa(t_stack **a)
{
	if (swap(a))
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b)
{
	if (swap(b))
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	if (swap(a) && swap(b))
		ft_putstr_fd("ss\n", 1);
}
