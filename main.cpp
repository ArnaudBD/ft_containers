#include "vector.hpp"
#include <string>
#include <iostream>

int main()
{
	Vector<std::string> v(8, "hello");

	std::cout << v << std::endl;

	return 0;
}