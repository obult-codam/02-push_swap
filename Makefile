# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: obult <obult@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2021/12/17 17:07:06 by obult         #+#    #+#                  #
#    Updated: 2023/07/01 17:25:01 by obult         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

export DYLD_FALLBACK_LIBRARY_PATH=/Users/obult/ft_malloc

NAME	= push_swap
SRC_S	= main.c \
			src/input/indexing.c src/input/lst_options.c \
			src/actions/push.c src/actions/rotate.c src/actions/swap.c \
			src/narrow/sort.c src/narrow/sort_b.c src/narrow/sort_utils.c \
			src/narrow/split_two.c\
			src/solve/general.c src/solve/quicksolve.c\
			src/minsteps/is_sorted.c src/minsteps/solve3.c\
			src/input/ft_atoi.c
OBJ	= ${SRC_S:.c=.o}
CC		= gcc
RM		= rm -f
HEADER	= -I Libft/ #../ft_malloc/lib/
CFLAGS	= -Wall -Werror -Wextra -g
MALLOCLIB := /Users/obult/ft_malloc/libft_malloc.so

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
				&& ${MAKE} fclean -C Libft --no-print-directory \
				&& ${MAKE} fclean -C ../ft_malloc

re:			fclean all

${NAME}:	${OBJ} Libft/libft.a
				@${CC} -o $@ $^ \
				$(info ************  push_swap Ready!)

${MALLOCLIB}:
				${MAKE} -C ../ft_malloc --no-print-directory

malloc:		${OBJ} Libft/libft.a ${MALLOCLIB}
				${CC} -o ${NAME} -L. ${MALLOCLIB} $^ \
				$(info ************  push_swap Ready --with malloc--!)

Libft/libft.a:
				@${MAKE} -C Libft --no-print-directory

checker:
				@${MAKE} -C check --no-print-directory

test:		${NAME}
				export DYLD_FALLBACK_LIBRARY_PATH=/Users/obult/ft_malloc && \
				./ps_test.sh

.PHONY: all clean fclean re libft
