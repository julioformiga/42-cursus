CC			= cc
CFLAGS		= -Wall -Wextra -Werror -std=c99 -I../../include -c -O2
MAKEFLAGS	+= --no-print-directory

RM			= rm -rf
AR			= ar src

SRC			= src
OBJ			= obj
SRC_PRINTF	= $(SRC)/ft_printf
OBJ_PRINTF	= $(SRC_PRINTF)/obj
SRCS		= $(wildcard $(SRC)/*.c)
OBJS		= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
SRCS_PRINTF	= $(wildcard $(SRC_PRINTF)/*.c)
OBJS_PRINTF	= $(patsubst $(SRC_PRINTF)/%.c, $(OBJ_PRINTF)/%.o, $(SRCS_PRINTF))

NAME		= libft.a

GREEN  = \033[0;32m
YELLOW = \033[1;33m
BLUE   = \033[1;34m
RED    = \033[0;31m
RESET  = \033[0m

all:		$(NAME)

$(OBJ)/%.o:	$(SRC)/%.c
			@if [ ! -d $(OBJ) ]; then mkdir $(OBJ); fi
			@echo -e "\t☑️ libft/$@"
			@$(CC) $(CFLAGS) $< -o $@

$(OBJ_PRINTF)/%.o:	$(SRC_PRINTF)/%.c
			@if [ ! -d $(OBJ_PRINTF) ]; then mkdir $(OBJ_PRINTF); fi
			@echo -e "\t☑️ ft_printf/$@"
			@$(CC) $(CFLAGS) $< -o $@

$(NAME):	$(OBJS) $(OBJS_PRINTF)
			@$(AR) $@ $(OBJS) $(OBJS_PRINTF)
			@echo -e "✅ $(GREEN)Build finished$(RESET): $@"

clean:
			@$(RM) $(OBJ) $(OBJ_PRINTF)
			@echo -e "🧹 $(RED)Cleaning LIB_FT$(RESET): $(OBJ) $(OBJ_PRINTF)"

fclean:		clean
			@echo -e "🧹 $(RED)Cleaning LIB_FT$(RESET): $(NAME) vgcore.* a.out"
			@$(RM) vgcore.* a.out
			@$(RM) $(NAME)

re:			fclean all

.SILENT:	all clean fclean re
.PHONY:		all clean fclean re
