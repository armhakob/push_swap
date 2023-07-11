/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:48:52 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/26 20:38:27 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack **dst, t_stack **src)
{
	t_stack	*head;
	t_stack	*tmp;

	if (!dst || !(*src))
		return (0);
	head = (*src);
	tmp = (*src)->next;
	if (tmp)
		tmp->prev = NULL;
	if (*dst)
		(*dst)->prev = head;
	head->next = (*dst);
	*dst = head;
	*src = tmp;
	return (1);
}

void	pa(t_stack **a, t_stack **b)
{
	if (push(a, b))
		ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	if (push(b, a))
		ft_putstr_fd("pb\n", 1);
}
