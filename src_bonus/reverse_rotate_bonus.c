/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:48:54 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/28 12:21:22 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	reverse_rotate(a);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
