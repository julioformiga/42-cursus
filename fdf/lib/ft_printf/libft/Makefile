CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g -std=c99 -c
RM		= rm -f
AR		= ar -src

SRCS		= $(wildcard *.c)
OBJS		= $(SRCS:.c=.o)

NAME		= libft.a

all:		$(NAME)

%.o: %.c
			$(CC) $(CFLAGS) $< -o $@

$(NAME):	$(OBJS)
			$(AR) $@ $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.SILENT: 	all clean fclean re
.PHONY:		all clean fclean re
