# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-gin <mvan-gin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/27 13:14:45 by mvan-gin       #+#    #+#                 #
#    Updated: 2020/01/06 08:54:43 by mvan-gin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 		libftprintf.a

FILES = 	main.c \
			main_utils.c \
			standards.c \
			standards_utils1.c \
			standards_utils2.c \
			convert_digit.c \
			convert_digit_utils.c \
			convert_char.c \
			convert_string.c \
			int_converter.c \
			convert_hex.c \
			convert_hex_utils.c \
			convert_pointer.c \
			convert_unsigned.c \
			convert_unsigned_utils.c \

OFILES = 	main.o \
			main_utils.o \
			standards.o \
			standards_utils1.o \
			standards_utils2.o \
			convert_digit.o \
			convert_digit_utils.o \
			convert_char.o \
			convert_string.o \
			int_converter.o \
			convert_hex.o \
			convert_hex_utils.o \
			convert_pointer.o \
			convert_unsigned.o \
			convert_unsigned_utils.o \

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c $(FILES)
	ar rc $(NAME) $(OFILES)

clean:
	rm -f $(OFILES) $(BOFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
