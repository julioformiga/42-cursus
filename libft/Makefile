CC		= cc
CFLAGS	= -Wall -Wextra -Werror -c

SRCDIR	= srcs
INCDIR	= .

SRCS	= $(wildcard $(SRCDIR)/*.c)
OBJS	= $(SRCS:.c=.o)

NAME	= libft.a

RM		= rm -f

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

.PHONY:		all clean fclean re
