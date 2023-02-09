NAME = philo

SRC = philosophers.c
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
RM = rm -f
all : $(NAME)
$(NAME) : $(OBJS)
		cc $(CFLAGS) -o $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all