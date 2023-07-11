/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:44:36 by armhakob          #+#    #+#             */
/*   Updated: 2023/05/11 10:49:23 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_symb(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && !ft_iswhitespace(*s) && *s != '+' && *s != '-')
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		s++;
	}
}

void	ft_check(char **nums)
{
	int	i;

	i = 0;
	while (nums[i])
	{
		check_symb(nums[i]);
		i++;
	}
	if (check_dup(nums) == 1)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}

t_stack	*check_and_fill(t_stack *a, char **s)
{
	long	num;
	int		i;
	t_stack	*cur;

	i = -1;
	while (s[++i] != NULL)
	{
		num = ft_atol(s[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			write (2, "Error\n", 6);
			exit (0);
		}
		cur = ft_stacknew(ft_atoi(s[i]));
		ft_stackadd_back(&a, cur);
	}	
	if (is_sorted(a))
		exit (0);
	return (a);
}

int	check_dup(char **nums)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (nums[i])
	{
		j = 0;
		while (j < i)
		{
			if (ft_atoi(nums[j]) == ft_atoi(nums[i]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
