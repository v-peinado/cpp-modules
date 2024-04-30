# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 15:14:58 by vpeinado          #+#    #+#              #
#    Updated: 2024/04/30 16:35:13 by vpeinado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Style
GREEN	=	\033[92;5;118m
YELLOW	=	\033[93;5;226m
GRAY	=	\033[33;2;37m
RESET	=	\e[0m
CURSIVE	=	\033[33;3m
RED		= 	\033[31m

#Program name
NAME	= megaphone

#Compiler
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
RM		= rm -f

#Source files
SRC_DIR	= src/
SRC 	= $(shell find $(SRC_DIR) -type f -iname "*.cpp" | sed 's|^src/||')

#Object files
OBJ_DIR	= obj/
OBJ		= $(SRC:.cpp=.o)
OBJS 	= $(addprefix $(OBJ_DIR), $(OBJ))

all: obj $(NAME)

obj:
	@rsync -av --include '*/' --exclude '*' --quiet $(SRC_DIR) $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@printf "$(GREEN)Megaphone: OK!$(RESET)\n"

clean:
	@$(RM) -Rf $(OBJ_DIR)
	@printf "$(YELLOW)Object files: $(RED)Deleted!$(RESET)\n"

fclean: clean
	@$(RM) -f $(NAME)
	@printf "$(YELLOW)Megaphone: $(RED)Deleted!$(RESET)\n"

re: fclean all

.PHONY: all re clean fclean
