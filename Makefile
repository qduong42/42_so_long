# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 17:02:05 by qduong            #+#    #+#              #
#    Updated: 2022/04/20 23:05:32 by qduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		map_check.c \
		utils.c \
		argv_check.c \
		freestuff.c
#map_parse_so_long_test.c

CC = gcc
OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C mlx
	$(MAKE) -C lib
	$(CC) -g -Wall -Werror $(OBJS) libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	${RM} ${OBJS}
	$(RM) */*.o */*/*.o

fclean: clean
	${RM} $(NAME) 

re: fclean all

.PHONY:	all clean fclean re 

no:
	norminette $(SRCS)