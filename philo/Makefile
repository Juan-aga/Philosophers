# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 08:52:41 by juan-aga          #+#    #+#              #
#    Updated: 2023/03/05 21:10:36 by juan-aga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC			= gcc ${CFLAGS} ${HEADERS}

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

SRC_DIR		= src/

OBJ_DIR		= obj/

_SRC		= philo.c		\
			 check_args.c	\
			 init.c			\
			 print.c		\
			 time.c			\
			 routine.c

SRC			= ${addprefix ${SRC_DIR}, ${_SRC}}

OBJ			= ${patsubst ${SRC_DIR}%.c, ${OBJ_DIR}%.o, ${SRC}}

HEADERS		= -I ./include
ifdef D
	CFLAGS += -g
	MAKE += -g
endif

#		COLORS		#
CYELLOW			=\033[1;33m
CGREEN			=\033[0;32m
CRED			=\033[0;91m
CRESET			=\033[0m

${OBJ_DIR}%.o: ${SRC_DIR}%.c
			@mkdir -p obj
			@${CC} -c $<  -o $@ && printf "${CGREEN}Compiling: ${CYELLOW}$(notdir $<\n)"

${NAME}:	${LIBS} ${OBJ}
			@${CC} ${OBJ} -o ${NAME}
			@echo "\n${CYELLOW}${NAME}${CGREEN} compiled with flags: ${CYELLOW}${CFLAGS}\n${CRESET}"

${LIBS}:
			@git submodule update --init
			@${MAKE} -s -C ../memory-leaks
		

all:		${NAME}

clean:
			@${RM} ${OBJ_DIR}
			@echo "${CRED}${NAME} objects files were deleted.${CRESET}"

fclean:		clean
			@${RM} ${NAME}
			@echo "${CRED}${NAME} was deleted.${CRESET}"

re:			fclean ${NAME}

.PHONY:		all clean fclean re
