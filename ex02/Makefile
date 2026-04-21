# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuliano <yuliano@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/18 19:44:06 by yuliano           #+#    #+#              #
#    Updated: 2026/04/18 19:44:39 by yuliano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++ -g
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

NAME = a.out
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all