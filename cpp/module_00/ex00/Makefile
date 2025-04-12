CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

all: $(NAME)

$(NAME): $(NAME).cpp
	$(CC) $(CFLAGS) $(NAME).cpp -o $(NAME)

clean:
	@rm -f $(NAME)

fclean:
	@rm -f $(NAME)

re: fclean all

run: all
	@./$(NAME)

test: all
	@echo -e "Test #0"
	./$(NAME) "shhhhh... I think the students are asleep..."
	@echo -e "\nTest #1"
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	@echo -e "\nTest #2"
	./$(NAME)

.PHONY: all clean re run test
