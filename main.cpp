#include "vector.hpp"
#include <string>
#include <iostream>
#include <vector>

int main()
{
	NAMESPACE::vector<std::string> v(2, "hello");
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << "v[" << i << "] = " << v[i] << std::endl;
		std::cout << v.size() << std::endl;
		std::cout << v.capacity() << std::endl;
		std::cout << v.max_size() << std::endl;
		std::cout << *v.begin() << std::endl;
		// std::cout << *v.end() - 1 << std::endl;
	}
	std::cout << v.size() << std::endl;

	NAMESPACE::vector<int> v2(2, 42);
	for (size_t i = 0; i < v2.size(); ++i) {
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
		std::cout << v2.size() << std::endl;
		std::cout << v2.capacity() << std::endl;
		std::cout << v2.max_size() << std::endl;
		std::cout << *v2.begin() << std::endl;
		// std::cout << *v2.end() -1 << std::endl;
	}
	std::cout << v2.size() << std::endl;

	NAMESPACE::vector<float> v3(2, 42.42);
	for (size_t i = 0; i < v3.size(); ++i) {
		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
		std::cout << v3.size() << std::endl;
		std::cout << v3.capacity() << std::endl;
		std::cout << v3.max_size() << std::endl;
		std::cout << *v3.begin() << std::endl;
		// std::cout << *v3.end() - 1 << std::endl;
	}
	std::cout << v3.size() << std::endl;

    std::cout << v.max_size() << std::endl;
    std::vector<int> truc_v;
v.reserve(10);
std::cout << v.capacity() << std::endl;
std::cout << v.size() << std::endl;
	v.insert(v.begin() + 1, "world");
	v.insert(v.begin(), 5, "HA");
std::cout << v.size() << std::endl;
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << v[i] << std::endl;
	}

	return 0;
}
