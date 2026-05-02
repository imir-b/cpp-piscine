# --- shell ---
SHELL		=			/bin/bash

# --- exe --
NAME		=			megaphone

# --- flags ---

CXXFLAGS	=			-Wall -Werror -Wextra -std=c++98

# --- files ---
SRC			=			megaphone.cpp
OBJ			=			megaphone.o

# --- rules ---

all			:			$(NAME)

$(OBJ)		:			$(SRC)
						c++ $(CXXFLAGS) -c $(SRC) -o $(OBJ)

$(NAME)		:			$(OBJ)
						c++ $(OBJ) $(CXXFLAGS) -o $(NAME)

clean		:
						rm -rf $(OBJ)

fclean		:			clean
						rm -rf $(NAME)

re			:
						make fclean
						make all

.PHONY		:			all clean fclean re