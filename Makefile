NAME	=	huffman_coding_program

SRCS	=	main.c huffman_encoding.c huffman_decoding.c

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
	rm -rf *.txt

re: fclean all

.PHONY : clean fclean re all