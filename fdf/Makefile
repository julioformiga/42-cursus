CC		= cc
INCLUDE	= -Iinclude
CFLAGS	= -Wall -Werror -Wextra -g -O3 $(INCLUDE)
XFLAGS	= -lX11 -lXext -lm -lz
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
SRC_LIBFT		= $(wildcard $(FT_PRINTF_DIR)libft/*.c)
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

run:	all debug
		$(CC) $(CFLAGS) $(XFLAGS) $(NAME) -o fdf
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./fdf assets/test_maps/42.fdf
#		valgrind --leak-check=full --show-leak-kinds=all ./fdf assets/test_maps/42.fdf
#		./fdf assets/test_maps/42.fdf
#		./fdf assets/test_maps/basictest.fdf

debug:	all
		$(CC) $(CFLAGS) $(XFLAGS) $(NAME) -g -o a.out


.SILENT:	all clean fclean re
.PHONY:		all clean fclean re run
