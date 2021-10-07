# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 23:44:35 by adesmet           #+#    #+#              #
#    Updated: 2021/10/07 23:29:05 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = 	ft_printf.c\
			ft_parse.c\
			ft_format.c\
			ft_print_cp.c\
			ft_print_di.c\
			ft_print_pxX.c\
			ft_print_s.c\
			ft_print_u.c\
			ft_utils.c\
				
OBJS = ${SRC:.c=.o}
SRC	= $(addprefix printf/,$(FILES))
NAME = libftprintf.a
LIBFT =	libft/libft.a
HEADERS = libft/libft.h printf/ft_printf.h

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS} 
	cp $(LIBFT) $@
	ar -rcs ${NAME} ${OBJS}
	
${OBJS} :
	gcc -Wall -Werror -Wextra -c ${@:.o=.c} -o $@

$(LIBFT):
	$(MAKE) -C libft

%.o : %.c $(HEADERS) 
	$(CC) $(CFLAGS) -I./includes -o $@ -c $<
			
clean:
	$(MAKE) clean -C libft
	rm -f ${OBJS}

fclean: clean
	rm -f $(LIBFT)
	rm -f ${NAME}

re: fclean all
		
.PHONY : all clean fclean re bonus