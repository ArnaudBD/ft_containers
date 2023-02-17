// #include "vector.hpp"
// #include <string>
// #include <iostream>
// #include <vector>

// int main()
// {
// 	NAMESPACE::vector<int> v;
// 	std::cout << "====================> v <====================" << std::endl;
// 	std::cout << "size: " << v.size() << std::endl;
// 	std::cout << "capacity: " << v.capacity() << std::endl;
// 	std::cout << "max size: " << v.max_size() << std::endl;
// 	std::cout << "empty: " << v.empty() << std::endl;
// 	std::cout << "********** v.push_back(1) *****" << std::endl;
// 	v.push_back(1);
// 	std::cout << "size: " << v.size() << std::endl;
// 	std::cout << "capacity: " << v.capacity() << std::endl;
// 	std::cout << "empty: " << v.empty() << std::endl;
// 	for (size_t i = 0; i < v.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v.data() + i) << std::endl;
// 		std::cout << "v[" << i << "] = " << v[i] << std::endl;
// 	}
// 	std::cout << "********** v.push_back(2) *****" << std::endl;
// 	v.push_back(2);
// 	std::cout << "size: " << v.size() << std::endl;
// 	std::cout << "capacity: " << v.capacity() << std::endl;
// 	std::cout << "empty: " << v.empty() << std::endl;
// 	for (size_t i = 0; i < v.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v.data() + i) << std::endl;
// 		std::cout << "v[" << i << "] = " << v[i] << std::endl;
// 	}
// 	std::cout << "********** v.assign(3, 3) *****" << std::endl;
// 	v.assign(3, 3);
// 	std::cout << "size: " << v.size() << std::endl;
// 	std::cout << "capacity: " << v.capacity() << std::endl;
// 	std::cout << "empty: " << v.empty() << std::endl;
// 	for (size_t i = 0; i < v.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v.data() + i) << std::endl;
// 		std::cout << "v[" << i << "] = " << v[i] << std::endl;
// 	}


// 	NAMESPACE::vector<std::string> v0(2, "hello");
// 	std::cout << "====================> v0(2, \"hello\") <====================" << std::endl;
// 	std::cout << "size: " << v0.size() << std::endl;
// 	std::cout << "capacity: " << v0.capacity() << std::endl;
// 	std::cout << "max size: " << v0.max_size() << std::endl;
// 	for (size_t i = 0; i < v0.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
// 		std::cout << "v0[" << i << "] = " << v0[i] << std::endl;
// 	}
// 	std::cout << "********** v0.insert(v0.begin() + 1, \"world\") *****" << std::endl;
// 	v0.insert(v0.begin() + 1, "world");
// 	std::cout << "size: " << v0.size() << std::endl;
// 	for (size_t i = 0; i < v0.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
// 		std::cout << "v0[" << i << "] = " << v0[i] << std::endl;
// 	}
// 	std::cout << "==========> v0.insert(v0.begin(), 1, \"HA\") <==========" << std::endl;
// 		v0.insert(v0.begin(), 1, "HA");
// std::cout << v0.size() << std::endl;
// 	for (size_t i = 0; i < v0.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
// 		std::cout << "v0[" << i << "] = " << v0[i] << std::endl;
// 	}

// std::cout << "==========> tv0.insert(v0.begin() + 1, 5, \"HA\") <==========" << std::endl;
// 	v0.insert(v0.begin(), 5, "HA");
// std::cout << v0.size() << std::endl;
// 	for (size_t i = 0; i < v0.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
// 		std::cout << v0[i] << std::endl;
// 	}

// 	std::cout << "==========> v0.erase(v0.end() - 1) <==========" << std::endl;
// 	v0.erase(v0.end() - 1);
// 		for (size_t i = 0; i < v0.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
// 		std::cout << v0[i] << std::endl;
// 	}

// 	std::cout << "==========> v0.assign(5, \"HA\") <==========" << std::endl;
// 	v0.assign(5, "HA");
// 		for (size_t i = 0; i < v0.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v0.data() + i) << std::endl;
// 		std::cout << v0[i] << std::endl;
// 	}

// 	NAMESPACE::vector<std::string> v1(15, "hello");
// 	std::cout << "====================> v1(15, \"hello\") <====================" << std::endl;
// 	std::cout << "size: " << v1.size() << std::endl;
// 	std::cout << "capacity: " << v1.capacity() << std::endl;
// 	std::cout << "max size: " << v1.max_size() << std::endl;
// 	for (size_t i = 0; i < v1.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
// 		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
// 	}
// 	std::cout << "********** v1.insert(v1.begin() + 1, \"world\") *****" << std::endl;
// 	v1.insert(v1.begin() + 1, "world");
// 	std::cout << "size: " << v1.size() << std::endl;
// 	for (size_t i = 0; i < v1.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
// 		std::cout << v1[i] << std::endl;
// 	}
// 	std::cout << "********** v1.insert(v1.begin(), 1, \"HA\") *****" << std::endl;
// 	v1.insert(v1.begin(), 1, "HA");
// 	std::cout << "size: " << v1.size() << std::endl;
// 	for (size_t i = 0; i < v1.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
// 		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
// 	}
// 	std::cout << "********** v1.insert(v1.begin(), 5, \"HA\") *****" << std::endl;
// 	v1.insert(v1.begin(), 5, "HA");
// 	std::cout << "size: " << v1.size() << std::endl;
// 	for (size_t i = 0; i < v1.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
// 		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
// 	}
// 	std::cout << "********** v1.erase(v1.end() - 1) *****" << std::endl;
// 	v1.erase(v1.end() - 1);
// 	std::cout << "size: " << v1.size() << std::endl;
// 	for (size_t i = 0; i < v1.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
// 		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
// 	}
// 	std::cout << "********** v1.assign(5, \"HA\") *****" << std::endl;
// 	v1.assign(5, "HA");
// 	std::cout << "size: " << v1.size() << std::endl;
// 	for (size_t i = 0; i < v1.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v1.data() + i) << std::endl;
// 		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
// 	}

// 	NAMESPACE::vector<int> v2(2, 42);
// 	std::cout << "====================> v2(2, 42) <====================" << std::endl;
// 	std::cout << "size: " << v2.size() << std::endl;
// 	std::cout << "capacity: " << v2.capacity() << std::endl;
// 	std::cout << "max size: " << v2.max_size() << std::endl;
// 	for (size_t i = 0; i < v2.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
// 		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
// 	}
// 	std::cout << "********** v2.insert(v2.begin() + 1, 21) *****" << std::endl;
// 	v2.insert(v2.begin() + 1, 21);
// 	std::cout << "size: " << v2.size() << std::endl;
// 	for (size_t i = 0; i < v2.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
// 		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
// 	}
// 	std::cout << "==========> v2.insert(v2.begin(), 1, 33) <==========" << std::endl;
// 	std::cout << "size: " << v2.size() << std::endl;
// 	std::cout << "capacity: " << v2.capacity() << std::endl;
// 	v2.insert(v2.begin(), 1, 33);
// 	for (size_t i = 0; i < v2.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
// 		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
// 	}
// 	std::cout << "==========> v2.insert(v2.begin(), 5, 42) <==========" << std::endl;
// 	v2.insert(v2.begin(), 5, 42);
// 	std::cout << "size: " << v2.size() << std::endl;
// 	for (size_t i = 0; i < v2.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
// 		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
// 	}
// 	std::cout << "********** v2.erase(v2.end() - 1) *****" << std::endl;
// 	v2.erase(v2.end() - 1);
// 	std::cout << "size: " << v2.size() << std::endl;
// 	for (size_t i = 0; i < v2.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
// 		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
// 	}
// 	std::cout << "********** v2.assign(5, 42) *****" << std::endl;
// 	v2.assign(5, 42);
// 	std::cout << "size: " << v2.size() << std::endl;
// 	for (size_t i = 0; i < v2.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v2.data() + i) << std::endl;
// 		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
// 	}

// 	NAMESPACE::vector<float> v3(2, 42.42);
// 	std::cout << "====================> v3(2, 42.42) <====================" << std::endl;
// 	std::cout << "size: " << v3.size() << std::endl;
// 	std::cout << "capacity: " << v3.capacity() << std::endl;
// 	std::cout << "max size: " << v3.max_size() << std::endl;
// 	for (size_t i = 0; i < v3.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
// 		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
// 	}
// 	std::cout << "********** v3.insert(v3.begin() + 1, 21.21) *****" << std::endl;
// 	v3.insert(v3.begin() + 1, 21.21);
// 	std::cout << "size: " << v3.size() << std::endl;
// 	for (size_t i = 0; i < v3.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
// 		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
// 	}
// 	std::cout << "==========> v3.insert(v3.begin(), 1, 42.42) <==========" << std::endl;
// 	std::cout << "size: " << v3.size() << std::endl;
// 	std::cout << "capacity: " << v3.capacity() << std::endl;
// 	v3.insert(v3.begin(), 1, 42.42);
// 	for (size_t i = 0; i < v3.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
// 		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
// 	}
// 	std::cout << "==========> v3.insert(v3.begin(), 5, 42.42) <==========" << std::endl;
// 	v3.insert(v3.begin(), 5, 42.42);
// 	std::cout << "size: " << v3.size() << std::endl;
// 	for (size_t i = 0; i < v3.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
// 		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
// 	}
// 	std::cout << "********** v3.erase(v3.end() - 1) *****" << std::endl;
// 	v3.erase(v3.end() - 1);
// 	std::cout << "size: " << v3.size() << std::endl;
// 	for (size_t i = 0; i < v3.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
// 		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
// 	}
// 	std::cout << "********** v3.assign(5, 42.42) *****" << std::endl;
// 	v3.assign(5, 42.42);
// 	std::cout << "size: " << v3.size() << std::endl;
// 	for (size_t i = 0; i < v3.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v3.data() + i) << std::endl;
// 		std::cout << "v3[" << i << "] = " << v3[i] << std::endl;
// 	}

// 	NAMESPACE::vector<char> v4(2, 'a');
// 	std::cout << "====================> v4(2, 'a') <====================" << std::endl;
// 	std::cout << "size: " << v4.size() << std::endl;
// 	std::cout << "capacity: " << v4.capacity() << std::endl;
// 	std::cout << "max size: " << v4.max_size() << std::endl;
// 	for (size_t i = 0; i < v4.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
// 		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
// 	}
// 	std::cout << "********** v4.insert(v4.begin() + 1, 'b') *****" << std::endl;
// 	v4.insert(v4.begin() + 1, 'b');
// 	std::cout << "size: " << v4.size() << std::endl;
// 	for (size_t i = 0; i < v4.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
// 		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
// 	}
// 	std::cout << "==========> v4.insert(v4.begin(), 1, 'a') <==========" << std::endl;
// 	v4.insert(v4.begin(), 1, 'a');
// 	std::cout << "size: " << v4.size() << std::endl;
// 	for (size_t i = 0; i < v4.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
// 		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
// 	}
// 	std::cout << "==========> v4.insert(v4.begin(), 5, 'a') <==========" << std::endl;
// 	v4.insert(v4.begin(), 5, 'a');
// 	std::cout << "size: " << v4.size() << std::endl;
// 	for (size_t i = 0; i < v4.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
// 		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
// 	}
// 	std::cout << "********** v4.erase(v4.end() - 1) *****" << std::endl;
// 	v4.erase(v4.end() - 1);
// 	std::cout << "size: " << v4.size() << std::endl;
// 	for (size_t i = 0; i < v4.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
// 		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
// 	}
// 	std::cout << "********** v4.assign(5, 'a') *****" << std::endl;
// 	v4.assign(5, 'a');
// 	std::cout << "size: " << v4.size() << std::endl;
// 	for (size_t i = 0; i < v4.size(); ++i) {
// 		std::cout << "data + " << i << " = " << *(v4.data() + i) << std::endl;
// 		std::cout << "v4[" << i << "] = " << v4[i] << std::endl;
// 	}
	
// 	// v.reserve(100);
// 	return 0;
// }
#ifndef BASE_HPP
# define BASE_HPP

# if !defined(USING_STD)
#  define TESTED_NAMESPACE ft
# else
#  define TESTED_NAMESPACE std
# endif /* !defined(STD) */

# include <iostream>
# include <string>

// --- Class foo
template <typename T>
class foo {
	public:
		typedef T	value_type;

		foo(void) : value(), _verbose(false) { };
		foo(value_type src, const bool verbose = false) : value(src), _verbose(verbose) { };
		foo(foo const &src, const bool verbose = false) : value(src.value), _verbose(verbose) { };
		~foo(void) { if (this->_verbose) std::cout << "~foo::foo()" << std::endl; };
		void m(void) { std::cout << "foo::m called [" << this->value << "]" << std::endl; };
		void m(void) const { std::cout << "foo::m const called [" << this->value << "]" << std::endl; };
		foo &operator=(value_type src) { this->value = src; return *this; };
		foo &operator=(foo const &src) {
			if (this->_verbose || src._verbose)
				std::cout << "foo::operator=(foo) CALLED" << std::endl;
			this->value = src.value;
			return *this;
		};
		value_type	getValue(void) const { return this->value; };
		void		switchVerbose(void) { this->_verbose = !(this->_verbose); };

		operator value_type(void) const {
			return value_type(this->value);
		}
	private:
		value_type	value;
		bool		_verbose;
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, foo<T> const &bar) {
	o << bar.getValue();
	return o;
}
// --- End of class foo

template <typename T>
T	inc(T it, int n)
{
	while (n-- > 0)
		++it;
	return (it);
}

template <typename T>
T	dec(T it, int n)
{
	while (n-- > 0)
		--it;
	return (it);
}

#endif /* BASE_HPP */

#if !defined(USING_STD)
# include "vector.hpp"
#else
# include <vector>
#endif /* !defined(STD) */

#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

#include "vector.hpp"
#include <list>

int		main(void)
{
	std::list<int> lst;
	std::list<int>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	NAMESPACE::vector<int> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	printSize(vct);
	return (0);
}
