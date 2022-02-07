# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gdufresn <gdufresn@student.42lausan>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 15:25:39 by gdufresn          #+#    #+#              #
#    Updated: 2022/02/07 15:48:15 by gdufresn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minishell

HEADER		=	minishell.h

SRCS		=	main.c \
				memory.c \
				str.c \
				str_list.c

OBJS		=	$(SRCS:.c=.o)
DEPS		=	$(SRCS:.c=.d)

CC			=	clang
CFLAGS		=	-Wall -Wextra -Wno-error -MD
				# Change to -Werror once the code is good.


all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

clean:
			rm -rf $(OBJS) $(DEPS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all


.PHONY:		all clean fclean re


-include $(DEPS)
