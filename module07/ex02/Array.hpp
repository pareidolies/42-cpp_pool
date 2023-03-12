#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stddef.h>
# include <iostream>
# include <exception>

# define ANSI_PURPLE		"\x1b[95m"
# define ANSI_BLUE			"\x1b[94m"
# define ANSI_YELLOW		"\x1b[93m"
# define ANSI_RED			"\x1b[91m"
# define ANSI_GREEN			"\x1b[92m"
# define ANSI_RESET			"\x1b[0m"

template<typename T>
class Array
{
	public:

		class	OutOfBounds : public std::exception
		{
			public:

				virtual char const * what(void) const throw()
				{
					return ("Exception: Array out of bounds");
				}
		};

		Array(void) :  _size(0), _array(new T[0]()) {} //default constructor
		Array(unsigned int n) :  _size(n), _array(new T[n]()) {} //unsigned int constructor
		Array(Array<T> const & copy) : _size(copy._size), _array(new T[copy._size]) //copy constructor
		{
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = copy._array[i];
		}
		~Array(void) //destructor
		{
			if (_array)
				delete [] _array;
		}

		Array	&operator=(Array<T> const & rhs) //assignement operator
		{
			if (this != &rhs) {
				_size = rhs._size;
				if (_array)
					delete [] _array;
				_array = new T[_size];
				for (unsigned int i = 0; i < _size; i++)
					_array[i] = rhs[i];
			}
			return (*this);
		}

		T &	operator[](unsigned int n)
		{
			if (n >= _size)
				throw (OutOfBounds());
			return (this->_array[n]);
		}
		T const &	operator[](unsigned int n) const 
		{
			if (n >= _size)
				throw (OutOfBounds());
			return (this->_array[n]);
		}

		unsigned int	size(void) const
		{
			return (this->_size);
		}

	private:

		unsigned int	_size;
		T *				_array;

};

#endif