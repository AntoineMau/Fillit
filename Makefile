# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:30:56 by anmauffr          #+#    #+#              #
#    Updated: 2018/11/21 20:17:37 by anmauffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

# Executable name, can be change
NAME = fillit

# Sources names
SRCS_NAME = ft_hello.c \
			main.c

# Sources, objects and includes path
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
INCS_PATH = ./includes/

# Sources and objects
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRCS))

# Compilation
CC = gcc
CPPFLAGS = -I $(INCS_PATH)
CFLAGS = -Wall -Wextra -Werror $(CPPFLAGS)
LDFLAGS = ./libft/
LDLIBS = libft.a

# Text format
_DEF = $'\033[0m
_GRAS = $'\033[1m
_SOUL = $'\033[4m
_CLIG = $'\033[5m
_SURL = $'\033[7m

# Colors
_BLACK = $'\033[30m
_RED = $'\033[31m
_GREEN = $'\033[32m
_YELLOW = $'\033[33m
_BLUE = $'\033[34m
_PURPLE = $'\033[35m
_CYAN = $'\033[36m
_GREY = $'\033[37m

# Background
_IBLACK = $'\033[40m
_IRED = $'\033[41m
_IGREEN = $'\033[42m
_IYELLOW = $'\033[43m
_IBLUE = $'\033[44m
_IPURPLE = $'\033[45m
_ICYAN = $'\033[46m
_IGREY = $'\033[47m

verif = 0

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	@$(CC) $(LDFLAGS)$(LDLIBS) $(OBJS) -o $@
	@echo

libft/libft.a:
	@echo -e "$(_GRAS)$(_GREEN)|~~~~~~~~~ COMPILING ~~~~~~~~~|\n$(_DEF)"
	@make -C $(LDFLAGS)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@if [[ $(verif) -eq 0 ]] ; then echo -e "\t$(_GREY)==> $(NAME) <=="; fi
	$(eval verif = 1)
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@echo -e "$(_YELLOW)Compiling :\t$(_GREEN)" $<
	@$(CC) $(CFLAGS) -o $@ -c $<


clean: lib_clean
	@rm -rf $(OBJS_PATH) 2> /dev/null || true
	@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(OBJS_PATH)
	@echo

fclean: lib_fclean
	@rm -rf $(OBJS_PATH) 2> /dev/null || true
	@rm -f $(NAME)
	@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(OBJS_PATH)
	@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(NAME)
	@echo

lib_clean:
	@echo -e "\n$(_GRAS)$(_RED)|~~~~~~~~~ REMOVING ~~~~~~~~~~|\n$(_DEF)"
	@make -C $(LDFLAGS) clean

lib_fclean:
	@echo -e "\n$(_GRAS)$(_RED)|~~~~~~~~~ REMOVING ~~~~~~~~~~|\n$(_DEF)"
	@make -C $(LDFLAGS) fclean

re: fclean all

norme:
	@norminette $(SRCS_PATH)
	@norminette $(INCS_PATH)

.PHONY: all clean fclean lib_clean lib_fclean re norme