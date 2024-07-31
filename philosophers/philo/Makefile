# For ArchLinux need to set mmap_rnd_bits to 30 (in archome = 32)
# sudo sysctl vm.mmap_rnd_bits=30
CC = cc
INCLUDE = -Iinclude
CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -pthread -g
# CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -O3 -pthread -g
# CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -pthread -fsanitize=thread -g
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
	@$(RM) $(OBJ)

fclean:	clean
		@$(RM) $(NAME) a.out philo vgcore.*

re: fclean all

debug:	all
		@$(CC) $(CFLAGS) $(NAME) -o a.out

run: re
#	./philo 50 410 200 200 7
#	./philo 5 800 200 200 7
	./philo 1 410 200 200 10
	valgrind ./philo 1 410 200 200 10
#	valgrind --leak-check=full ./philo 1 410 200 200 10
#	./philo 3 390 200 200 2
#	./philo 4 400 200 200 2
#	./philo 1 310 200 200 2
#	./philo 16 480 200 200 10 | xsel -ib
