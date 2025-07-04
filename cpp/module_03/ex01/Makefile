CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iinclude
# DFLAGS	= -g -pg

NAME	= scavtrap
BIN_DIR	= bin/
SRC_DIR	= src/
OBJ_DIR	= obj/

SRCS	= $(shell ls $(SRC_DIR) | grep -E '\.cpp$$')
OBJS	= $(SRCS:.cpp=.o)

SRC		= $(addprefix $(SRC_DIR), $(SRCS))
OBJ		= $(addprefix $(OBJ_DIR), $(OBJS))

all: $(BIN_DIR)$(NAME)

$(BIN_DIR)$(NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJ) -o $@

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

$(NAME): $(BIN_DIR)$(NAME)

clean:
	rm -f $(OBJ_DIR)*.o a.out

fclean: clean
	rm -rf $(BIN_DIR)$(NAME) $(BIN_DIR) $(OBJ_DIR)

re: clean run

run: all
	@./$(BIN_DIR)$(NAME)

debug:
	$(CC) $(CFLAGS) $(OBJ) -g -pg

mleak: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./$(BIN_DIR)$(NAME)

.PHONY: all clean re run test
