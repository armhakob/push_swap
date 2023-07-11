/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:07:37 by armhakob          #+#    #+#             */
/*   Updated: 2023/04/28 13:58:30 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	i = (low - 1);
	pivot = arr[high];
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}	
		j++;
	}
	ft_swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quick_sort(int *arr, int low, int high)
{
	int	j;

	if (low < high)
	{
		j = partition(arr, low, high);
		quick_sort(arr, low, j - 1);
		quick_sort(arr, j + 1, high);
	}
}

void	find_index(t_stack **a, int *arr, int n)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	while (tmp)
	{
		i = 0;
		while (i < n)
		{
			if (arr[i] == tmp->data)
				tmp->index = i;
			i++;
		}
		tmp = tmp->next;
	}
}

void	do_indexing(t_stack **a)
{
	int		i;
	int		n;
	int		*arr;
	t_stack	*tmp;

	i = 0;
	n = ft_stacksize(*a);
	arr = (int *)malloc(sizeof(int) * n);
	tmp = *a;
	if (!arr)
		return ;
	while (i < n)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	quick_sort(arr, 0, n - 1);
	find_index(a, arr, n);
	free(arr);
}
