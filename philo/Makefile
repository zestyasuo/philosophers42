CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g -pthread
NAME		=	philo

INCPATH		=	include/
SRCPATH		=	src/
OBJPATH		=	obj/

SRC			=	philo.c			\
				print_utils.c	\

HEADERS = philo.h

HEAD_DEP = ${HEADERS:%.h=${INCPATH}%.h}

OBJ			=	${SRC:%.c=${OBJPATH}%.o}

.PHONY: all clean fclean re

all: ${NAME}

${OBJPATH}:
	mkdir ${OBJPATH}

${NAME}: ${OBJ} 
	${CC} ${CFLAGS} $^ -o $@

${OBJPATH}%.o : ${SRCPATH}%.c ${HEAD_DEP} | ${OBJPATH}
	${CC} ${CFLAGS} -c $< -o $@ -I${INCPATH}

clean: 
	rm -rf ${OBJPATH}

fclean: clean
	rm -f ${NAME}

re: fclean all