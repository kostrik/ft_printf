# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akostrik <akostrik@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 14:32:35 by akostrik          #+#    #+#              #
#    Updated: 2022/11/30 23:20:35 by akostrik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

all:
	clear
	(cd ./workspace && make)
	${CC} main.c -L./workspace/ -lftprintf -L./workspace/libft -lft -lbsd
	./a.out

fclean: clean
	rm -f a.out
	(cd workspace && make fclean)

clean:
	(cd workspace && make clean)

re: fclean all