SRCS = 	main.c

OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

NAME = so_long

all: $(OBJS)
	$(MAKE) -C mlx
	$(MAKE) -C printf
	gcc -Wall -Werror $(OBJS) printf/libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

$(NAME): $(OBJS)
	gcc -Wall -Werror $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

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