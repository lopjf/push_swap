/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:05:08 by loris             #+#    #+#             */
/*   Updated: 2022/12/22 14:18:25 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		main(int ac, char *av[]);
int		check_args_and_init(uint len, char *s[], t_list **a);
void	free_stack(t_list *stack);
void	s(t_list **stack, char *s);
void	p(t_list **stack_push, t_list **stack_trim, char *s);
void	r(t_list **stack, char *s);
void	rr(t_list **stack, char *s);
void	index_list(t_list **a, int *list, uint len);
int		get_nb_bits(size_t size);
void	solve(t_list **a_p, t_list **b_p, size_t len, size_t nb_bits);
void	simple_solve(t_list **a_pointer, t_list **b_pointer, uint len);
int		check_if_solve(t_list *stack);
void	print_list(t_list *stack);

#endif