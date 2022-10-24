# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cschuijt <cschuijt@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/24 11:17:25 by cschuijt      #+#    #+#                  #
#    Updated: 2022/10/24 23:17:29 by cschuijt      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC=cc
FLAGS=-Werror -Wall -Wextra
NAME=libftprintf.a
OBJECTS=ft_printf.o print_functions.o
BONUS_OBJECTS=

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus : $(BONUS_OBJECTS)
	ar rcs $(NAME) $(BONUS_OBJECTS)

re : fclean all

clean :
	rm $(NAME) $(OBJECTS)

fclean :
	rm -f $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

test : re
	cc libftprintf.a libft/libft.a test.c -o test
	./test

ft_printf.o : ft_printf.c libft.a
	$(CC) $(FLAGS) -c ft_printf.c

print_functions.o : print_functions.c libft.a
	$(CC) $(FLAGS) -c print_functions.c

libft.a :
	make -C libft all bonus
