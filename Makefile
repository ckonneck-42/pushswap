# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckonneck <ckonneck@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 12:55:57 by ckonneck          #+#    #+#              #
#    Updated: 2024/08/26 15:59:53 by ckonneck         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Source files for pipex
PUSHSWAP_SRCS = push_swap.c push_swap_utils1.c push_swap_utils2.c \
				push_swap_utils3.c push_swap_utils4.c push_swap_bgutils1.c \
				push_swap_bubble.c push_swap_free1.c push_swap_free2.c \
				push_swap_op1.c push_swap_op2.c push_swap_op3.c \
				push_swap_opbg1.c push_swap_opbg2.c push_swap_utils5.c \
				push_swap_bgutils2.c push_swap_bgutils3.c \
				push_swap_utils6.c push_swap_bgutils4.c push_swap_utils7.c \
				push_swap_error.c push_swap_utils8.c push_swap_error2.c \
				push_swap_error3.c
PUSHSWAP_OBJS = $(PUSHSWAP_SRCS:.c=.o)
CC = cc
LIBFT_DIR = ./libft
LIBS = -L$(LIBFT_DIR) -lft
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
NAME = push_swap
# 'all' target
all: $(NAME)
$(NAME): $(PUSHSWAP_OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(PUSHSWAP_OBJS) $(LIBS) -o $(NAME)

# 'clean' rule
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(PUSHSWAP_OBJS)

# 'fclean' rule
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# 're' rule
re: fclean all

# Declare phony targets
.PHONY: all libft clean fclean re