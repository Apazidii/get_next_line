NAME	= run
FUNCS 	=	main.c					\
			get_next_line.c			\
			get_next_line_utils.c	\

			

FUNCSO = ${FUNCS:.c=.o}
GCC = gcc
CFLAGS = -c
HDRS = head.h

all:		${NAME}
			make clean
			clear
			./${NAME}

nc:			${NAME}
			make clean
			./${NAME}	

${NAME}:	${FUNCSO} ${HDRS} 
			${GCC} ${FUNCSO} -o ${NAME}
			
.c.o:		
			${GCC} ${CFLAGS} $< -o ${<:.c=.o} 

clean:
		rm -f ${FUNCSO}

fclean:	clean
		rm -f ${NAME}

.PHONY:	all clean fclean