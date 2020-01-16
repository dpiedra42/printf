# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 17:16:30 by dpiedra           #+#    #+#              #
#    Updated: 2020/01/16 17:16:35 by dpiedra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

RM		=	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

CC		=	gcc

HEADER	=	printf.h

SRCS	=	ft_printf.c 

OBJ		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $((SRCS) libftprintf.h $(CFLAGS) 
			ar -rcs $(NAME) $(OBJ) $(HEADER)

.PHONY	:	clean fclean re

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
