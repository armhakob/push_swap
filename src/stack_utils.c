/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:57:17 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/27 15:33:23 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_stacklast(t_stack *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

void	ft_stackadd_back(t_stack **stack, t_stack *cur)
{
	t_stack	*l;

	l = *stack;
	if (!l)
	{
		*stack = cur;
		return ;
	}
	l = ft_stacklast(l);
	l->next = cur;
	cur->prev = l;
}

int	ft_stacksize(t_stack *head)
{
	size_t	i;
	t_stack	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
