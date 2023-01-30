/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:04:33 by loris             #+#    #+#             */
/*   Updated: 2022/12/22 21:43:32 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *stack)
{
	if (stack == NULL)
		return ;
	free(stack);
	free_stack(stack->next);
}

int	ascii_to_decimal(char *str)
{
	size_t	i;
	int		ret;
	int		neg;

	i = 0;
	ret = 0;
	neg = 1;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (i < ft_strlen(str))
	{
		ret = ret * 10 + (str[i] - 48);
		i++;
	}
	return (ret * neg);
}

void	print_list(t_list *stack)
{
	t_list	*current;

	current = stack;
	while (current)
	{
		ft_printf("%d ", current->content);
		current = current->next;
	}
	ft_printf("\n");
}

int	main(int ac, char *av[])
{
	t_list	*a;
	t_list	*b;

	if (ac == 1)
		return (0);
	if (ac > 1)
	{
		if (check_args_and_init(ac - 1, av, &a) == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	if (ac == 2)
		return (0);
	b = NULL;
	if (ft_lstsize(a) < 6)
		simple_solve(&a, &b, ft_lstsize(a));
	else
		solve(&a, &b, ft_lstsize(a), get_nb_bits(ft_lstsize(a)));
	free_stack(a);
	return (0);
}

// sa
	// s(&a);
// sb
	// s(&b);
// ss
	// s(&a);
	// s(&b);
// pa
	// p(&a, &b);
// pb
	// p(&b, &a);
// ra
	// r(&a);
// rb
	// r(&b);
// rr
	// r(&a);
	// r(&b);
// rra
	// rr(&a);
// rrb
	// rr(&b);
// rrr
	// rr(&a);
	// rr(&b);
