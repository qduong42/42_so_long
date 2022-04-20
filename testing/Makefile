SRCS = 	hook.c

OBJS = ${SRCS:.c=.o}

NAME = test

all: $(OBJS)
	$(MAKE) -C mlx
	gcc -Wall -Werror $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./$(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Werror $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) && ./$(NAME)

events: $(OBJS)
	gcc -Wall -Werror events.o -Lmlx -lmlx -framework OpenGL -framework AppKit -o events && ./events


clean:
	${RM} ${OBJS}

fclean: clean
	${RM} $(NAME) 

re: fclean all

.PHONY:	all clean fclean re 

no:
	norminette $(SRCS)