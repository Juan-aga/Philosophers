# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 08:52:41 by juan-aga          #+#    #+#              #
#    Updated: 2023/02/24 09:02:42 by juan-aga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= gcc ${CFLAGS} ${HEADERS}

CFLAGS		= -Wall -Werror -Wextra

rm			= rm -rf

SRC_DIR		= src/

_SRC		= philo.c

SRC			= ${addprefix ${SRC_DIR}, ${_SRC}}

OBJ			= ${SRC:.c=.o}

HEADERS		= -I ./include

%.o: %.c
			@${CC} -c $^  -o $@

${NAME}:	${OBJ}
			${CC} ${OBJ} -o ${NAME}

all:		${NAME}

clean:
			@${RM} ${OBJ}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
