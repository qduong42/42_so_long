# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qduong <qduong@students.42wolfsburg.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/21 13:15:50 by qduong            #+#    #+#              #
#    Updated: 2022/04/25 14:30:20 by qduong           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a

CC=gcc

CFLAGS=-Wall -Werror -Wextra

SRCS=	ft_printf.c\
		convert_write_hexa.c\
		convert_write_deca.c\
		conversion.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_put_error_string.c

OBJS=${SRCS:.c=.o}
RM = rm -rf

all: $(NAME)

$(NAME) : ${OBJS}
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) ${OBJS}
	cp $(NAME) ..

clean:
	${RM} ${OBJS} $(BONUS_OBJS)
	${RM} */*.o
	$(RM) a.out

fclean: clean
	${RM} $(NAME)
	${RM} libft/libft.a

re: fclean all

.PHONY:	all clean fclean re

no: ${SRCS}
	norminette ${SRCS} libft/*.c
