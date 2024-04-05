CC		= cc
INCLUDE	= -Iinclude
CFLAGS	= -Wall -Werror -Wall -std=c99 -g $(INCLUDE)
RM		= rm -f
AR		= ar -src

NAME	= fdf.a

SRC	= src/fdf.c
OBJ	= $(addprefix obj/,$(SRCS:.c=.o))

MINILIBX_DIR	= lib/minilibx/
FT_PRINTF_DIR	= lib/ft_printf/
FT_LIBFT_DIR	= $(FT_PRINTF_DIR)libft/
SRC_FT_PRINTF	= $(wildcard $(FT_PRINTF_DIR)*.c)
OBJ_FT_PRINTF	= $(SRC_FT_PRINTF:.c=.o)
SRC_LIBFT		= $(wildcard $(FT_PRINTF_DIR)libft/ft_*.c)
OBJ_LIBFT		= $(SRC_LIBFT:.c=.o)
FT_PRINTF_A		= $(FT_PRINTF_DIR)libftprintf.a
LIBMXL_A		= $(MINILIBX_DIR)libmlx.a
LIBMXL_O		= $(wildcard $(MINILIBX_DIR)obj/*.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			make all -C $(FT_PRINTF_DIR)
			make all -C $(MINILIBX_DIR)
			$(AR) $@ $(OBJ) $(OBJ_LIBFT) $(OBJ_FT_PRINTF) $(LIBMXL_O)
			$(CC) $(CFLAGS) $(NAME) -o fdf

clean:
		$(RM) $(OBJ)
		make clean -C $(FT_PRINTF_DIR)
		make clean -C $(MINILIBX_DIR)

fclean:	clean
		$(RM) $(NAME) a.out fdf
		$(RM) *.a *.o src/*.o *.o vgcore.*
		make fclean -C $(FT_PRINTF_DIR)

re:		fclean all

run:	$(NAME)
		$(CC) $(CFLAGS) $(NAME) -o fdf
		./fdf

# .SILENT:	all $(NAME) clean fclean re
.PHONY:		all $(NAME) clean fclean re run
