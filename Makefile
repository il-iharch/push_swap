NAME = push_swap


CC = cc

CFLAGS = -Wall -Wextra -Werror 

RM = rm -f

SRC = 	parsing.c\
		ft_split.c\
		is_repeat.c\
		linked_list.c\
		push.c\
		reverse_rotate.c\
		rotate.c\
		swap.c\
		short_sort.c\
		stack_operations_1.c\
		sort_stack.c\
		push_swap.c
		

OBJS = $(SRC:.c=.o)


INCLUDE = push_swap.h

all: $(NAME)
 
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME) 

re: fclean all 
