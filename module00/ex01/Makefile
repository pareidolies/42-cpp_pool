NAME		=	phonebook

SRCS		=	Phonebook.class.cpp Contact.class.cpp main.cpp

SRCS_DIR	= srcs

OBJS_DIR	= objs

INC_DIR		= includes

OBJS		= 	$(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

DEPS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.d))

CC		=	c++

CPPFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I $(INC_DIR) -MMD

RM		=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[92m[object files : OK].\033[0m"
	$(CC) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo "\033[92m[$(NAME) : OK].\033[0m"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)
	@echo "\033[93m[cleaning : OK].\033[0m"

re:	fclean all

-include $(DEPS)

.PHONY:	all clean fclean re
