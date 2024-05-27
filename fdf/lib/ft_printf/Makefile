CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g -std=c99
RM			= rm -f
AR			= ar -src

SRC			= $(wildcard *.c)
OBJ			= $(SRC:.c=.o)

LIBFT_DIR	= libft/
LIBFT_A		= $(LIBFT_DIR)libft.a

SRCS_LIBFT	= $(wildcard $(LIBFT_DIR)*.c)
OBJS_LIBFT	= $(SRCS_LIBFT:.c=.o)

NAME		= libftprintf.a

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			@make all -C $(LIBFT_DIR)
			@$(AR) $@ $(OBJ) $(OBJS_LIBFT)

clean:
			$(RM) $(OBJ)
			@make clean -C $(LIBFT_DIR)

fclean:		clean
			$(RM) main *.o *.a a.out
			$(RM) $(LIBFT_DIR)main $(LIBFT_DIR)a.out
			$(RM) $(LIBFT_DIR)*.o $(LIBFT_DIR)*.a
			$(RM) vgcore.*

re:			fclean all

run:
			$(CC) $(SRC) $(NAME) $(CFLAGS)
#			./a.out
			valgrind --leak-check=full --show-leak-kinds=all -s ./a.out

.SILENT:	all clean fclean re
.PHONY:		all clean fclean re run
