/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:48:52 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/28 13:25:34 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	push(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
}
