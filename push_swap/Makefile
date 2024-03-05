CC			= cc
INCLUDES	= -Iincludes
CFLAGS		= -Wall -Wextra -Werror -std=c99 $(INCLUDES)
RM			= rm -f
AR			= ar -src

NAME		= push_swap.a
NAME_BONUS	= bonus.a

SRCS		= $(wildcard src/*.c) push_swap.c
SRCS_BONUS	= $(wildcard src/*.c) bonus.c

FT_PRINTF_DIR	= includes/ft_printf/
FT_LIBFT_DIR	= $(FT_PRINTF_DIR)libft/
SRCS_FT_PRINTF	= $(wildcard $(FT_PRINTF_DIR)*.c)
OBJS_FT_PRINTF	= $(SRCS_FT_PRINTF:.c=.o)
SRCS_LIBFT		= $(wildcard $(FT_PRINTF_DIR)libft/ft_*.c)
OBJS_LIBFT		= $(SRCS_LIBFT:.c=.o)
OBJS			= $(SRCS:.c=.o)
OBJS_BONUS		= $(SRCS_BONUS:.c=.o)
FT_PRINTF_A		= $(FT_PRINTF_DIR)libftprintf.a

all:		$(NAME)
			$(CC) $(CFLAGS) $(NAME) -o push_swap

$(NAME):	$(OBJS)
			make all -C $(FT_PRINTF_DIR)
			$(AR) $@ $(OBJS) $(OBJS_LIBFT) $(OBJS_FT_PRINTF)

$(NAME_BONUS):	$(OBJS_BONUS)
				make all -C $(FT_PRINTF_DIR)
				$(AR) $@ $(OBJS_BONUS) $(OBJS_LIBFT) $(OBJS_FT_PRINTF)

clean:
			$(RM) $(OBJS)
			make clean -C $(FT_PRINTF_DIR)

fclean:		clean
			$(RM) $(NAME) push_swap bonus checker a.out
			$(RM) *.a *.o src/*.o *.o vgcore.*
			make fclean -C $(FT_PRINTF_DIR)

bonus:		$(NAME_BONUS)
			$(CC) $(CFLAGS) $(NAME_BONUS) -o checker

re:			fclean all

run:		all
			@$(CC) $(CFLAGS) $(NAME) -o push_swap
#			@./push_swap $$(seq 0 99 | shuf | tr "\n" " ")
#			@./push_swap $$(seq -100 400 | shuf | tr "\n" " ") | wc -l
#			valgrind --leak-check=full -s ./push_swap $$(seq 0 99 | shuf | tr "\n" " ") | wc -l
#			valgrind --leak-check=full -s ./push_swap $$(seq -100 400 | shuf | tr "\n" " ") | wc -l
#			@./push_swap $$(seq -1 499 | shuf | tr "\n" " ") | wc -l
#			@./push_swap $$(seq -1000 4 | shuf | tr "\n" " ") | wc -l
#			@./push_swap $$(seq 0 99 9850 | shuf | tr "\n" " ") | wc -l
#			@./push_swap $$(seq 0 19 9490 | shuf | tr "\n" " ") | wc -l
#			./push_swap $$(seq 20948409 20948509 | shuf | tr "\n" " ") | wc -l
#			./push_swap $$(seq 20948509 20949009 | shuf | tr "\n" " ") | wc -l
#			./push_swap "1 2 -3 0 -5"
#			bash ./utils/generate_numbers.sh 0123456789
#			./push_swap "2 3 6 5 1 8" | wc -l
#			24 mosse
#			./push_swap "6 8 7 9 3 1 10 2 0 4 5"
#			./push_swap "6 8 7 9 3 1 10 2 0 4 5" | wc -l
			./checker "6 8 7 9 -2147483647 3 1 -100 2 2147483647 0 4 5"
			./push_swap "6 8 7 9 -2147483647 3 1 -100 2 2147483647 0 4 5" | wc -l
#			valgrind --leak-check=full -s ./push_swap "2 1 3 6 -1 5 8 0 9 4 10"
#			./push_swap "0 5 2 4 3 1" | wc -l
#			./push_swap "10 5 2 4 3 0 1 -2" | wc -l
#			./push_swap "10 5 2 4 3 0 1 -2" | ./checker_linux "10 5 2 4 3 0 1 -2"
#			valgrind --leak-check=full -s ./push_swap "2 1 3 6 5 8"
#			ARG="2 1 3 6 5 8"; ./push_swap $$ARG | ./checker_linux $$ARG
#			ARG="1 3 2 2147483647 -3 0 -5"; ./push_swap $$ARG -2147483648 4 -1 "6 -2"
#			ARG="1 3 2 2147483647 -3 0 -5"; valgrind --leak-check=full -s ./push_swap $$ARG -2147483648 4 -1 "6 -2"
#			./push_swap 1 "  -2 	+11   "  5 	one -3  --5" - 90a   -19r4   	" - 7
#			valgrind --leak-check=full -s ./push_swap $ARG
#			./push_swap 1 "  -2 5 -1	+11  2147483645 " 2147483644 0 3 -2147483648	 -3  -5 "  90   -194   " 4
#			./push_swap "1 5 2" 8 "4 3"
#			./push_swap 99 -21474836481 2147483647 0
#			./push_swap 2 1 3 6 5 8

.SILENT: all bonus clean fclean re
.PHONY: all bonus clean fclean re
