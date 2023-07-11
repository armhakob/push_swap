/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:48:57 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/28 12:21:27 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	rotate(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return (0);
	tmp = *stack_a;
	tmp2 = (*stack_a)->next;
	while ((*stack_a)->next)
		(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp->prev = *stack_a;
	tmp->next = NULL;
	tmp2->prev = NULL;
	*stack_a = tmp2;
	return (1);
}

void	ra(t_stack **a)
{
	rotate(a);
}

void	rb(t_stack **b)
{
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
