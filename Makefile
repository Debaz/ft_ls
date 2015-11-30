# Insert 42 header

NAME =		ft_ls

SRCS = 		./sources/main.c \
		./sources/ ...

OBJ =		./main.o \
		./ ...

CFLAGS = 	-Wall -Wextra -Werror

LFLAGS = 	-L./sources/libft/ -lft

IFLAGS = 	-I./includes -I./sources/libft/includes

all: 		$(NAME)

$(NAME):
		@echo "Compilation des librairies ..."
		@make -C ./sources/libft
		@echo "Compilation des sources ..."
		@gcc -c $(SRCS) $(IFLAGS) $(LFLAGS) $(CFLAGS)
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