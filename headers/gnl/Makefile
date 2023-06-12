# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snocita <snocita@student.42wolfsburg.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/12 13:21:30 by snocita           #+#    #+#              #
#    Updated: 2023/05/12 14:11:29 by snocita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror
NAME 		=	get_next_line.a
SRCS_DIR	=	src
OBJS_DIR	=	obj
RM			=	rm -rf
AR			=	ar -rcs

SRC			=	get_next_line_utils \
				get_next_line

SRCS		=	$(addsuffix .c, $(SRC))
OBJS		=	$(addsuffix .o, $(SRC))

.c: $(SRCS)
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		@$(AR) get_next_line.a $(OBJS)
		@mkdir -p $(OBJS_DIR)
		mv *o $(OBJS_DIR)/

all: $(NAME)
	

clean: 
	@$(RM) *.o
	@rm -rf obj/

fclean: clean
	@$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re