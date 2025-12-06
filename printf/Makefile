# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/27 19:27:15 by bahkaya           #+#    #+#              #
#    Updated: 2025/07/15 14:43:13 by bahkaya          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = 	ft_printf_utils.c \
		ft_printf.c \
		ft_printf_itoa_utils.c \
		ft_printf_flags.c		\
		ft_flags_check.c		\
		ft_itoa.c				
OBJC = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJC)
	@ar rcs $(NAME) $(OBJC)

clean:

	@rm -rf $(OBJC)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

comp:
	@$(CC) $(CFLAGS) main.c $(NAME) $(LIBFT)
run: comp
	@./a.out