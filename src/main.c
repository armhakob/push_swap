/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:44:24 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/28 13:59:08 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		size;
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	checking(argc, argv, &a);
	size = ft_stacksize(a);
	if (size == 2)
		sa(&a);
	else if (size > 2 && size < 13)
		sort_under_12(&a, &b, size);
	else
		do_butterfly_detka(&a, &b);
	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
	return (0);
}
