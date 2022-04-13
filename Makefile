SRCS = main.c

OBJS = ${SRCS:.c=.o}

NAME = so_long

all: $(OBJS)
	$(MAKE) -C mlx
	gcc -Wall -Werror $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./$(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Werror $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./$(NAME)

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} $(NAME) 

re: fclean all

.PHONY:	all clean fclean re 

no:
	norminette $(SRCS)