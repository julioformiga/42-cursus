CC			= cc
CFLAGS		= -Wall -Werror -Wextra -std=c99 -c
RM			= rm -f
AR			= ar -src

SRC			= ft_printf.c
OBJ			= $(SRC:.c=.o)

LIBFT_DIR	= libft/
LIBFT_A		= libft.a

NAME		= libftprintf.a

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $< -o $@

$(NAME):	$(OBJ)
			$(AR) $@ $(OBJ)
			make all -C $(LIBFT_DIR)
			cp $(LIBFT_DIR)$(LIBFT_A) .

clean:
			$(RM) $(OBJ)
			make clean -C $(LIBFT_DIR)

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT_A)
			$(RM) main
			$(RM) a.out
			make fclean -C $(LIBFT_DIR)

re:			fclean all

.PHONY:		all clean fclean re
