#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <memory>
#include <stddef.h>
#include <string>

namespace ft {

	// Primitives
	template<class iterator> struct iterator_traits;
	template<class T> struct iterator_traits<T*>;

	template<class Category, class T, class Distance = ptrdiff_t,
	class Pointer = T*, class Reference = T&> struct iterator;

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	// Iterator Operations
	template<class InputIterator, class Distance>
		void advance(InputIterator& i, Distance n);
	template <class InputIterator>
		typename iterator_traits<InputIterator>::difference_type
		distance(InputIterator first, InputIterator last);

	// Predifined Iterators
	template <class Iterator> class reverse_iterator;

	template <class Iterator>
		bool operator==(const reverse_iterator<Iterator>& x,
						const reverse_iterator<Iterator>& y);
	template <class Iterator>
		bool operator<(const reverse_iterator<Iterator>& x,
						const reverse_iterator<Iterator>& y);
	template <class Iterator>
		bool operator!=(const reverse_iterator<Iterator>& x,
						const reverse_iterator<Iterator>& y);
	template <class Iterator>
		bool operator>(const reverse_iterator<Iterator>& x,
						const reverse_iterator<Iterator>& y);
	template <class Iterator>
		bool operator<=(const reverse_iterator<Iterator>& x,
						const reverse_iterator<Iterator>& y);
	template <class Iterator>
		bool operator>=(const reverse_iterator<Iterator>& x,
						const reverse_iterator<Iterator>& y);
	
	template <class Iterator>
		typename reverse_iterator<Iterator>::difference_type operator-(
			const reverse_iterator<Iterator>& x,
			const reverse_iterator<Iterator>& y);
	template <class Iterator>
		reverse_iterator<Iterator> operator+(
			typename reverse_iterator<Iterator>::difference_type n,
			const reverse_iterator<Iterator>& x);
	
	template <class Container> class back_insert_iterator;
	template <class Container>
		back_insert_iterator<Container> back_inserter(Container& x);
	
	template <class Container> class front_insert_iterator;
	template <class Container>
		front_insert_iterator<Container> front_inserter(Container& x);
	
	template <class Container> class insert_iterator;
	template <class Container, class Iterator>
		insert_iterator<Container> inserter(Container& x, Iterator i);
	
	// Stream Iterators
	template <class T, class charT = char, class traits = std::char_traits<charT>,
		class Distance = ptrdiff_t>
	class istream_iterator;
	template <class T, class charT, class traits, class Distance>
		bool operator==(const istream_iterator<T, charT, traits, Distance>& x,
						const istream_iterator<T, charT, traits, Distance>& y);
	template <class T, class charT, class traits, class Distance>
		bool operator!=(const istream_iterator<T, charT, traits, Distance>& x,
						const istream_iterator<T, charT, traits, Distance>& y);
	
	template <class T, class charT = char, class traits = std::char_traits<charT> >
		class ostream_iterator;
	
	template<class charT, class traits = std::char_traits<charT> >
		class istreambuf_iterator;
	template<class charT, class traits>
		bool operator==(const istreambuf_iterator<charT, traits>& a,
						const istreambuf_iterator<charT, traits>& b);
	template <class charT, class traits>
		bool operator!=(const istreambuf_iterator<charT, traits>& a,
						const istreambuf_iterator<charT, traits>& b);
	
	template <class charT, class traits = std::char_traits<charT> >
		class ostreambuf_iterator;
}

#endif