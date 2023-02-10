#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

# include "Form.hpp"
# include <iostream>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

# define K1 "     ccee88oo "
# define K2 "  C8O8O8Q8PoOb o8oo "
# define K3 " dOB69QO8PdUOpugoO9bD "
# define K4 "CgggbU8OU qOp qOdoUOdcb "
# define K5 "    6OuU  |p u gcoUodpP "
# define K6 "      |||||  |douUP "
# define K7 "        ||||||| "
# define K8 "         ||||| "
# define K9 "         ||||| "
# define K10 "         ||||| "
# define K11 "   .....|||||||.... "

# define L1 "              ,@@@@@@@,"
# define L2 "       ,,,.   ,@@@@@@/@@,  .oo8888o."
# define L3 "    ,&%&&%&&%,@@@@@/@@@@@@,8888\\88/8o"
# define L4 "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'"
# define L5 "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"
# define L6 "   %&&%/ %&&%&&@@\\ V /@@' `88\\8 `/88'"
# define L7 "   `&%\\ ` /%&'    |.|        \\ '|8'"
# define L8 "       |o|        | |         | |"
# define L9 "       |.|        | |         | |"
# define L10 "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_"

# define M1 "    oxoxoo    ooxoo"
# define M2 "  ooxoxo oo  oxoxooo"
# define M3 " oooo xxoxoo ooo ooox"
# define M4 " oxo o oxoxo  xoxxoxo"
# define M5 "  oxo xooxoooo o ooo"
# define M6 "    ooo\\oo\\  /o/o"
# define M7 "        \\  \\/ /"
# define M8 "         |   /"
# define M9 "         |  |"
# define M10 "         | D|"
# define M11 "         |  |"
# define M12 "         |  |"
# define M13 "  ______/____\\____"

class	Bureaucrat;

class ShrubberyCreationForm : public Form
{
	public:

		ShrubberyCreationForm(void); //default constructor
		ShrubberyCreationForm(std::string target); //target constructor
		ShrubberyCreationForm(ShrubberyCreationForm const & copy); //copy constructor
		~ShrubberyCreationForm(void); //destructor

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const & rhs); //assignement operator

		bool					execute(Bureaucrat const & executor) const;

	private:

		std::string			_target;

};

std::ostream &	operator<<(std::ostream & o, ShrubberyCreationForm const & rhs);

#endif