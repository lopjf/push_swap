# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loris <loris@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/07 14:54:38 by lpenelon          #+#    #+#              #
#    Updated: 2023/02/07 20:40:18 by loris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

SRCS			=	ft_putchar_fd.c \
					ft_strncmp.c \
					ft_bzero.c \
					ft_putnbr_fd.c  ft_strlen.c \
					ft_calloc.c \
					ft_putstr_fd.c \
					ft_putnbru_fd.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c \
					ft_printf.c ft_printf_funcs1.c ft_printf_funcs2.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
RUN				= ar rcs

%.o: %.c
	$(CC) -c $(CFLAGS) -I headers $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(RUN) $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)