CC			= cc
CFLAGS		= -Wall -Werror -Wextra -std=c99 -c
RM			= rm -f
AR			= ar -src

SRC			= ft_printf.c
OBJ			= $(SRC:.c=.o)

LIBFT_DIR	= libft/
LIBFT_A		= libft.a

SRCS_LIBFT	= $(wildcard $(LIBFT_DIR)ft_*.c)
OBJS_LIBFT	= $(SRCS_LIBFT:.c=.o)

NAME		= libftprintf.a

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $< -o $@

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

re:			fclean all

.PHONY:		all clean fclean re
