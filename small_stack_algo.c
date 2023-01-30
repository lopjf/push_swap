/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_algo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:37:53 by loris             #+#    #+#             */
/*   Updated: 2022/12/22 21:42:35 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_higest_at_end(t_list **a_p, t_list *a)
{
	if (a->content == 2)
		r(a_p, "ra");
	else if (a->next->content == 2)
		rr(a_p, "rra");
}

void	place_lowest_on_top(t_list **a_p, uint len, uint len2, uint pos)
{
	uint	i;
	t_list	*a;

	a = *a_p;
	i = 0;
	while (i < len)
	{
		if (a->content == len - pos)
			break ;
		a = a->next;
		i++;
	}
	if (i <= (len2 - 1) / 2)
		while (i-- > 0)
			r(a_p, "ra");
	else
		while (i++ < len2)
			rr(a_p, "rra");
}

void	simple_solve1(t_list **a_p, t_list **b_p, uint len, uint pos)
{
	t_list	*a;

	while (pos > 2)
	{
		place_lowest_on_top(a_p, len, ft_lstsize(*a_p), pos);
		p(b_p, a_p, "pb");
		pos--;
	}
	a = *a_p;
	if (a->content > a->next->content)
		r(a_p, "ra");
	while (len - pos > 0)
	{
		p(a_p, b_p, "pa");
		len--;
	}
}

void	simple_solve(t_list **a_p, t_list **b_p, uint len)
{
	t_list	*a;
	uint	pos;

	pos = len;
	if (len == 2 || len == 3)
	{
		if (len == 3)
			place_higest_at_end(a_p, *a_p);
		if (check_if_solve(*a_p) == 0)
			return ;
		a = *a_p;
		if (a->content > a->next->content)
			s(a_p, "sa");
		else
			return ;
	}
	if (check_if_solve(*a_p) == 0)
		return ;
	if (len > 3)
		simple_solve1(a_p, b_p, len, pos);
}
