# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: deannapiedra <deannapiedra@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/16 17:16:30 by dpiedra           #+#    #+#              #
#    Updated: 2020/02/07 11:44:21 by deannapiedr      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

RM		=	rm -f

CFLAGS	= 	-Wall -Wextra -Werror

CC		=	gcc

HEADER	=	-I printf.h

SRCS	=	ft_printf.c ft_char.c ft_conv_tools.c ft_flag_tools.c \
			ft_hexa.c ft_longitoa_base.c ft_percent.c ft_ptr.c \
			ft_signed_dec.c ft_str.c ft_uitoa_base.c ft_unsigned.c 

OBJ		=	$(SRCS:.c=.o)

all		:	$(NAME)

$(NAME)	:	$(OBJ)
			cd libft && $(MAKE)
			cp libft/libft.a $(NAME)
			ar -rcs $(NAME) $(OBJ)

.PHONY	:	clean fclean re

clean	:
			$(RM) $(OBJ)
			cd libft && $(MAKE) clean

fclean	:	clean
			$(RM) $(NAME)
			cd libft && $(MAKE) fclean

re		:	fclean all

%.o		:	%.c
			$(CC) $(FLAGS) $(HEADER) -c $<  -o $(<:.c=.o)
