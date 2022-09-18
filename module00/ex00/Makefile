NAME	=	megaphone

SRCS	=	megaphone.cpp

OBJS	= 	$(SRCS:%.cpp=%.o)

CC	=	c++

CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[92m[object files : OK].\033[0m"
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[92m[executable : OK].\033[0m"

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@echo "\033[93m[cleaning : OK].\033[0m"

re:	fclean all

.PHONY:	all clean fclean re
