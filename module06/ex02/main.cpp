# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

int main()
{
	Base	base = Base();

	srand (time(NULL));
	Base *ptr;
	for (int i = 0; i < 30; i++)
	{
		ptr = generate();
		identify(ptr);
		identify(*ptr);
		delete ptr;
		std::cout << std::endl;
		usleep(10000);
	}
	return (0);
}
