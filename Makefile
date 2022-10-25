# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cschuijt <cschuijt@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/24 11:17:25 by cschuijt      #+#    #+#                  #
#    Updated: 2022/10/25 11:32:50 by cschuijt      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

FLAGS=-Werror -Wall -Wextra
NAME=libftprintf.a
OBJECTS=ft_printf.o print_functions.o ft_strlen.o
BONUS_OBJECTS=

$(NAME) : $(OBJECTS)

all : $(NAME)

# bonus : $(BONUS_OBJECTS)
# 	ar r $(NAME) $(BONUS_OBJECTS)

re : fclean all

clean :
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean :
	rm -f $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

test : re
	cc libftprintf.a test.c -o test
	./test

ft_printf.o : ft_printf.c
	$(CC) $(FLAGS) -c ft_printf.c
	ar r $(NAME) ft_printf.o

print_functions.o : print_functions.c
	$(CC) $(FLAGS) -c print_functions.c
	ar r $(NAME) print_functions.o

ft_strlen.o : ft_strlen.c
	$(CC) $(FLAGS) -c ft_strlen.c
	ar r $(NAME) ft_strlen.o
