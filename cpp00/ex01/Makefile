#Style
GREEN	=	\033[92;5;118m
YELLOW	=	\033[93;5;226m
GRAY	=	\033[33;2;37m
RESET	=	\e[0m
CURSIVE	=	\033[33;3m
RED		= 	\033[31m

#Program name
NAME	= phonebook

#Compiler
CC		= c++
CFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic
RM		= rm -f

#Includes
INC			= -I ./includes/

#Source files
SRC_PATH	= src/
SRC 	= main.cpp \
			PhoneBook.cpp \
			Contact.cpp

#Object files
OBJ_PATH	= obj/
OBJ		= $(SRC:.cpp=.o)
OBJS 	= $(addprefix $(OBJ_PATH), $(OBJ))

all: obj $(NAME)

obj:
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp | $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS)  $(INC) -o $(NAME) $(OBJS)
	@printf "$(GREEN)Phonebook: OK!$(RESET)\n"

clean:
	@$(RM) -Rf $(OBJ_PATH)
	@printf "$(YELLOW)Object files: $(RED)Deleted!$(RESET)\n"

fclean: clean
	@$(RM) -f $(NAME)
	@printf "$(YELLOW)Phonebook: $(RED)Deleted!$(RESET)\n"

re: fclean all

.PHONY: all re clean fclean