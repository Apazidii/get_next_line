NAME	= run
FUNCS 	=	get_next_line.c			\
			get_next_line_utils.c	\
			main.c					\

			

FUNCSO = ${FUNCS:.c=.o}
GCC = gcc
CFLAGS = -c -D BUFFER_SIZE=30 -D OPEN_MAX=265
HDRS = get_next_line.h 

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