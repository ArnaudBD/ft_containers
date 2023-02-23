#include "vector.hpp"
#include <string>
#include <iostream>
#include <vector>

int main()
{
	NAMESPACE::vector<int> v;
	std::cout << "====================> v <====================" << std::endl;
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "max size: " << v.max_size() << std::endl;
	std::cout << "empty: " << v.empty() << std::endl;
	std::cout << "********** v.push_back(1) *****" << std::endl;
	v.push_back(1);
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "empty: " << v.empty() << std::endl;
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v.data() + i) << std::endl;
		std::cout << "v[" << i << "] = " << v[i] << std::endl;
	}
	std::cout << "********** v.push_back(2) *****" << std::endl;
	v.push_back(2);
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "empty: " << v.empty() << std::endl;
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v.data() + i) << std::endl;
		std::cout << "v[" << i << "] = " << v[i] << std::endl;
	}
	std::cout << "********** v.assign(3, 3) *****" << std::endl;
	v.assign(3, 3);
	std::cout << "size: " << v.size() << std::endl;
	std::cout << "capacity: " << v.capacity() << std::endl;
	std::cout << "empty: " << v.empty() << std::endl;
	for (size_t i = 0; i < v.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v.data() + i) << std::endl;
		std::cout << "v[" << i << "] = " << v[i] << std::endl;
	}


	NAMESPACE::vector<std::string> v0(2, "hello");
	std::cout << "====================> v0(2, \"hello\") <====================" << std::endl;
	std::cout << "size: " << v0.size() << std::endl;
	std::cout << "capacity: " << v0.capacity() << std::endl;
	std::cout << "max size: " << v0.max_size() << std::endl;
	for (size_t i = 0; i < v0.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
		std::cout << "v0[" << i << "] = " << v0[i] << std::endl;
	}
	std::cout << "********** v0.insert(v0.begin() + 1, \"world\") *****" << std::endl;
	v0.insert(v0.begin() + 1, "world");
	std::cout << "size: " << v0.size() << std::endl;
	for (size_t i = 0; i < v0.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
		std::cout << "v0[" << i << "] = " << v0[i] << std::endl;
	}
	std::cout << "==========> v0.insert(v0.begin(), 1, \"HA\") <==========" << std::endl;
		v0.insert(v0.begin(), 1, "HA");
std::cout << v0.size() << std::endl;
	for (size_t i = 0; i < v0.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
		std::cout << "v0[" << i << "] = " << v0[i] << std::endl;
	}

std::cout << "==========> tv0.insert(v0.begin() + 1, 5, \"HA\") <==========" << std::endl;
	v0.insert(v0.begin(), 5, "HA");
std::cout << v0.size() << std::endl;
	for (size_t i = 0; i < v0.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
		std::cout << v0[i] << std::endl;
	}

	std::cout << "==========> v0.erase(v0.end() - 1) <==========" << std::endl;
	v0.erase(v0.end() - 1);
		for (size_t i = 0; i < v0.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
		std::cout << v0[i] << std::endl;
	}

	std::cout << "==========> v0.assign(5, \"HA\") <==========" << std::endl;
	v0.assign(5, "HA");
		for (size_t i = 0; i < v0.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
		std::cout << v0[i] << std::endl;
	}

	NAMESPACE::vector<std::string> v1(15, "hello");
	std::cout << "====================> v1(15, \"hello\") <====================" << std::endl;
	std::cout << "size: " << v1.size() << std::endl;
	std::cout << "capacity: " << v1.capacity() << std::endl;
	std::cout << "max size: " << v1.max_size() << std::endl;
	for (size_t i = 0; i < v1.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
	}
	std::cout << "********** v1.insert(v1.begin() + 1, \"world\") *****" << std::endl;
	v1.insert(v1.begin() + 1, "world");
	std::cout << "size: " << v1.size() << std::endl;
	for (size_t i = 0; i < v1.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
		std::cout << v1[i] << std::endl;
	}
	std::cout << "********** v1.insert(v1.begin(), 1, \"HA\") *****" << std::endl;
	v1.insert(v1.begin(), 1, "HA");
	std::cout << "size: " << v1.size() << std::endl;
	for (size_t i = 0; i < v1.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
	}
	std::cout << "********** v1.insert(v1.begin(), 5, \"HA\") *****" << std::endl;
	v1.insert(v1.begin(), 5, "HA");
	std::cout << "size: " << v1.size() << std::endl;
	for (size_t i = 0; i < v1.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
	}
	std::cout << "********** v1.erase(v1.end() - 1) *****" << std::endl;
	v1.erase(v1.end() - 1);
	std::cout << "size: " << v1.size() << std::endl;
	for (size_t i = 0; i < v1.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
	}
	std::cout << "********** v1.assign(5, \"HA\") *****" << std::endl;
	v1.assign(5, "HA");
	std::cout << "size: " << v1.size() << std::endl;
	for (size_t i = 0; i < v1.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
	}

	NAMESPACE::vector<int> v2(2, 42);
	std::cout << "====================> v2(2, 42) <====================" << std::endl;
	std::cout << "size: " << v2.size() << std::endl;
	std::cout << "capacity: " << v2.capacity() << std::endl;
	std::cout << "max size: " << v2.max_size() << std::endl;
	for (size_t i = 0; i < v2.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
	}
	std::cout << "********** v2.insert(v2.begin() + 1, 21) *****" << std::endl;
	v2.insert(v2.begin() + 1, 21);
	std::cout << "size: " << v2.size() << std::endl;
	for (size_t i = 0; i < v2.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
	}
	std::cout << "==========> v2.insert(v2.begin(), 1, 33) <==========" << std::endl;
	std::cout << "size: " << v2.size() << std::endl;
	std::cout << "capacity: " << v2.capacity() << std::endl;
	v2.insert(v2.begin(), 1, 33);
	for (size_t i = 0; i < v2.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
	}
	std::cout << "==========> v2.insert(v2.begin(), 5, 42) <==========" << std::endl;
	v2.insert(v2.begin(), 5, 42);
	std::cout << "size: " << v2.size() << std::endl;
	for (size_t i = 0; i < v2.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
	}
	std::cout << "********** v2.erase(v2.end() - 1) *****" << std::endl;
	v2.erase(v2.end() - 1);
	std::cout << "size: " << v2.size() << std::endl;
	for (size_t i = 0; i < v2.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
	}
	std::cout << "********** v2.assign(5, 42) *****" << std::endl;
	v2.assign(5, 42);
	std::cout << "size: " << v2.size() << std::endl;
	for (size_t i = 0; i < v2.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
	}

	NAMESPACE::vector<float> v3(2, 42.42);
	std::cout << "====================> v3(2, 42.42) <====================" << std::endl;
	std::cout << "size: " << v3.size() << std::endl;
	std::cout << "capacity: " << v3.capacity() << std::endl;
	std::cout << "max size: " << v3.max_size() << std::endl;
	for (size_t i = 0; i < v3.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
	}
	std::cout << "********** v3.insert(v3.begin() + 1, 21.21) *****" << std::endl;
	v3.insert(v3.begin() + 1, 21.21);
	std::cout << "size: " << v3.size() << std::endl;
	for (size_t i = 0; i < v3.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
	}
	std::cout << "==========> v3.insert(v3.begin(), 1, 42.42) <==========" << std::endl;
	std::cout << "size: " << v3.size() << std::endl;
	std::cout << "capacity: " << v3.capacity() << std::endl;
	v3.insert(v3.begin(), 1, 42.42);
	for (size_t i = 0; i < v3.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
	}
	std::cout << "==========> v3.insert(v3.begin(), 5, 42.42) <==========" << std::endl;
	v3.insert(v3.begin(), 5, 42.42);
	std::cout << "size: " << v3.size() << std::endl;
	for (size_t i = 0; i < v3.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
	}
	std::cout << "********** v3.erase(v3.end() - 1) *****" << std::endl;
	v3.erase(v3.end() - 1);
	std::cout << "size: " << v3.size() << std::endl;
	for (size_t i = 0; i < v3.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
	}
	std::cout << "********** v3.assign(5, 42.42) *****" << std::endl;
	v3.assign(5, 42.42);
	std::cout << "size: " << v3.size() << std::endl;
	for (size_t i = 0; i < v3.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
	}

	NAMESPACE::vector<char> v4(2, 'a');
	std::cout << "====================> v4(2, 'a') <====================" << std::endl;
	std::cout << "size: " << v4.size() << std::endl;
	std::cout << "capacity: " << v4.capacity() << std::endl;
	std::cout << "max size: " << v4.max_size() << std::endl;
	for (size_t i = 0; i < v4.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
	}
	std::cout << "********** v4.insert(v4.begin() + 1, 'b') *****" << std::endl;
	v4.insert(v4.begin() + 1, 'b');
	std::cout << "size: " << v4.size() << std::endl;
	for (size_t i = 0; i < v4.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
	}
	std::cout << "==========> v4.insert(v4.begin(), 1, 'a') <==========" << std::endl;
	v4.insert(v4.begin(), 1, 'a');
	std::cout << "size: " << v4.size() << std::endl;
	for (size_t i = 0; i < v4.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
	}
	std::cout << "==========> v4.insert(v4.begin(), 5, 'a') <==========" << std::endl;
	v4.insert(v4.begin(), 5, 'a');
	std::cout << "size: " << v4.size() << std::endl;
	for (size_t i = 0; i < v4.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
	}
	std::cout << "********** v4.erase(v4.end() - 1) *****" << std::endl;
	v4.erase(v4.end() - 1);
	std::cout << "size: " << v4.size() << std::endl;
	for (size_t i = 0; i < v4.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
	}
	std::cout << "********** v4.assign(5, 'a') *****" << std::endl;
	v4.assign(5, 'a');
	std::cout << "size: " << v4.size() << std::endl;
	for (size_t i = 0; i < v4.size(); ++i) {
		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
	}
	
	// v.reserve(100);
	return 0;
}