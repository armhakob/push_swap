/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instractions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:03:12 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/28 13:33:33 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h" 

void	error_tpi(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_instr(char *instr, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(instr, "sa\n", ft_strlen(instr)))
		sa(a);
	else if (!ft_strncmp(instr, "sb\n", ft_strlen(instr)))
		sb(b);
	else if (!ft_strncmp(instr, "ss\n", ft_strlen(instr)))
		ss(a, b);
	else if (!ft_strncmp(instr, "pa\n", ft_strlen(instr)))
		pa(a, b);
	else if (!ft_strncmp(instr, "pb\n", ft_strlen(instr)))
		pb(a, b);
	else if (!ft_strncmp(instr, "ra\n", ft_strlen(instr)))
		ra(a);
	else if (!ft_strncmp(instr, "rb\n", ft_strlen(instr)))
		rb(b);
	else if (!ft_strncmp(instr, "rr\n", ft_strlen(instr)))
		rr(a, b);
	else if (!ft_strncmp(instr, "rra\n", ft_strlen(instr)))
		rra(a);
	else if (!ft_strncmp(instr, "rrb\n", ft_strlen(instr)))
		rrb(b);
	else if (!ft_strncmp(instr, "rrr\n", ft_strlen(instr)))
		rrr(a, b);
	else
		error_tpi();
}
