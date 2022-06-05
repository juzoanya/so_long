# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juzoanya <juzoanya@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/21 13:58:18 by juzoanya          #+#    #+#              #
#    Updated: 2022/01/27 21:32:14 by juzoanya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC =	$(wildcard */*.c) \
		ft_evaluator.c \
		ft_printers.c \
		ft_printers_cs.c \
		ft_printf.c \
		ft_putchar.c \
		ft_utils.c \
		ft_evaluator_bonus.c \


OBJ = $(SRC:.c=.o)

BONUS = ft_evaluator_bonus.c \

BONUS_OBJ = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) created"
	@ranlib $(NAME)
	@echo "$(NAME) indexed"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

bonus: $(BONUS_OBJ) $(NAME)
	@ar rc $(NAME) $(BONUS_OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) $(BONUS_OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all, clean, fclean, re