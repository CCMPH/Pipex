NAME = pipex

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

FILES = pipex.c libftutils.c libftutils2.c utils.c

OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) -o $(NAME) $(OBJS)

%.o:%.c pipex.h
	$(CC) $(CFLAGS) -c $<

clean:
	$(RM) $(OBJS)

normi: $(FILES)
	norminette $(FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, normi