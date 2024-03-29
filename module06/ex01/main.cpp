# include "Serializer.hpp"

int main()
{
	Data *initial = new Data();
	uintptr_t ptr;
	Data *final;

	initial->value = "test";
	initial->c = 'a';
	initial->f = 22.5;
	initial->d = 14.7;

	ptr = Serializer::serialize(initial);
	final = Serializer::deserialize(ptr);

	std::cout << "value initial : " << initial->value << "	| 	value final : " << final->value << std::endl;
	std::cout << "c initial : " << initial->c << "		| 	c final : " << final->c << std::endl;
	std::cout << "f initial : " << initial->f << "	| 	f final : " << final->f << std::endl;
	std::cout << "d initial : " << initial->d << "	| 	d final : " << final->d << std::endl;

	delete initial;

	return (0);
}
