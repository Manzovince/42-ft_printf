# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:14:09 by vmanzoni          #+#    #+#              #
#    Updated: 2019/05/08 09:05:59 by vmanzoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_printf

SRC_DIR	=	srcs/
SRCS	=	*.c

OBJ_DIR	=	objs/
OBJS	=	$(SRCS:.c=.o)

HEADER	=	includes/

LIB		=	ft_printf.h

LDFLAGS	=	-L./libft/
LDLIBS	=	-lft

CC		=	gcc

CFLAGS	=	-I.
CFLAGS	+=	-Wall -Wextra -Werror

RM		=	rm -f

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(SRC_DIR)$(SRCS) -o $(NAME)
#	mkdir $(OBJ_DIR)
#	mv *.o $(OBJ_DIR)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
