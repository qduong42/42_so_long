# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 17:02:05 by qduong            #+#    #+#              #
#    Updated: 2022/04/18 19:16:25 by qduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c	
#map_parse_so_long_test.c

OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

NAME = so_long

all: $(OBJS)
	$(MAKE) -C mlx
	$(MAKE) -C printf
	gcc -Wall -Werror $(OBJS) libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) 

$(NAME): $(OBJS)
	gcc -Wall -Werror $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

events: $(OBJS)
	gcc -Wall -Werror events.o -Lmlx -lmlx -framework OpenGL -framework AppKit -o events && ./events


clean:
	${RM} ${OBJS}
	$(RM) */*.o */*/*.o

fclean: clean
	${RM} $(NAME) 

re: fclean all

.PHONY:	all clean fclean re 

no:
	norminette $(SRCS)