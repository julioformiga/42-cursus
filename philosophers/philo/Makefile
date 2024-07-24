# For Arch linux need to set mmap_rnd_bits to 30 (in archome = 32)
# sudo sysctl vm.mmap_rnd_bits=30
CC = cc
INCLUDE = -Iinclude
# CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -pthread
CFLAGS = -Wall -Wextra -Werror $(INCLUDE) -pthread -fsanitize=thread -g
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
#	./philo 50 410 200 200 7
#	./philo 5 800 200 200 7
	./philo 1 410 200 200 10
#	./philo 16 480 200 200 10 | xsel -ib
