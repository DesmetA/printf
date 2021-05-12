# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adesmet <adesmet@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 23:44:35 by adesmet           #+#    #+#              #
#    Updated: 2021/05/08 12:38:01 by adesmet          ###   ########.fr        #
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
SRC	= $(addprefix sources/,$(FILES))
NAME = libftprintf.a
LIBFT =	libft/libft.a
HEADERS = includes/libft.h includes/ft_printf.h

all: ${NAME}

${NAME}: ${OBJS} ${LIBFT}
	cp $(LIBFT) $@	
	ar -rcs ${NAME} ${OBJS}
	
${OBJS} :
	gcc -Wall -Werror -Wextra -c ${@:.o=.c} -o $@

$(LIBFT):
			$(MAKE) -C libft

%.o:		%.c $(HEADERS) 
			$(CC) $(CFLAGS) -I./includes -o $@ -c $<
			
clean:
	$(MAKE) clean -C libft
	rm -f ${OBJS}

fclean: clean
	rm -f $(LIBFT)
	rm -f ${NAME}

re: fclean all
		
.PHONY : all clean fclean re