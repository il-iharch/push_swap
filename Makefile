NAME = push_swap.a
CC = cc
FLAGS = -Wall -Wextra -Werror

SRC = 	ft_cheak.c\
		ft_split.c\
		is_repeat.c\
		


OBJS1 = $(SRC:.c=.o)


INCLUDE = push_swap.h

%.o : %.c $(INCLUDE) 
	$(CC) $(FLAGS) -c $< -o $@
	ar rc $(NAME) $@   

$(NAME) : $(OBJS1) 
	

all : $(NAME)
	
clean :
	rm -rf $(OBJS1)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean