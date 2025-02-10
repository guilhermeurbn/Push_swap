# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guisanto <guisanto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/27 15:43:22 by guisanto          #+#    #+#              #
#    Updated: 2025/02/10 17:17:50 by guisanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
INCLUDES_DIR = includes

SRCS = check_args.c \
	checks.c \
	list.c \
	main.c \
	operations.c \
	p_s.c \
	push_swap.c \
	rotate.c \
	small_operations.c \
	stack.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Werror -Wextra -g -I $(INCLUDES_DIR)

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o push_swap

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Esta regra indica como compilar cada arquivo .c em um .o
%.o: %.c
	@$(CC) $(CFLAGS) -c -o $@ $^

clean:
	@rm -f $(OBJS)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
