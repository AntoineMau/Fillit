# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anmauffr <anmauffr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 18:30:56 by anmauffr          #+#    #+#              #
#    Updated: 2018/11/21 20:17:39 by anmauffr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

# Executable name, can be change
NAME = libft.a

# Sources names
SRCS_NAME = ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putnbr.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstlen.c \
			ft_lst_at.c \
			ft_lstnext.c \
			ft_print_word_tab.c \
			ft_print_nbr_tab.c

# Sources, objects and includes path
SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
INCS_PATH = ./includes/

# Sources and objects
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(patsubst $(SRCS_PATH)%.c, $(OBJS_PATH)%.o, $(SRCS))

# Compilation
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I $(INCS_PATH)
LDFLAGS = ./libft/

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

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo -ne "$(_YELLOW)Compiling :\t$(_BLUE)" $(NAME)
	@echo -e "$(_DEF)"
	@echo

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	@if [[ $(verif) -eq 0 ]] ; then echo -e "\t$(_GREY)==> $(NAME) <=="; fi
	$(eval verif = 1)
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@echo -e "$(_YELLOW)Compiling :\t$(_GREEN)" $<
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJS_PATH) 2> /dev/null || true
	@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)objs/

fclean:
	@rm -rf $(OBJS_PATH) 2> /dev/null || true
	@rm -f $(NAME)
	@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)objs/
	@echo -e "$(_YELLOW)Remove :\t$(_RED)" $(LDFLAGS)$(NAME)

re: fclean all

norme:
	@echo -ne "$(_GREEN)"
	@norminette $(SRCS_PATH)
	@norminette $(INCS_PATH)
	@echo -ne "$(_DEF)"

.PHONY: all clean fclean re norme