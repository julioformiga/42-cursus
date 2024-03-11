CC = cc
INLCUDES = -Iinclude
CFLAGS = -Wall -Wextra -Werror -std=c99 $(INCLUDES)
RM = rm -f
AR = ar -src

NAME = pipex.a

SRC 	= $(wildcard src/*.c) pipex.c
OBJS 	= $(SRC:.c=.o)

all:	$(NAME)
		$(CC) $(CFLAGS) $(NAME) -o pipex

$(NAME):	$(OBJS)
			$(AR) $@ $(OBJS)

clean:
		$(RM) $(OBJS)

re:		clean all

run:	all
#		echo "content01.txt" > "file01.txt"
#		echo "content02.txt" > "file02.txt"
		./pipex
#		bat file0*
#		< file01.txt seq 0 11 | cat > file03.txt
#		bat file0*
