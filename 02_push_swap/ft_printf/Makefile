CC			= cc
CFLAGS		= -Wall -Werror -Wextra -std=c99 -g
RM			= rm -f
AR			= ar -src

SRC			= ft_printf.c ft_printf_print.c ft_printf_get_strings.c ft_printf_format.c \
			  ft_printf_pre_format_space_plus.c ft_uitoa.c ft_itoa_base.c
OBJ			= $(SRC:.c=.o)

LIBFT_DIR	= libft/

# SRCS_LIBFT	= $(wildcard $(LIBFT_DIR)ft_*.c)
SRCS_LIBFT	= $(LIBFT_DIR)ft_isalpha.c \
			  $(LIBFT_DIR)ft_isdigit.c \
			  $(LIBFT_DIR)ft_isalnum.c \
			  $(LIBFT_DIR)ft_isascii.c \
			  $(LIBFT_DIR)ft_isprint.c \
			  $(LIBFT_DIR)ft_strlen.c \
			  $(LIBFT_DIR)ft_memset.c \
			  $(LIBFT_DIR)ft_bzero.c \
			  $(LIBFT_DIR)ft_memcpy.c \
			  $(LIBFT_DIR)ft_memmove.c \
			  $(LIBFT_DIR)ft_strlcpy.c \
			  $(LIBFT_DIR)ft_strlcat.c \
			  $(LIBFT_DIR)ft_toupper.c \
			  $(LIBFT_DIR)ft_tolower.c \
			  $(LIBFT_DIR)ft_strchr.c \
			  $(LIBFT_DIR)ft_strrchr.c \
			  $(LIBFT_DIR)ft_strncmp.c \
			  $(LIBFT_DIR)ft_memchr.c \
			  $(LIBFT_DIR)ft_memcmp.c \
			  $(LIBFT_DIR)ft_strnstr.c \
			  $(LIBFT_DIR)ft_atoi.c \
			  $(LIBFT_DIR)ft_calloc.c \
			  $(LIBFT_DIR)ft_strdup.c \
			  $(LIBFT_DIR)ft_substr.c \
			  $(LIBFT_DIR)ft_strjoin.c \
			  $(LIBFT_DIR)ft_strtrim.c \
			  $(LIBFT_DIR)ft_split.c \
			  $(LIBFT_DIR)ft_itoa.c \
			  $(LIBFT_DIR)ft_strmapi.c \
			  $(LIBFT_DIR)ft_striteri.c \
			  $(LIBFT_DIR)ft_putchar_fd.c \
			  $(LIBFT_DIR)ft_putstr_fd.c \
			  $(LIBFT_DIR)ft_putendl_fd.c \
			  $(LIBFT_DIR)ft_putnbr_fd.c
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
			$(CC) $(SRC) $(NAME) $(CFLAGS)
			./a.out
#			valgrind --leak-check=full --show-leak-kinds=all -s ./a.out

.PHONY:		all clean fclean re run
