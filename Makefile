NAME	=	hack

SRCS	=	huffman_coding.c

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

OBJS	=	$(SRCS:.c=.o)

%.o : %.c
	$(CC) $(FLAGS) -c -o $@ $<
	
$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(SRCS)

all : $(NAME)

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)
	rm -rf *.bin

re: fclean all

.PHONY : clean fclean re all