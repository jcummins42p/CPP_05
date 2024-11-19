# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcummins <jcummins@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 18:08:59 by jcummins          #+#    #+#              #
#    Updated: 2024/11/19 21:53:14 by jcummins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = interns

CXX = c++
CXXFLAGS = -g -Werror -Wextra -Wall -pedantic -std=c++98

SRCS = main.cpp \
	AForm.cpp \
	Bureaucrat.cpp \
	PresidentialPardonForm.cpp \
	RobotomyRequestForm.cpp \
	ShrubberyCreationForm.cpp \
	Intern.cpp
OBJS = $(SRCS:%.cpp=%.o)
HEADS = AForm.hpp \
	Bureaucrat.hpp \
	PresidentialPardonForm.hpp \
	RobotomyRequestForm.hpp \
	ShrubberyCreationForm.hpp \
	Intern.hpp
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $^ -o $@
	@echo "✅ Linking object files into executable $@"

%.o: %.cpp $(HEADS)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "✅ Complied object file $@ from source file $<"

clean:
	@echo "💥 Removing all object files"
	@rm -f $(OBJS)

fclean: clean
	@echo "💥 Removing all object files and executable"
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
