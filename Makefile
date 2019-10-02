# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmanzoni <vmanzoni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 14:14:09 by vmanzoni          #+#    #+#              #
#    Updated: 2019/10/02 15:31:17 by vmanzoni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC_DIR	=	srcs/

SRCS	=	ft_dprintf.c\
			ft_printf.c\
			errors.c\
			parse_flags.c\
			buffer.c\
			flags.c\
			nbr_conv.c\
			fieldwitdh_precision.c\
			str_conv.c\
			color.c\
			wildcard.c

MAIN	=	main_test.c

OBJ_DIR	=	objs/
OBJS	=	$(SRCS:.c=.o)

HEADER	=	includes/

LIB		=	ft_printf.h

LDFLAGS	=	-L./libft/
LDLIBS	=	-lft

CC		=	gcc

CFLAGS	=	-I.
LFLAGS	=	-c
CFLAGS	+=	-Wall -Wextra -Werror

RM		=	rm -rf

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(LFLAGS) $(addprefix $(SRC_DIR), $(SRCS))
	mv *.o $(OBJ_DIR)
	ar rc $(NAME) libft/libft.a $(addprefix $(OBJ_DIR), $(OBJS))
#	@echo "\033[1;34mLibftprintf.a\t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

test:
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(addprefix $(SRC_DIR), $(SRCS)) $(MAIN) -o ft_printf
	@echo "\033[1;34mTEST PRINTF\t\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"

clean:
	$(RM) $(OBJ_DIR)

fclean:		clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re test
