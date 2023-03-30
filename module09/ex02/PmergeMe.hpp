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
		PmergeMe(std::vector<int> unsortedVector);
		PmergeMe(std::deque<int> unsortedDeque);
		PmergeMe(PmergeMe const & copy);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const & rhs);

		//vector
		void	fordJohnsonSort(std::vector<int> unsortedVector);
		void	createPairs(std::vector < std::pair<int,int> > & vectorPair);
		void	sortPairsRecursively(std::vector < std::pair<int,int> > & vectorPair, size_t size);
		void	addFirstHalf(std::vector < std::pair<int,int> > & vectorPair, std::vector<int> & sortedVector);
		void	addElementPairedWithFirst(std::vector < std::pair<int,int> > & vectorPair, std::vector<int> & sortedVector);
		int		binarySearch(int value, std::vector<int> sortedVector);
		void	insertAtPosition();
		void	printBefore(std::vector<int> & vector);
		void	printAfter(std::vector<int> & vector);

		//deque

	private:

		std::vector<int>	_unsortedVector;
		std::deque<int>		_unsortedDeque;
};

#endif