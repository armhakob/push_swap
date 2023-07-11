/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:48:54 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/27 15:30:10 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate(t_stack **stack_a)
{
	t_stack	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return (0);
	tmp = *stack_a;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->prev->next = NULL;
	tmp->prev = *stack_a;
	(*stack_a)->next = tmp;
	(*stack_a)->prev = NULL;
	return (1);
}

void	rra(t_stack **a)
{
	if (reverse_rotate(a))
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b)
{
	if (reverse_rotate(b))
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (reverse_rotate(a) && reverse_rotate(b))
		ft_putstr_fd("rrr\n", 1);
}
