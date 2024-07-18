CC = cc
INCLUDE = -Iinclude
# sudo sysctrl vm.mmap_rnd_bits=30 (in archome = 32)
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

re: fclean all

debug:	all
		@$(CC) $(CFLAGS) $(NAME) -o a.out

run: re
	./philo 16 480 200 200 10
