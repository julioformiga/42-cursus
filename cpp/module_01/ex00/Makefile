CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -Iinclude

NAME	= brainz
BIN_DIR	= bin/
SRC_DIR	= src/
OBJ_DIR	= obj/

SRCS	= main.cpp Zombie.cpp
OBJS	= $(SRCS:.cpp=.o)

SRC		= $(addprefix $(SRC_DIR), $(SRCS))
OBJ		= $(addprefix $(OBJ_DIR), $(OBJS))

all: $(NAME)

$(NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $(OBJ) -o $(BIN_DIR)$(NAME)

debug:
	$(CC) $(CFLAGS) $(OBJ) -g -o a.out

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_DIR)*.o a.out

fclean: clean
	rm -rf $(BIN_DIR)$(NAME) $(BIN_DIR) $(OBJ_DIR)

re: clean all

run: all debug
	./$(BIN_DIR)$(NAME)

mleak: all
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BIN_DIR)$(NAME)

.PHONY: all clean re run test
