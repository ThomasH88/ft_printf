# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2019/05/18 19:51:50 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[1;32m
YELLOW = \033[1;33m
NC = \033[0m # No Color

NAME = libftprintf.a

IDIR = includes

HEADERS = $(addprefix includes/, ft_printf.h)

CC = gcc

FLAGS = -Wall -Werror -Wextra -I$(IDIR)

ODIR = objs

SDIR = srcs

OBJS = $(addprefix $(ODIR)/, ft_printf.o \
	   init.o \
	   nb_size.o \
	   padding.o \
	   parsing.o \
	   print_all_nbs.o \
	   print_conversion.o \
	   print_other.o \
	   print_special.o \
	   set_params.o \
	   unsigned_helpers.o \
	   minilibft.o)

$(ODIR)/%.o: $(SDIR)/%.c $(HEADERS)
	@mkdir -p objs
	@$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJS)
	@echo "$(GREEN)OK -->$(YELLOW) libftprintf$(NC)"
	@ar rcs $@ $^

all: $(NAME)

clean:
	@echo "$(RED)Cleaning Objects$(NC)"
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf objs

fclean: clean
	@echo "$(RED)Cleaning executables$(NC)"
	@/bin/rm -rf $(NAME) *.out* *.dSYM

re: fclean all

.PHONY: all clean fclean re
