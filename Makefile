# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: loris <loris@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/26 11:02:47 by loris             #+#    #+#              #
#    Updated: 2022/12/22 13:38:18 by loris            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c check_args.c moves.c index.c big_stack_algo.c small_stack_algo.c
					
LIBFT_A = libft.a
LIBFT_DIR = libft/
LIBFT  = $(addprefix $(LIBFT_DIR), $(LIBFT_A))

OBJS = $(SRCS:.c=.o)

RM				= rm -f
FLAGS			= -Wall -Wextra -Werror -I.

%.o: %.c
	gcc -c $(CFLAGS) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(MAKE) -C $(LIBFT_DIR)
	gcc $(FLAGS) $(OBJS) -fsanitize=address $(LIBFT) -o $(NAME)

$(OBJS): $(SRCS)
	gcc $(FLAGS) -c $(SRCS)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(OBJS)

fclean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re