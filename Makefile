NAME = philo
DIR = src
SRC = $(DIR)/philosophers.c $(DIR)/error.c $(DIR)/utils.c
# CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
RM = rm -f
all : $(NAME)
$(NAME) : $(OBJS)
		cc -o $(NAME) $(OBJS)

clean :
		$(RM) $(OBJS)

fclean : clean
		$(RM) $(NAME)

re : fclean all