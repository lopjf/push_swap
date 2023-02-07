/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:58:50 by loris             #+#    #+#             */
/*   Updated: 2023/02/07 19:17:32 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_it(int *sorted_list, int j)
{
	int	tmp;

	tmp = sorted_list[j];
	sorted_list[j] = sorted_list[j + 1];
	sorted_list[j + 1] = tmp;
}

int	*simple_sort(int *list, uint len, uint i, uint j)
{
	int	*sorted_list;

	sorted_list = malloc(sizeof(int) * len);
	if (!sorted_list)
		return (NULL);
	while (i < len)
	{
		sorted_list[i] = list[i];
		i++;
	}
	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - 1)
		{
			if (sorted_list[j] > sorted_list[j + 1])
				swap_it(sorted_list, j);
			j++;
		}
		i++;
	}
	return (sorted_list);
}

uint	*get_index(int *list, int *sorted_list, uint len)
{
	uint	*indexed;
	size_t	i;
	size_t	j;

	indexed = malloc(sizeof(uint) * len);
	if (!indexed)
		return (NULL);
	j = 0;
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (list[j] == sorted_list[i])
			indexed[j] = i;
			i++;
		}
		j++;
	}
	return (indexed);
}

void	apply_index(t_list **a, uint *indexed, uint len)
{
	*a = ft_lstnew(indexed[len]);
	len--;
	while (len > 0)
	{
		ft_lstadd_front(a, ft_lstnew(indexed[len]));
		len--;
	}
	ft_lstadd_front(a, ft_lstnew(indexed[len]));
}

void	index_list(t_list **a, int *list, uint len)
{
	int		*sorted_list;
	uint	*indexed;

	sorted_list = simple_sort(list, len, 0, 0);
	indexed = get_index(list, sorted_list, len);
	free(list);
	free(sorted_list);
	apply_index(a, indexed, len - 1);
	free(indexed);
}
