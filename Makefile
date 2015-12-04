#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: klescaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/03 10:51:54 by klescaud          #+#    #+#              #
#    Updated: 2015/12/03 11:02:19 by klescaud         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME =		ft_ls

SRCS = 		./sources/main.c

OBJ =		./main.o

CFLAGS = 	-Wall -Wextra -Werror

LFLAGS = 	-L./sources/libft/ -lft

IFLAGS = 	-I./includes -I./sources/libft/includes

all: 		$(NAME)

$(NAME):
		@echo "Compilation des librairies ..."
		@make -C ./sources/libft
		@echo "Compilation des sources ..."
		@gcc -c $(SRCS) $(IFLAGS) $(CFLAGS)
		@echo "Compilation du projet ..."
		@gcc -o $(NAME) $(OBJ) $(LFLAGS)

clean:
		@make -C ./sources/libft fclean
		@rm -rf $(OBJ)
		@echo "Objets detruits."

fclean: 	clean
		@rm $(NAME)
		@echo "Projet detruit."

re: 		fclean all

.PHONY: 	all fclean re