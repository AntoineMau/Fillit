# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:30:56 by anmauffr          #+#    #+#              #
#    Updated: 2018/11/22 17:19:21 by anmauffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

# Executable name, can be change
NAME = fillit

# Sources names
SRCS_NAME = ft_verif.c \
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
	@echo -en "$(_GREEN)\t [OK]\n\n$(_DEF)"

libft/libft.a:
	@make -C $(LDFLAGS)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@if [[ $(verif) -eq 0 ]]; then printf "\n$(_GRAS)$(_CYAN)|==========================>  $(NAME)   <==========================|$(_DEF)\n";\
	else printf "\e[1A"; fi
	$(eval FNCT = $(words $(SRCS)))
	$(eval verif = $(shell echo $(verif) + 1 | bc ))
	$(eval PCR = $(shell echo "$(verif) / $(FNCT) * 100" | bc -l))
	@printf " \n$(_GREEN)[%3d%%]\t$(_DEF)%-24s $(_PURPLE)👉$(_GREEN)\t%-24s$(_DEF)" $(shell echo $(PCR) | sed -E "s:\.[0-9]{20}::") $< $@
	@mkdir -p objs
	@printf "$(_DEF)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

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
	@make -C $(LDFLAGS) clean

lib_fclean:
	@make -C $(LDFLAGS) fclean

re: fclean all

norme:
	@norminette $(SRCS_PATH)
	@norminette $(INCS_PATH)

.PHONY: all lib_clean lib_fclean clean fclean re  norme
