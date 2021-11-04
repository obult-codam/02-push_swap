NAME	= push_swap
SRC_S	= main.c indexing.c input.c
OBJ	= ${SRC_S:.c=.o}
CC		= gcc
RM		= rm -f
HEADER	= -I Libft/
CFLAGS	= -Wall -Werror -Wextra -g

all:		${NAME}

.c.o:
				${CC} -c ${CFLAGS} ${HEADER} $< -o ${<:.c=.o}

clean:
				@${RM} ${OBJ} \
				$(info ************  Push_Swap Clean)

libclean:
				@${MAKE} clean -C Libft

fclean:		clean
				@${RM} ${NAME} \
				$(info ************  Push_Swap Removed) \
				&& ${MAKE} fclean -C Libft

re:			fclean all

${NAME}:	${OBJ} Libft/libft.a
				${CC} -o $@ $^

Libft/libft.a:
				${MAKE} -C Libft 

.PHONY: all clean fclean re libft