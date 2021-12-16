NAME	= checker
SRC_S	= main.c \
			../src/input/indexing.c ../src/input/lst_options.c \
			../src/actions/push.c ../src/actions/rotate.c ../src/actions/swap.c \
			../src/minsteps/is_sorted.c\
			../src/input/ft_atoi.c\
			do_push.c do_swap.c do_rotate.c do_rev_rotate.c\
			execute_step.c check_series.c\
			\
			../src/narrow/sort.c ../src/narrow/sort_b.c\
			../src/narrow/sort_utils.c ../src/narrow/split_two.c\
			../src/solve/general.c ../src/solve/quicksolve.c\
			../src/minsteps/solve3.c
OBJ	= ${SRC_S:.c=.o}
CC		= gcc
RM		= rm -f
HEADER	= -I ../Libft/
CFLAGS	= -Wall -Werror -Wextra -g

all:		${NAME}

.c.o:
				@${CC} -c ${CFLAGS} ${HEADER} $< -o ${<:.c=.o}

clean:
				@${RM} ${OBJ} \
				$(info ************  checker Clean)

fclean:		clean
				@${RM} ${NAME} \
				$(info ************  checker Removed)

re:			fclean all

${NAME}:	${OBJ} ../Libft/libft.a
				@${CC} -o $@ $^ \
				$(info ************  checker Ready!)

../Libft/libft.a:
				@${MAKE} -C Libft --no-print-directory

.PHONY: all clean fclean re