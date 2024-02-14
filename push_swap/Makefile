CC			= cc
INCLUDES	= -Ilib
CFLAGS		= -Wall -Wextra -Werror -std=c99 $(INCLUDES)
RM			= rm -f
AR			= ar -src

NAME		= push_swap.a

SRCS		= $(wildcard src/*.c)

FT_PRINTF_DIR	= lib/ft_printf/
FT_LIBFT_DIR	= $(FT_PRINTF_DIR)libft/
SRCS_FT_PRINTF	= $(wildcard $(FT_PRINTF_DIR)*.c)
OBJS_FT_PRINTF	= $(SRCS_FT_PRINTF:.c=.o)
SRCS_LIBFT		= $(wildcard $(FT_PRINTF_DIR)libft/ft_*.c)
OBJS_LIBFT		= $(SRCS_LIBFT:.c=.o)

OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			make all -C $(FT_PRINTF_DIR)
			make bonus -C $(FT_PRINTF_DIR)
			$(AR) $@ $(OBJS) $(OBJS_FT_PRINTF) $(OBJS_LIBFT)

clean:
			$(RM) $(OBJS)
			make clean -C $(FT_PRINTF_DIR)

fclean:		clean
			$(RM) $(NAME) push_swap
			make fclean -C $(FT_PRINTF_DIR)

re:			fclean all

run:		all
			$(CC) $(CFLAGS) $(NAME) -o push_swap
#			./push_swap 1 "  -2 	+11   "  5 	one -3  --5" - 90a   -19r4   	" - 7
			./push_swap 1 "  -2 	+11   "  5 	 -3  -5"  90   -194   	"  7
# ./push_swap "1 5 2" 8 "4 3"
# ./push_swap 99 -21474836481 2147483647 0
# ./push_swap 2 1 3 6 5 8

.SILENT: all clean fclean re
.PHONY: all clean fclean re
