CC			= cc
INCLUDE		= -Iinclude
CFLAGS		= -Wall -Wextra -Werror $(INCLUDE) -std=c99
RM			= rm -f
AR			= ar -src

NAME = pipex.a

SRC 	= $(wildcard src/*.c) pipex.c
OBJS 	= $(SRC:.c=.o)

FT_PRINTF_DIR	= lib/ft_printf/
FT_LIBFT_DIR	= $(FT_PRINTF_DIR)libft/
SRCS_FT_PRINTF	= $(wildcard $(FT_PRINTF_DIR)*.c)
OBJS_FT_PRINTF	= $(SRCS_FT_PRINTF:.c=.o)
SRCS_LIBFT		= $(wildcard $(FT_PRINTF_DIR)libft/ft_*.c)
OBJS_LIBFT		= $(SRCS_LIBFT:.c=.o)
FT_PRINTF_A		= $(FT_PRINTF_DIR)libftprintf.a

all:	$(NAME)

$(NAME):	$(OBJS)
			make all -C $(FT_PRINTF_DIR)
			$(AR) $@ $(OBJS) $(OBJS_LIBFT) $(OBJS_FT_PRINTF)

clean:
		$(RM) $(OBJS)
		make clean -C $(FT_PRINTF_DIR)

fclean:	clean
		$(RM) $(NAME) pipex a.out
		$(RM) *.a *.o src/*.o *.o vgcore.*
		make fclean -C $(FT_PRINTF_DIR)

re:		fclean all

run:	all
		$(CC) $(CFLAGS) $(NAME) -o pipex
#		echo "content01.txt" > "file01.txt"
#		echo "content02.txt" > "file02.txt"
#		./pipex
		./pipex input.txt "grep a1" "wc -w" output.txt
#		bat file0*
#		< file01.txt seq 0 11 | cat > file03.txt
#		bat file0*

debug:	all
		$(CC) $(CFLAGS) $(NAME) -g

.SILENT:	all clean fclean re run debug $(NAME)
.PHONY:		all clean fclean re run debug
