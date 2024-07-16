CC = cc
INCLUDE = -Iinclude
# CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -pthread
CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -pthread -fsanitize=thread -g
# CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -pthread -g
RM		= rm -f
AR		= ar -src

NAME = philo.a

SRC	= $(wildcard src/*.c)
OBJ	= $(SRC:.c=.o)

all:	$(NAME)

%.o:	%.c
		@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@$(CC) $(CFLAGS) $(NAME) -o philo

clean:
	@$(RM) $(OBJ) philo

fclean:	clean
		@$(RM) $(NAME) a.out philo

re: fclean all run

debug:	all
		@$(CC) $(CFLAGS) $(NAME) -o a.out

run: re
	./philo 100 410 200 200 10
