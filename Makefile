NAME	= push_swap
SRC_S	= main.c
OBJ	= ${SRC_S:.c=.o}
CC		= gcc
RM		= rm -f
HEADER	= -I Libft/
CFLAGS	= -Wall -Werror -Wextra

all:		${NAME}

.c.o:
				${CC} -c ${CFLAGS} ${HEADER} $< -o ${<:.c=.o}
clean:
				${RM} ${OBJ}

fclean:		clean
				${RM} ${NAME}

re:			fclean all

${NAME}:	${OBJ} Libft/libft.a
				${CC} -o $@ $^ 

Libft/libft.a:
				${MAKE} -C Libft 

.PHONY: all clean fclean re libft