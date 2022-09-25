NAME = Bureaucrat

SRC =	main.cpp Bureaucrat.cpp Form.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp Intern.cpp

OBJS =  $(SRC:%.cpp=%.o)

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98 -g

all:	$(NAME)

%.o: %.cpp
	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@rm -rf $(OBJS)

fclean:		clean
	@rm -rf $(NAME)

re:			fclean all
