# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 15:24:15 by snocita           #+#    #+#              #
#    Updated: 2023/06/21 19:49:13 by snocita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

HEADER	= headers/minishell.h

SRCS	= src/main.c src/lexer.c src/parsing.c src/execution.c \
			src/builtins/ft_echo.c src/builtins/ft_cd.c \
			src/builtins/ft_pwd.c src/builtins/ft_env.c \
			src/builtins/ft_export.c \
			src/builtins/ft_exit.c \
			src/utils.c
SRC_DIR = src
OBJS	= $(SRCS:.c=.o)
OBJ_DIR = obj

LIBFT_PATH	= ./headers/libft
LIBFT		= $(LIBFT_PATH)/libft.a

%.o: %.c
		${CC} ${CFLAGS} -c $< -g -o $@

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS) $(LIBFT) $(GNL)
			cp $(LIBFT) .
			@$(CC) $(CFLAGS) $(OBJS) libft.a -o $(NAME) -lreadline

$(OBJ_DIR):
			mkdir $(OBJ_DIR)

$(LIBFT):
			make -sC $(LIBFT_PATH) all

clean:
		@$(RM) obj/
		make -C $(LIBFT_PATH) clean

fclean:	clean
		@$(RM) $(NAME)
		$(RM) libft.a get_next_line.a
		make -C $(LIBFT_PATH) fclean

re:		fclean all