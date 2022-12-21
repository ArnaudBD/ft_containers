#include "vector.hpp"
#include <string>
#include <iostream>
#include <vector>

int main()
{
	NAMESPACE::vector<std::string> v(8, "hello");
	for (int i = 0; i < 8; ++i) {
		std::cout << v[i] << std::endl;
	}
	std::cout << v.size() << std::endl;

	NAMESPACE::vector<int> v2(8, 42);
	for (int i = 0; i < 8; ++i) {
		std::cout << v2[i] << std::endl;
	}
	std::cout << v.size() << std::endl;

	NAMESPACE::vector<float> v3(8, 42.42);
	for (int i = 0; i < 8; ++i) {
		std::cout << v3[i] << std::endl;
	}
	std::cout << v.size() << std::endl;

    std::cout << v.max_size() << std::endl;
    std::vector<int> truc_v;

	return 0;
}
