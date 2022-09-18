NAME	=	megaphone

SRCS	=	megaphone.cpp

OBJS	= 	$(SRCS:%.cpp=%.o)

CC	=	c++

CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[92m[Object files : OK].\033[0m"
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[92m[Executable : OK].\033[0m"

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@echo "\x1b[31m[Cleaning : OK].\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
