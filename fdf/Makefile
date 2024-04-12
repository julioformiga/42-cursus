CC		= cc
INCLUDE	= -Iinclude
CFLAGS	= -Wall -Werror -Wextra -std=c99 $(INCLUDE)
XFLAGS	= -lX11 -lXext -lz -lm
RM		= rm -f
AR		= ar -src

NAME	= fdf.a

SRC	= $(wildcard src/*.c)
OBJ	= $(SRC:.c=.o)

MINILIBX_DIR	= lib/minilibx/
FT_PRINTF_DIR	= lib/ft_printf/
FT_LIBFT_DIR	= $(FT_PRINTF_DIR)libft/
SRC_FT_PRINTF	= $(wildcard $(FT_PRINTF_DIR)*.c)
OBJ_FT_PRINTF	= $(SRC_FT_PRINTF:.c=.o)
SRC_LIBFT		= $(wildcard $(FT_PRINTF_DIR)libft/ft_*.c)
OBJ_LIBFT		= $(SRC_LIBFT:.c=.o)
FT_PRINTF_A		= $(FT_PRINTF_DIR)libftprintf.a
LIBMXL_A		= $(MINILIBX_DIR)libmlx.a
SRC_LIBMXL		= $(wildcard $(MINILIBX_DIR)*.c)
OBJ_LIBMXL		= $(wildcard $(MINILIBX_DIR)obj/*.o)

all:	$(NAME)

%.o:	%.c
		$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			@make all -C $(FT_PRINTF_DIR)
			@make all -C $(MINILIBX_DIR)
			$(AR) $@ $(OBJ) $(OBJ_LIBFT) $(OBJ_FT_PRINTF) $(OBJ_LIBMXL)

clean:
		$(RM) $(OBJ)
		make clean -C $(FT_PRINTF_DIR)
#		make clean -C $(MINILIBX_DIR)

fclean:	clean
		$(RM) $(NAME) a.out fdf
		$(RM) *.a *.o src/*.o *.o vgcore.*
		make fclean -C $(FT_PRINTF_DIR)

re:		fclean all

run:	all
		$(CC) $(CFLAGS) $(XFLAGS) $(NAME) -o fdf
		./fdf

debug:	all
		$(CC) $(CFLAGS) $(XFLAGS) $(NAME) -g


.SILENT:	all clean fclean re
.PHONY:		all clean fclean re run
