# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amurawsk <amurawsk@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 15:24:15 by snocita           #+#    #+#              #
#    Updated: 2023/06/19 20:44:32 by amurawsk         ###   ########.fr        #
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

GNL_PATH = ./headers/gnl
GNL = $(GNL_PATH)/get_next_line.a

LIBFT_PATH	= ./headers/libft
LIBFT		= $(LIBFT_PATH)/libft.a

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJS) $(LIBFT) $(GNL)
			cp $(LIBFT) .
			cp $(GNL) . 
			@$(CC) $(CFLAGS) $(OBJS) libft.a get_next_line.a -g -o $(NAME) -lreadline
			mv src/*.o ./obj
			mv src/builtins/*.o ./obj

$(OBJ_DIR):
			mkdir $(OBJ_DIR)

$(GNL):
			make -sC $(GNL_PATH) all

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