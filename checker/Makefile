NAME	= checker
SRC_S	= main.c \
			../src/input/indexing.c ../src/input/lst_options.c \
			../src/actions/push.c ../src/actions/rotate.c ../src/actions/swap.c \
			../src/minsteps/is_sorted.c\
			../src/input/ft_atoi.c\
			do_push.c do_swap.c do_rotate.c do_rev_rotate.c\
			execute_step.c check_series.c
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
				$(info ************  checker Removed) \

re:			fclean all

${NAME}:	${OBJ}
				${CC} -o $@ $^ 

.PHONY: all clean fclean re libft