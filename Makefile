NAME	= push_swap
SRC_S	= main.c input/indexing.c input/lst_options.c actions/push.c actions/rotate.c \
			narrow/sort.c narrow/sort_b.c narrow/sort_utils.c solve/general.c \
			actions/swap.c solve/quicksolve.c minsteps/is_sorted.c minsteps/solve3.c
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