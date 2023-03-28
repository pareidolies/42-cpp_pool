#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

class PmergeMe
{
	public:

		PmergeMe(void);
		PmergeMe();
		PmergeMe(PmergeMe const & copy);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const & rhs);

		void sortList();
		void sortVector();

		void printSortedList();
		void printUnsortedList(std::list<int> & list);
		void printSortedVector();
		void printUnsortedVector(std::vector<int> & vector);

	private:

		std::vector<int>	_vector;
		std::list<int>		_list;
};

#endif