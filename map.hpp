#ifndef MAP_HPP
#define MAP_HPP

#include "pair.hpp"
#include <functional>
#include <memory>

namespace ft {
template< class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key, T> > >
class map {
	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef Alloc allocator_type;
		typedef typename Alloc::reference reference;
		typedef typename Alloc::const_reference const_reference;
		typedef typename Alloc::pointer pointer;
		typedef typename Alloc::const_pointer const_pointer;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t difference_type;
		typedef size_t size_type;
		typedef iterator<T> iterator;
		typedef const_iterator<T> const_iterator;
		class value_compare 
			: public std::binary_function<value_type, value_type, bool> {
		friend class map;
		protected:
			Compare comp;
			std::value_compare(Compare c) : comp(c) {}
		public:
			bool operator()(const value_type& x, const value_type& y) const {
				return comp(x.first, y.first);
			}
		};
	private:
		iterator _begin;
		iterator _end;
		size_type _size;
		allocator_type _alloc;
		key_compare _comp;
	public:
		//Construct - Copy - Destroy
		explicit map(const Compare& comp = Compare(),
					const Alloc& = Alloc()));
		template< class InputIterator >
		map(InputIterator first, InputIterator last,
			const Compare& comp = Compare(),
			const Alloc& = Alloc());
		map(const map<Key, T, Compare, Alloc>& x);
		~map();
		map<Key, T, Compare, Alloc>&
		operator=(const map<Key, T, Compare, Alloc>& x);
		
		//Iterators
		iterator begin() { return _begin; }
		const_iterator begin() const { return _begin; }
		iterator end() { return _end; }
		const_iterator end() const { return _end; }
		reverse_iterator rbegin() { return reverse_iterator(_end); }
		const_reverse_iterator rbegin() const { return const_reverse_iterator(_end); }
		reverse_iterator rend() { return reverse_iterator(_begin); }
		const_reverse_iterator rend() const { return const_reverse_iterator(_begin); }

		//Capacity
		bool empty() const { return _size == 0; }
		size_type size() const;
		size_type max_size() const;

		//Element access
		T& operator[](const key_type& x);

		//Modifiers
		pair<iterator, bool> insert(const value_type& x);
		iterator insert(iterator position, const value_type& x);
		template< class InputIterator >
			void insert(InputIterator first, InputIterator last);
		void erase(iterator position);
		size_type erase(const key_type& x);
		void erase(iterator first, iterator last);
		void swap(map<Key, T, Compare, Alloc>& x);
		void clear();

		//Observers
		key_compare key_comp() const;
		value_compare value_comp() const;

		//Operations
		iterator find(const key_type& x);
		const_iterator find(const key_type& x) const;
		size_type count(const key_type& x) const;
		
		iterator lower_bound(const key_type& x);
		const_iterator lower_bound(const key_type& x) const;
		iterator upper_bound(const key_type& x);
		const_iterator upper_bound(const key_type& x) const;
		
		pair<iterator, iterator>
			equal_range(const key_type& x);
		pair<const_iterator, const_iterator>
			equal_range(const key_type& x) const;
	};
		template <class Key, class T, class Compare, class Alloc>
		bool operator==(const map<Key, T, Compare, Alloc>& x,
						const map<Key, T, Compare, Alloc>& y);
		template <class Key, class T, class Compare, class Alloc>
		bool operator<(const map<Key, T, Compare, Alloc>& x,
						const map<Key, T, Compare, Alloc>& y);
		template <class Key, class T, class Compare, class Alloc>
		bool operator!=(const map<Key, T, Compare, Alloc>& x,
						const map<Key, T, Compare, Alloc>& y);
		template <class Key, class T, class Compare, class Alloc>
		bool operator>(const map<Key, T, Compare, Alloc>& x,
						const map<Key, T, Compare, Alloc>& y);
		template <class Key, class T, class Compare, class Alloc>
		bool operator<=(const map<Key, T, Compare, Alloc>& x,
						const map<Key, T, Compare, Alloc>& y);
		template <class Key, class T, class Compare, class Alloc>
		bool operator>=(const map<Key, T, Compare, Alloc>& x,
						const map<Key, T, Compare, Alloc>& y);

		//Specialized algorithms
		template <class Key, class T, class Compare, class Alloc>
		void swap(map<Key, T, Compare, Alloc>& x,
				map<Key, T, Compare, Alloc>& y);

}

#endif