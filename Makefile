# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2018/11/01 19:48:28 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NAME2 = libft/libft.a

HEADER = ft_printf.h

HEADER2 = libft/libft.h

FLAGS = -Wall -Werror -Wextra -c

DEBUG = fsanitize=address -g

SRCS = ft_printf.c \
	   init.c \
	   nb_size.c \
	   padding.c \
	   parsing.c \
	   print_all_nbs.c \
	   print_conversion.c \
	   print_other.c \
	   set_params.c \
	   unsigned_helpers.c \

SRCO = $(SRCS:.c=.o)

$(NAME):
	make -C libft
	gcc $(FLAGS) $(SRCS) -I=$(HEADER)
	ar rcs $(NAME) $(SRCO)

all: $(NAME) 

run: re
	gcc main.c print_bits.c $(NAME) $(NAME2) -I $(HEADER2)

san: fclean
	gcc $(DEBUG) $(SRCS) main.c print_bits.c -I $(HEADER2)

clean:
	make clean -C libft
	/bin/rm -f $(SRCO)

fclean: clean
	make fclean -C libft
	/bin/rm -rf $(NAME) *.out* *.dSYM

re: fclean all

git: fclean
	git add .
	git reset HEAD *main*
	git status
	git commit -m "update"
	git push
