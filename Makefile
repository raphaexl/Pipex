# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abiri <kerneloverseer@protonmail>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/15 20:38:11 by abiri             #+#    #+#              #
#    Updated: 2019/02/03 11:26:26 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

_lCYAN = \x1b[96m
_lYELLOW = \x1b[93m
_lGREEN = \x1b[92m
_lBLUE = \x1b[94m
_RED = \x1b[31m
_END = \x1b[0m

NAME = pipex
SRC = src/main.c\
	  src/ft_cmdline.c\
	  src/ft_tools.c
FLAGS = -Wall -Werror -Wextra
INCLUDES = ./libft
LIBRARIES = libft/libft.a\
			libft/ft_printf/libftprintf.a
DELAY = 1

all : $(NAME)
$(NAME):
	@echo "\n\n$(_lCYAN)\
		 ________  ___  ________  _______      ___    __\n\
		|\   __  \|\  \|\   __  \|\  ___ \    |\  \  /  /|\n\
		\ \  \|\  \ \  \ \  \|\  \ \   __/|   \ \  \/  / /\n\
		 \ \   ____\ \  \ \   ____\ \  \_|/__  \ \    / / \n\
		  \ \  \___|\ \  \ \  \___|\ \  \_|\ \  /     \/  \n\
		   \ \__\    \ \__\ \__\    \ \_______\/  /\   \  \n\
		    \|__|     \|__|\|__|     \|_______/__/ /\ __\ \n\
                                              |__|/ \|__| \n\
	$(_END)\n\n"
	@echo "gcc $(_lYELLOW)$(FLAGS)$(_END) $(_lCYAN)$(SRC)$(_END)\n$(_lGREEN)$(LIBRARIES)$(_END) -I$(_RED)./inc$(_END)-I$(_RED)$(INCLUDES)$(_END) -o $(_lBLUE)$(NAME)$(_lEND)\n"
	@gcc $(FLAGS) $(SRC) $(LIBRARIES) -I./inc -I$(INCLUDES) -o $(NAME)
clean:
	@echo "\n$(_lCYAN)Makefile :$(_END) will delete $(_RED)$(NAME)$(_END)"
	@echo "starting in $(DELAY) sec, $(_RED)press Ctrl-c to abort$(_END)"
	@sleep $(DELAY)
	@rm -f $(NAME)
fclean: clean
	@echo "\n$(_lCYAN)Makefile :$(_END) will delete $(_RED)$(SRC:.c=.o)$(_END)"
	@echo "starting in $(DELAY) sec, $(_RED)press Ctrl-c to abort$(_END)"
	@sleep $(DELAY)
	@rm -f $(SRC:.c=.o)
fast:
	@rm -f $(NAME)
	@rm -f $(SRC:.c=.o)
	@gcc $(FLAGS) $(SRC) $(LIBRARIES) -I./inc -I$(INCLUDES) -o $(NAME)	
re: fclean all
