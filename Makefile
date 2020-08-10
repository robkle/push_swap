# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rklein <rklein@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/11 11:37:41 by rklein            #+#    #+#              #
#    Updated: 2020/06/11 11:39:30 by rklein           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CH = checker

PS = push_swap

FLAGS = -Wall -Wextra -Werror

CH_MAIN = ch_main.c

PS_MAIN = ps_main.c

CH_OBJ = ch_main.o

PS_OBJ = ps_main.o

SRC = checker.c longsort.c misc.c operations.c presort.c print.c push_swap.c \
		stack_a.c stack_b.c validator.c verylong.c

OBJ = checker.o longsort.o misc.o operations.o presort.o print.o push_swap.o \
		stack_a.o stack_b.o validator.o verylong.o

INC = ./

LIB = libft/libft.a

all :
	make -C libft/
	gcc $(FLAGS) -c $(CH_MAIN) $(PS_MAIN) $(SRC)
	gcc -o $(CH) $(FLAGS) $(CH_OBJ) $(OBJ) $(LIB) -I $(INC)
	gcc -o $(PS) $(FLAGS) $(PS_OBJ) $(OBJ) $(LIB) -I $(INC)

clean :
	rm -rf $(CH_OBJ) $(PS_OBJ) $(OBJ)
	make clean -C libft/

fclean : clean
	rm -rf $(CH) $(PS)
	make fclean -C libft/

re: fclean all
