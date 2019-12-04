# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 11:36:56 by dpiedra           #+#    #+#              #
#    Updated: 2019/12/04 13:28:27 by dpiedra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libprintf.a

RM		=	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

CC		=	gcc

HEADER	=	libprintf.h

SRCS	=

OBJ		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $((SRCS) libprintf.h $(CFLAGS) 
			ar -rcs $(NAME) $(OBJ) $(HEADER)

.PHONY	:	clean fclean re

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
