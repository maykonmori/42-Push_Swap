# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 12:06:31 by mjose-ye          #+#    #+#              #
#    Updated: 2022/01/22 22:47:34 by mjose-ye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

HEADER = push_swap.h

INCLUDE = -I ./includes

FOLDER = ./src/

FOLDER2 = ./utils/

LIBFT = ./42_Libft/libft.a

UTILS = $(addprefix $(FOLDER2), \
		)

SRC =	$(addprefix $(FOLDER), \
		push_swap.c \
		utils.c \
		validations.c \
		operations.c \
		rules.c)

OBJS	= ${SRC:%.c=%.o} ${UTILS:%.c=%.o}

CC = gcc

CFLAGS = -Wextra -Werror -Wall -g

.c.o:
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	make -C ./42_Libft

clean:
	rm -f $(OBJS)
	make clean -C ./42_Libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./42_Libft

re: fclean all