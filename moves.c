/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 13:16:20 by loris             #+#    #+#             */
/*   Updated: 2022/12/22 14:18:04 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_list **stack, char *s)
{
	t_list	*tmp;
	int		i1;
	int		i2;

	tmp = *stack;
	if (!tmp->next || !tmp)
		return ;
	i1 = tmp->content;
	*stack = tmp->next;
	free(tmp);
	tmp = *stack;
	i2 = tmp->content;
	*stack = tmp->next;
	free(tmp);
	ft_lstadd_front(stack, ft_lstnew(i1));
	ft_lstadd_front(stack, ft_lstnew(i2));
	ft_printf("%s\n", s);
}

void	p(t_list **stack_push, t_list **stack_trim, char *s)
{
	t_list	*tmp;

	if (!stack_trim)
		return ;
	tmp = *stack_trim;
	ft_lstadd_front(stack_push, ft_lstnew(tmp->content));
	free(*stack_trim);
	*stack_trim = tmp->next;
	ft_printf("%s\n", s);
}

void	r(t_list **stack, char *s)
{
	t_list	*tmp;

	tmp = *stack;
	ft_lstadd_back(&tmp, ft_lstnew(tmp->content));
	tmp = tmp->next;
	free(*stack);
	*stack = tmp;
	ft_printf("%s\n", s);
}

void	rr(t_list **stack, char *s)
{
	t_list	*tmp;

	tmp = ft_lstlast(*stack);
	ft_lstadd_front(stack, ft_lstnew(tmp->content));
	free(tmp);
	tmp = *stack;
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	tmp->next = NULL;
	ft_printf("%s\n", s);
}
