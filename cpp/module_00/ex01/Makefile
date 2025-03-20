NAME	= phonebook

CC		= c++

CFLAGS	= -Wall -Wextra -Werror -std=c++98

BIN_DIR	= bin/
SRC_DIR	= src/
OBJ_DIR	= obj/
INC_DIR	= include/

SRCS	= main.cpp
OBJS	= $(SRCS:.cpp=.o)

SRC		= $(addprefix $(SRC_DIR), $(SRCS))
OBJ		= $(addprefix $(OBJ_DIR), $(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) $(OBJ) -o $(BIN_DIR)$(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)*.o

fclean: clean
	@rm -rf $(BIN_DIR)$(NAME) $(BIN_DIR) $(OBJ_DIR)

re: clean all

run: all
	@./$(BIN_DIR)$(NAME)
#	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BIN_DIR)$(NAME)

.PHONY: all clean re run test
