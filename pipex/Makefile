CC			= cc
INCLUDE		= -Iinclude
CFLAGS		= -Wall -Wextra -Werror -g -std=c99 $(INCLUDE)
RM			= rm -f
AR			= ar -src

NAME		= pipex.a
NAME_BONUS	= pipex_bonus.a

SRCS 		= src/pipex.c src/utils.c
OBJS 		= $(SRCS:.c=.o)
SRCS_BONUS 	= src/pipex_bonus.c src/utils.c
OBJS_BONUS 	= $(SRCS_BONUS:.c=.o)

FT_PRINTF_DIR	= lib/ft_printf/
FT_LIBFT_DIR	= $(FT_PRINTF_DIR)libft/
SRCS_FT_PRINTF	= $(wildcard $(FT_PRINTF_DIR)*.c)
OBJS_FT_PRINTF	= $(SRCS_FT_PRINTF:.c=.o)
SRCS_LIBFT		= $(wildcard $(FT_PRINTF_DIR)libft/ft_*.c)
OBJS_LIBFT		= $(SRCS_LIBFT:.c=.o)
FT_PRINTF_A		= $(FT_PRINTF_DIR)libftprintf.a

all:	$(NAME)

bonus:	$(NAME) $(NAME_BONUS)

$(NAME):	$(OBJS)
			make all -C $(FT_PRINTF_DIR)
			$(AR) $@ $(OBJS) $(OBJS_LIBFT) $(OBJS_FT_PRINTF)
			$(CC) $(CFLAGS) $(NAME) -o pipex

$(NAME_BONUS):	$(OBJS_BONUS)
				make all -C $(FT_PRINTF_DIR)
				$(AR) $@ $(OBJS_BONUS) $(OBJS_LIBFT) $(OBJS_FT_PRINTF)
				$(CC) $(CFLAGS) $(NAME_BONUS) -o pipex

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)
		make clean -C $(FT_PRINTF_DIR)

fclean:	clean
		$(RM) $(NAME) $(NAME_BONUS) a.out pipex
		$(RM) *.a *.o src/*.o *.o vgcore.*
		make fclean -C $(FT_PRINTF_DIR)

re:		fclean all

SHELL		= /bin/bash
.ONESHELL:

test:
		[ ! -d "pipe-tester" ] && git clone https://github.com/vfurmane/pipex-tester.git
		cd pipex-tester
		./run.sh

rmtest:
		rm -rf pipex-tester
		rm -rf pipexMedic

CMD1 = "grep include"
# CMD1 = "ls as"
# CMD1 = "notfound"
CMD2 = "cat"

run:	all
#		$(CC) $(CFLAGS) $(NAME) -o pipex
#		$(CC) $(CFLAGS) $(NAME_BONUS) -o pipex
#		echo "content01.txt" > "file01.txt"
#		echo "content02.txt" > "file02.txt"
#		./pipex
#		./pipex input.txt "grep dup" "cat" output.txt
#		valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes -s ./pipex input.txt $(CMD1) $(CMD2) output.txt
#		valgrind --leak-check=full --show-leak-kinds=all ./pipex input.txt $(CMD1) $(CMD2) output.txt
		./pipex input.txt $(CMD1) $(CMD2) output.txt
#		./pipex input.txt $(CMD1) $(CMD2)
		cat output.txt
#		< input.txt $(CMD1) | $(CMD2) > output.txt

.SILENT:	all clean fclean re bonus $(NAME)
.PHONY:		all clean fclean re bonus run
