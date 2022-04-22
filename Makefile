# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 17:02:05 by qduong            #+#    #+#              #
#    Updated: 2022/04/22 18:45:14 by qduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		map_check.c \
		utils.c \
		argv_check.c \
		freestuff.c
#map_parse_so_long_test.c
RM = rm -rf
CC = gcc
OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

NAME = so_long

all: $(NAME)

run:
	./so_long maps/簡単.ber
	
up:
	./so_long maps/上.ber

$(NAME): $(OBJS)
	$(MAKE) -C mlx
	$(MAKE) -C lib
	$(CC) -g -Wall -Werror $(OBJS) libftprintf.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	${RM} ${OBJS}
	@make clean -C lib/
	@make clean -C lib/libft
#$(RM) */*.o */*/*.o

fclean: clean
	${RM} $(NAME) libftprintf.a
	@make fclean -C lib/
	@make fclean -C lib/libft
	$(RM) *.dSYM 

re: fclean all

.PHONY:	all clean fclean re 

no:
	norminette $(SRCS)