CC			= cc
CFLAGS		= -Wall -Werror -Wextra -std=c99 -g
RM			= rm -f
AR			= ar -src

SRC			= ft_printf.c ft_printf_cspui.c ft_printf_uhex.c ft_printf_parser.c \
			  ft_printf_uitoa.c ft_printf_itoa_base.c
OBJ			= $(SRC:.c=.o)

LIBFT_DIR	= libft/

SRCS_LIBFT	= $(wildcard $(LIBFT_DIR)ft_*.c)
OBJS_LIBFT	= $(SRCS_LIBFT:.c=.o)

NAME		= libftprintf.a

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			$(AR) $@ $(OBJ)
			make all -C $(LIBFT_DIR)
			make bonus -C $(LIBFT_DIR)
			$(AR) $@ $(OBJS_LIBFT)

clean:
			$(RM) $(OBJ)
			make clean -C $(LIBFT_DIR)

fclean:		clean
			$(RM) main *.o *.a a.out
			$(RM) $(LIBFT_DIR)main $(LIBFT_DIR)a.out
			$(RM) $(LIBFT_DIR)*.o $(LIBFT_DIR)*.a

bonus:		all

re:			fclean all

run:
			$(CC) $(SRC) $(NAME) $(CFLAGS) && ./a.out

.PHONY:		all clean fclean re run
