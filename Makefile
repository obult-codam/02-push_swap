NAME	= push_swap
SRC_S	= main.c \
			src/input/indexing.c src/input/lst_options.c \
			src/actions/push.c src/actions/rotate.c src/actions/swap.c \
			src/narrow/sort.c src/narrow/sort_b.c src/narrow/sort_utils.c src/narrow/split_two.c\
			src/solve/general.c src/solve/quicksolve.c\
			src/minsteps/is_sorted.c src/minsteps/solve3.c\
			src/input/ft_atoi.c
OBJ	= ${SRC_S:.c=.o}
CC		= gcc
RM		= rm -f
HEADER	= -I Libft/
CFLAGS	= -Wall -Werror -Wextra -g #-fsanitize=address

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

checker:
				@${MAKE} -C checker --no-print-directory

.PHONY: all clean fclean re libft