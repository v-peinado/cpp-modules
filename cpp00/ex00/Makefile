# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpeinado <vpeinado@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 15:14:58 by vpeinado          #+#    #+#              #
#    Updated: 2024/03/20 18:02:38 by vpeinado         ###   ########.fr        #
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
SRC_PATH	= src/
SRC 	= megaphone.cpp
SRCS	= $(addprefix $(SRC_PATH), $(SRC))

#Object files
OBJ_PATH	= obj/
OBJ		= $(SRC:.cpp=.o)
OBJS 	= $(addprefix $(OBJ_PATH), $(OBJ))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp | $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@printf "$(GREEN)Megaphone: OK!$(RESET)\n"

clean:
	@$(RM) -Rf $(OBJ_PATH)
	@printf "$(YELLOW)Object files: $(RED)Deleted!$(RESET)\n"

fclean: clean
	@$(RM) -f $(NAME)
	@printf "$(YELLOW)Megaphone: $(RED)Deleted!$(RESET)\n"

re: fclean all

.PHONY: all re clean fclean
