# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/10 16:42:11 by tholzheu          #+#    #+#              #
#    Updated: 2019/05/18 20:56:33 by tholzheu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[1;32m
YELLOW = \033[1;33m
ORANGE = \033[1;31m
BLUE = \033[1;36m
GREY = \033[1;30m
NC = \033[0m

NAME = libftprintf.a

IDIR = includes

HEADERS = $(addprefix $(IDIR)/, ft_printf.h)

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
	@echo "$(ORANGE)Compiling $(NC)($(YELLOW)$(NAME)$(NC)) > $(BLUE)$<$(NC)"
	@mkdir -p objs
	@$(CC) -c -o $@ $< $(FLAGS)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "$(GREEN)OK -->$(YELLOW) $(NAME)$(NC)"

all: $(NAME)

clean:
	@echo "$(GREY)Cleaning $(RED)Objects$(NC)"
	@/bin/rm -f $(OBJS)
	@/bin/rm -rf objs

fclean: clean
	@echo "$(GREY)Cleaning $(RED)Executables$(NC)"
	@/bin/rm -rf $(NAME) *.out* *.dSYM

re: fclean all

.PHONY: all clean fclean re
