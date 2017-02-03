# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarmaya <vdarmaya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 08:23:40 by achauvea          #+#    #+#              #
#    Updated: 2017/02/03 07:08:47 by vdarmaya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = vdarmaya.filler
FLAGS = -Wall -Wextra -Werror
LIBDIR = ./libft/
SRCDIR = ./src/
INCDIR = ./include/

SRC = main.c get_next_line.c utils.c error.c get_turn_info.c solver.c \
		scoring.c radius.c

VISUAL = display.c display2.c get_next_line.c

SRCS = $(addprefix $(SRCDIR), $(SRC))
VISUALS = $(addprefix $(SRCDIR), $(VISUAL))

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@echo "libft - Compilation Done"	
	@gcc $(FLAGS) $(SRCS) -I$(INCDIR) -o $(NAME) -L $(LIBDIR) -l ft -lncurses
	@echo "filler - Compilation Done"

visual: $(NAME)
	@gcc $(FLAGS) $(VISUALS) -I$(INCDIR) -o visual -L$(LIBDIR) -l ft
	@echo "visual - Compilation Done"

clean:
	@make clean -C $(LIBDIR)
	@echo "libft - Clean Done"
	@echo "filler - Clean Done"

fclean: clean
	@make fclean -C $(LIBDIR)
	@rm -rf $(NAME)
	@rm -rf visual
	@echo "filler - Fclean Done"

re: fclean all
