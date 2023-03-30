#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>

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
		PmergeMe(const std::string &arg);
		PmergeMe(PmergeMe const & copy);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const & rhs);

		void	checkArg();

		void	fillDeque();
		void	fillVector();

		void	checkDuplicates();

		void	sortDeque();
		void	sortVector();

		void	createPairsDeque();
		void	createPairsVector();

		void	sortPairsDeque();
		void	sortPairsVector();

		void	mergeDeque();
		void	mergeVector();

		void	binarySearchDeque();
		void	binarySearchVector();

		void	insertAtPositionDeque();
		void	insertAtPositionVector();

		void	printDeque(std::deque<int> & deque);
		void	printVector(std::vector<int> & vector);

	private:

		std::vector<int>	_vector;
		std::deque<int>		_deque;
		std::string			_arg;
};

#endif