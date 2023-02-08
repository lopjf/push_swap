/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:50:01 by loris             #+#    #+#             */
/*   Updated: 2023/02/07 19:08:43 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_simple_atoi(const char *nptr)
{
	int			i;
	long long	nbr;
	int			minus;

	i = 0;
	nbr = 0;
	minus = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			minus *= -1 ;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nbr * 10) + nptr[i] - 48;
		i++;
	}
	if (nptr[i] || nbr > 2147483647 || nbr * minus < -2147483648)
		return (0);
	return (nbr * minus);
}

int	check_if_zero(char *str)
{
	if ((ft_strncmp(str, "0", 1) == 0 && ft_strlen(str) == 1) || \
	(ft_strncmp(str, "+0", 2) == 0 && ft_strlen(str) == 2) || \
	(ft_strncmp(str, "-0", 2) == 0 && ft_strlen(str) == 2))
		return (0);
	return (1);
}

int	*create_int_array(uint len, char *s[])
{
	int		*list;
	uint	i;

	list = malloc(sizeof(int) * len);
	if (!list)
		return (NULL);
	i = 0;
	while (i < len)
	{
		list[i] = ft_simple_atoi(s[i + 1]);
		i++;
	}
	return (list);
}

int	check_double(int *list, uint len)
{
	uint	i;
	uint	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (list[i] == list[j])
			{
				free(list);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_args_and_init(uint len, char *s[], t_list **a)
{
	uint	i;
	int		zero;
	int		*list;

	i = 1;
	zero = 0;
	while (i < len + 1)
	{
		if (check_if_zero(s[i]) == 0)
		{
			if (zero == 1)
				return (0);
			zero = 1;
		}
		else if (ft_simple_atoi(s[i]) == 0)
			return (0);
		i++;
	}
	if (len == 1)
		return (1);
	list = create_int_array(len, s);
	if (check_double(list, len) == 0)
		return (0);
	index_list(a, list, len);
	return (1);
}
