NAME	=	animal

SRCS	=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongDog.cpp WrongCat.cpp

OBJS	= 	$(SRCS:%.cpp=%.o)

DEPS	= 	$(SRCS:%.cpp=%.d)

CC	=	c++

CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98 -MMD

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[92m[object files : OK].\033[0m"
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[92m[executable : OK].\033[0m"

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)
	@echo "\033[93m[cleaning : OK].\033[0m"

re:	fclean all

.PHONY:	all clean fclean re