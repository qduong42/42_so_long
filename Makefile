# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 17:02:05 by qduong            #+#    #+#              #
#    Updated: 2022/04/25 10:26:42 by qduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.c \
		map_check.c \
		utils.c \
		argv_check.c \
		freestuff.c\
		move_right_left.c\
		move_up_down.c
#map_parse_so_long_test.c
RM = rm -rf
CC = gcc
CFLAGS	= -Wall -Wextra -Werror
OBJS = ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Iminilibx-linux -c $< -o $@

NAME = so_long

all: $(NAME)

run:
	./so_long maps/簡単.ber
	
up:
	./so_long maps/上.ber

$(NAME): $(OBJS)
	$(MAKE) -C minilibx-linux
	$(MAKE) -C lib
	$(CC) -g $(CFLAGS) $(OBJS) libftprintf.a -L./minilibx-linux -L/usr/X11/lib -lmlx -lXext -lX11 -lm -o $(NAME)

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
	$(RM) mlx/libmlx.a

re: fclean all

.PHONY:	all clean fclean re 

no:
	norminette $(SRCS)