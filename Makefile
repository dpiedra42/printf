# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpiedra <dpiedra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 17:16:30 by dpiedra           #+#    #+#              #
#    Updated: 2020/02/06 16:40:30 by dpiedra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	printf.a

RM		=	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

CC		=	gcc

HEADER	=	printf.h

SRCS	=	ft_printf.c ft_char.c ft_conv_tools.c ft_flag_tools.c \
			ft_hexa.c ft_longitoa_base.c ft_percent.c ft_ptr.c \
			ft_signed_dec.c ft_str.c ft_uitoa_base.c ft_unsigned.c 

OBJ		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $((SRCS) libft.h $(CFLAGS) 
			ar -rcs $(NAME) $(OBJ) $(HEADER)

.PHONY	:	clean fclean re

clean	:
			$(RM) $(OBJ)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all
