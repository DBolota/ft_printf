# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dubolota <dubolota@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 03:11:48 by dubolota          #+#    #+#              #
#    Updated: 2025/05/16 04:00:31 by dubolota         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c printf_extra_func.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	@echo "$(NAME) was created!"
	@ar rc $(NAME) $(OBJ)

%.o: %.c libftprintf.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	@/bin/rm -f $(OBJ)
	@echo "Object files were removed"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "All files removed"

re: fclean all