NAME	= push_swap
SRC_S	= main.c indexing.c input.c
OBJ	= ${SRC_S:.c=.o}
CC		= gcc
RM		= rm -f
HEADER	= -I Libft/
CFLAGS	= -Wall -Werror -Wextra -g

all:		${NAME}

.c.o:
				@${CC} -c ${CFLAGS} ${HEADER} $< -o ${<:.c=.o}

clean:
				@${RM} ${OBJ} \
				$(info ************  push_swap Clean)

libclean:
				@${MAKE} clean -C Libft --no-print-directory

fclean:		clean
				@${RM} ${NAME} \
				$(info ************  push_swap Removed) \
				&& ${MAKE} fclean -C Libft --no-print-directory

re:			fclean all

${NAME}:	${OBJ} Libft/libft.a
				@${CC} -o $@ $^ \
				$(info ************  push_swap ready!)

Libft/libft.a:
				@${MAKE} -C Libft --no-print-directory

.PHONY: all clean fclean re libft