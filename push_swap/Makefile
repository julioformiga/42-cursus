CC			= cc
INCLUDES	= -Ilib
CFLAGS		= -Wall -Wextra -Werror -g -std=c99 $(INCLUDES)
RM			= rm -f
AR			= ar -src

NAME		= push_swap.a

SRCS		= $(wildcard src/*.c)

FT_PRINTF_DIR	= lib/ft_printf/
FT_LIBFT_DIR	= $(FT_PRINTF_DIR)libft/
SRCS_FT_PRINTF	= $(wildcard $(FT_PRINTF_DIR)*.c)
OBJS_FT_PRINTF	= $(SRCS_FT_PRINTF:.c=.o)
SRCS_LIBFT		= $(wildcard $(FT_PRINTF_DIR)libft/ft_*.c)
OBJS_LIBFT		= $(SRCS_LIBFT:.c=.o)
OBJS			= $(SRCS:.c=.o)
FT_PRINTF_A		= $(FT_PRINTF_DIR)libftprintf.a

all:		$(NAME)

$(NAME):	$(OBJS)
			make all -C $(FT_PRINTF_DIR)
			@$(AR) $@ $(OBJS) $(OBJS_LIBFT) $(OBJS_FT_PRINTF)

clean:
			$(RM) $(OBJS)
			make clean -C $(FT_PRINTF_DIR)

fclean:		clean
			$(RM) $(NAME) push_swap
			$(RM) src/*.o *.o vgcore.*
			make fclean -C $(FT_PRINTF_DIR)

re:			fclean all

run:		all
			@$(CC) $(CFLAGS) $(NAME)
#			./a.out $$(seq -100 100 | shuf | tr "\n" " ")
#			./a.out "1 2 -3 0 -5"
			sh ./utils/generate_numbers.sh 123456
#			./a.out "2 3 6 5 1 8"
#			./a.out "2 1 3 6 5 8"
#			valgrind --leak-check=full -s ./a.out "2 1 3 6 5 8"
#			ARG="2 1 3 6 5 8"; ./a.out $$ARG | ./checker_linux $$ARG
#			ARG="1 3 2 2147483647 -3 0 -5"; ./a.out $$ARG -2147483648 4 -1 "6 -2"
#			ARG="1 3 2 2147483647 -3 0 -5"; valgrind --leak-check=full -s ./a.out $$ARG -2147483648 4 -1 "6 -2"
#			./push_swap 1 "  -2 	+11   "  5 	one -3  --5" - 90a   -19r4   	" - 7
#			valgrind --leak-check=full -s ./a.out $ARG
#			./a.out 1 "  -2 5 -1	+11  2147483645 " 2147483644 0 3 -2147483648	 -3  -5 "  90   -194   " 4
#			./push_swap "1 5 2" 8 "4 3"
#			./push_swap 99 -21474836481 2147483647 0
#			./push_swap 2 1 3 6 5 8

.SILENT: all clean fclean re
.PHONY: all clean fclean re
