CC		= cc
CFLAGS	= -Wall -Wextra -Werror -std=c99 -c

SRCS_BONUS	= $(wildcard ft_lst*.c)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

SRCS		= $(filter-out $(SRCS_BONUS), $(wildcard ft_*.c))
OBJS		= $(SRCS:.c=.o)

NAME		= libft.a

RM			= rm -f

all:		$(NAME)

%.o: %.c
			$(CC) $(CFLAGS) $< -o $@

$(NAME):	$(OBJS)
			ar rcs $@ $(OBJS)

bonus:		$(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS_BONUS)

$(OBJS_BONUS):	$(SRCS_BONUS)
				$(CC) $(CFLAGS) $< -o $@

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
