# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:14:09 by vmanzoni          #+#    #+#              #
#    Updated: 2019/04/05 21:35:53 by vmanzoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC_DIR	=	srcs/

SRCS	=	SRC_DIR/*.c

OBJ_DIR	=	objs/

OBJS	=	$(SRCS:.c=.o)

HEADER	=	includes/

LIB	=	ft_printf.h

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM	=	rm -f

all:	$(NAME)

$(NAME)
	$(CC) $(CFLAGS) -I$(HEADER) -c $(addprefix srcs/, $(SRCS))
	$(CC) $(OBJS) -o $(NAME)
	mkdir $(OBJ_DIR)
	mv *.o $(OBJ_DIR)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
