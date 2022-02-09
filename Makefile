# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgoncalv <bgoncalv@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 15:25:39 by gdufresn          #+#    #+#              #
#    Updated: 2022/02/09 16:25:51 by gdufresn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

HEADER		=	minishell.h

INCLUDES	=	-I includes/

SRCS		=	$(wildcard srcs/parse/*.c) \
				$(wildcard srcs/string/*.c) \
				$(wildcard srcs/utils/*.c) \
				$(wildcard srcs/builtins/*.c) \
				$(wildcard srcs/main/*.c)

OBJS		=	$(SRCS:.c=.o)
DEPS		=	$(SRCS:.c=.d)

CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -MD

_BLUE=\e[34m
_PURPLE=\e[35m
_END=\e[0m

%.o : %.c
			@printf "$(_BLUE)Object in the making... $< $(_END)\n" $@
			@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -lreadline -o $(NAME)
			@printf "minishell		[$(_BLUE)✓$(_END)]\n"

clean:
			@printf "$(_PURPLE)Cleaning minishell objects... $(_END)\n" $@
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)
			@printf "$(_PURPLE)minishell	deleted$(_END)\n"

re:			fclean all

.PHONY:		all clean fclean re


-include $(DEPS)
