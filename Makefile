# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rafaoliv <rafaoliv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 13:41:07 by rafaoliv          #+#    #+#              #
#    Updated: 2025/10/22 13:41:52 by rafaoliv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

OBJ = $(SRC:.c=.o)
SRC = 

NAME = push_swap

INCLUDES = $(LIBFT_INCLUDES)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES = -I$(LIBFT_DIR)
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo "$@ ✔️"

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT_FLAGS) -o $(NAME)
	@echo "$@ compilado ✔️"
	
$(LIBFT):
	@echo "Compilando libft..."
	@make -C $(LIBFT_DIR)
	@echo "libft compilada ✔️"

norminette:
	norminette $(SRC) -R CheckForbiddenSourceHeader

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR) --silent
	@echo "Arquivos .o limpos 🧴"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) --silent
	@echo "Tudo limpo 🧽🧼"

re: fclean all

.PHONY: all clean fclean re norminette