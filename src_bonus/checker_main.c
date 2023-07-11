/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:44:24 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/28 15:33:00 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

#if 0

void	print_stack(t_stack *a)
{
	printf("################  stack  ##################\n");
	while (a)
	{
		printf("%d ", a->data);
		a = a->next;
	}
	printf("\n################  stack  ##################\n");
}
#endif

void	free_stack(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a;
		a = a->next;
		free(tmp);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*instr;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	checking(argc, argv, &a);
	while (1)
	{
		instr = get_next_line(0);
		if (instr)
			check_instr(instr, &a, &b);
		else
			break ;
		free(instr);
	}
	if (!a || b || !is_sorted(a))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	free_stack(a);
	return (0);
}
