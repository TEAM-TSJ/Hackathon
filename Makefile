NAME	=	hack

SRCS	=	huffman_coding.c

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

OBJS	=	$(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<
	
$(NAME):	$(OBJS) $(HEADER)
			$(CC) -o $(NAME) $(SRCS) -lpthread

all : $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY : clean fclean re all