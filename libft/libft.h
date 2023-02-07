/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loris <loris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:35:48 by lpenelon          #+#    #+#             */
/*   Updated: 2023/02/07 20:45:20 by loris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	uint			content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
void				ft_bzero(void *b, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbru_fd(unsigned int n, int fd);
t_list				*ft_lstnew(int content);
void				ft_lstadd_front(t_list **lst, t_list *new);
size_t				ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_printf(const char *string, ...);
size_t				ft_printstr(char *str);
long unsigned int	ft_printpointer(unsigned long int i);
size_t				ft_printid(int n);
size_t				ft_printu(unsigned int n);
size_t				ft_printx(int n, char *base);
size_t				ft_printchar(int c);

#endif