CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude -lreadline -g
MAKEFLAGS	+= --no-print-directory -s

RM			= rm -rf
AR			= ar src

SRC			= src
OBJ			= obj
SRCS		= $(wildcard $(SRC)/*.c)
OBJS		= $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
BIN_DIR		= bin
BIN			= $(BIN_DIR)/minishell

LIBFT_DIR	= lib/libft
LIBFT		= $(LIBFT_DIR)/libft.a

GREEN  		= \033[0;32m
YELLOW 		= \033[1;33m
BLUE   		= \033[1;34m
RED    		= \033[0;31m
RESET  		= \033[0m

all:		$(BIN)
			echo -e "☑️ $(GREEN)Compiled in$(RESET): $(BIN)"

$(OBJ)/%.o:	$(SRC)/%.c
			if [ ! -d $(OBJ) ]; then mkdir $(OBJ); fi
			if [ ! -d $(BIN_DIR) ]; then mkdir $(BIN_DIR); fi
			$(CC) $(CFLAGS) -c -o $@ $<

$(BIN):		$(OBJS)
			echo -e "⚙️  $(BLUE)Building LIB_FT$(RESET)"
			make all -C $(LIBFT_DIR)
			echo -e "⚙️  $(BLUE)Building MINISHELL$(RESET)"
			$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)

clean:
			$(RM) $(OBJ)
			echo -e "🧹 $(RED)Cleaning$(RESET): $(OBJ)"

fclean:		clean
			echo -e "🧹 $(RED)Cleaning$(RESET): $(BIN_DIR) vgcore.* a.out"
			$(RM) $(BIN_DIR)
			$(RM) vgcore.* a.out
			make fclean -C $(LIBFT_DIR)
			echo -e "🧹 $(RED)Cleaning$(RESET): build/"
			cd build/ && make clean && cd ..

re:			fclean all

run:		all
			cd build/ && cmake .. && make && ctest && cd ..
			echo -e "🚀 $(YELLOW)Running$(RESET): $(BIN)"
			./$(BIN)
#			valgrind --leak-check=full --suppressions=readline.supp ./$(BIN)
#			valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp -s ./$(BIN)

.SILENT:	all clean fclean re run
.PHONY:		all clean fclean re run
