CC		= cc
CFLAGS	= -Wall -Wextra -Werror -c

SRCDIR	= srcs
INCDIR	= includes

SRCS	= $(wildcard $(SRCDIR)/*.c)
OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

RM		= rm -f

.PHONY:		all clean fclean re
all:		$(NAME)

%.o: %.c
			$(CC) $(CFLAGS) $< -o $@ -I$(INCDIR)

$(NAME):	$(OBJS)
			ar rcs $@ $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
