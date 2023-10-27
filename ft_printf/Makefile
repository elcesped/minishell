# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/15 16:36:16 by mvachera          #+#    #+#              #
#    Updated: 2023/05/22 15:51:59 by mvachera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

CC		= clang

CFLAGS	= -Wall -Wextra -Werror

RM		= rm -f

AR		= ar -rcs

SRC 	= ft_affichage.c  ft_arg.c  ft_count.c  ft_hexa.c  ft_printf.c

OBJ	= ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${AR} ${NAME} ${OBJ}

clean :
	${RM} ${OBJ}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
