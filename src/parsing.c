/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 16:40:52 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/28 14:04:21 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	i = a->data;
	while (a)
	{
		if (i > a->data)
			return (0);
		i = a->data;
		a = a->next;
	}
	return (1);
}

int	is_number(const char *str)
{
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	is_empty_mari(char **nums)
{
	int	i;
	int	j;

	i = 0;
	while (nums[i])
	{
		j = 0;
		if (ft_strlen(nums[i]))
		{
			while (ft_iswhitespace(nums[i][j]))
				j++;
			if (nums[i][j] == '\0')
				exit(0);
		}
		i++;
	}
}

void	free_nums(char **nums)
{
	int	i;

	i = -1;
	while (nums && nums[++i])
		free(nums[i]);
	free(nums);
}

void	checking(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**nums;
	char	*line;

	line = NULL;
	nums = NULL;
	i = 1;
	while (i < argc)
	{
		line = ft_strjoin_2(line, argv[i]);
		line = ft_strjoin_2(line, " ");
		i++;
	}
	if (line)
	{
		nums = ft_split(line, ' ');
		free(line);
		is_empty_mari(nums);
		ft_check(nums);
		*a = check_and_fill(*a, nums);
		do_indexing(a);
		free_nums(nums);
	}
}
