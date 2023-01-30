/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:13:03 by loris             #+#    #+#             */
/*   Updated: 2022/12/22 21:29:47 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nb_bits(size_t size)
{
	int	count;

	count = 0;
	while (size > 0)
	{
		size = size / 2;
		count++;
	}
	return (count);
}

int	check_if_solve(t_list *stack)
{
	long long int	i;

	i = 0;
	while (stack)
	{
		if (stack->content != i)
			return (1);
		stack = stack->next;
		i++;
	}
	return (0);
}

int	solve1(t_list **a_p, t_list **b_p, size_t len, long long bit)
{
	t_list	*a;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (i < len)
	{
		a = *a_p;
		if ((a->content & bit) == 0)
		{
			p(b_p, a_p, "pb");
			count++;
		}
		else
			r(a_p, "ra");
		i++;
	}
	return (count);
}

void	solve(t_list **a_p, t_list **b_p, size_t len, size_t nb_bits)
{
	size_t		i;
	size_t		j;
	size_t		count;
	long long	bit;

	i = 0;
	j = 0;
	bit = 1;
	while (j < nb_bits)
	{
		i = 0;
		if (check_if_solve(*a_p) == 0)
			return ;
		count = solve1(a_p, b_p, len, bit);
		i = 0;
		while (i < count)
		{
			p(a_p, b_p, "pa");
			i++;
		}
		bit = bit * 2;
		j++;
	}
}
