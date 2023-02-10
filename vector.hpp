#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <string>
#include <iostream>
#include <iterator>
#include <limits>
#include <algorithm>

namespace ft {
  template < class T, class Allocator = std::allocator<T> >
  class vector
  {
    typedef typename  Allocator::reference                  reference;
    typedef typename  Allocator::const_reference            const_reference;
    typedef           T                                     value_type;
    typedef           size_t                                size_type;
    typedef           Allocator                             allocator_type;
    typedef           T*                                    iterator;
    typedef           const T*                              const_iterator;
    typedef typename  Allocator::pointer                    pointer;
    typedef typename  Allocator::const_pointer              const_pointer;
    typedef           std::reverse_iterator<iterator>       reverse_iterator;
    typedef           std::reverse_iterator<const_iterator> const_reverse_iterator;

  private:
    value_type*                 _first;
    value_type*                 _last;
    value_type*                 _last_allocated;
    std::allocator<value_type>  _alloc;

  public:

  // CONSTRUCTORS
    vector() {
      _first = NULL;
      _last = NULL;
      _last_allocated = NULL;
    }
    explicit vector( const allocator_type& alloc = allocator_type() ) : _alloc(alloc) {
      _first = NULL;
      _last = NULL;
      _last_allocated = NULL;
    }

    explicit vector(size_type n, 
                    const T& value = T(), 
                    const allocator_type& = allocator_type()) {
      _first = _alloc.allocate(n);
      std::uninitialized_fill_n(_first, n, value);
      _last = _first + n;
      _last_allocated = _last;
    }

    template <class InputIterator>
    vector( value_type* first, value_type* last, const allocator_type& = allocator_type() ) {
      _first = _alloc.allocate(last - first);
      std::uninitialized_copy(first, last, _first);
      _last = _first + (last - first);
      _last_allocated = _last;
    }

    vector( const vector& x ) {
      _first = _alloc.allocate(x.size());
      std::uninitialized_copy(x.begin(), x.end(), _first);
      _last = _first + x.size();
      _last_allocated = _last;
    }

  // DESTRUCTOR  
    ~vector() {
      for (size_type i = 0; i < size(); ++i) {
        _alloc.destroy(_first + i);
      }
      _alloc.deallocate(_first, capacity());
    }

  // CAPACITY
    size_type size() const { return std::distance(_first, _last ); }
    size_type max_size() const { return _alloc.max_size(); }
    size_type capacity() const { return std::distance(_first, _last_allocated); }
    bool empty() const { return _first == _last; }
    
    void reserve (size_type new_cap) {
      if (new_cap > max_size()) {
        throw std::length_error("vector::reserve");
      }
      if (new_cap > capacity()) {
        pointer new_first = _alloc.allocate(new_cap);
        std::uninitialized_copy(_first, _last, new_first);
        size_type old_size = size();
        _alloc.deallocate(_first, capacity());
        _last_allocated = new_first + new_cap;
        _last = new_first + old_size;
        _first = new_first;
      }
    }

  // ELEMENT ACCESS
    reference operator[](size_type n) { return _first[n]; }
    const_reference operator[](size_type n) const { return _first[n]; }
    reference at(size_type n) {
      if (n >= size()) {
        throw std::out_of_range("vector::at");
      }
      return _first[n];
    }
    const_reference at(size_type n) const {
      if (n >= size()) {
        throw std::out_of_range("vector::at");
      }
      return _first[n];
    }
    reference front() { return *_first; }
    const_reference front() const { return *_first; }
    reference back() { return *(_last - 1); }
    const_reference back() const { return *(_last - 1); }
    pointer data() { return _first; }
    const_pointer data() const { return _first; }

  // ITERATORS
  iterator begin() { return _first; }
  const_iterator begin() const { return _first; }
  iterator end() { return _last; }
  const_iterator end() const { return _last; }
  reverse_iterator rbegin() { return reverse_iterator(end()); }
  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }
  reverse_iterator rend() { return reverse_iterator(begin()); }
  const_reverse_iterator rend() const { 
    return const_reverse_iterator(begin()); 
  }


  // MODIFIERS
void insert_aux(iterator position, const T& x) {
    if (_last != _last_allocated) {
	_alloc.construct(_last, *(_last - 1));
	std::copy_backward(position, _last - 1, _last);
	*position = x;
	++_last;
    } else {
	size_type len = size() ? 2 * size() : 1;
	iterator tmp = _alloc.allocate(len);
	std::uninitialized_copy(begin(), position, tmp);
	_alloc.construct(tmp + (position - begin()), x);
	std::uninitialized_copy(position, end(), tmp + (position - begin()) + 1); 
	_alloc.deallocate(begin(), capacity());
	// _alloc.destroy(begin());
	_last_allocated = tmp + len;
	_last = tmp + size() + 1;
	_first = tmp;
    }
}

iterator insert(iterator position, const T& x) {
	size_type n = position - begin();
	if (_last != _last_allocated && position == end()) {
	    _alloc.construct(_last, x);
	    _last++;
	} else
	    insert_aux(position, x);
	return begin() + n;
    }


iterator insert(iterator position, size_type n, const T& x) {
    if (n == 0) return position;
    size_type surplus = _last_allocated - _last;
    if ( surplus >= n) {
      size_type len = end() - position;
	if (len > n) {
	    std::uninitialized_copy(end() - n, end(), end());
	    std::copy_backward(position, end() - n, end());
	    std::fill(position, position + n, x);
	} else {
	    std::uninitialized_copy(position, end(), position + n);
	    std::fill(position, end(), x);
	    std::uninitialized_fill_n(end(), n - (end() - position), x);
	}
	_last += n;
    } else {
	size_type len = size() +  n;
	iterator tmp = _alloc.allocate(len);
	std::uninitialized_copy(begin(), position, tmp);
	std::uninitialized_fill_n(tmp + (position - begin()), n, x);
	std::uninitialized_copy(position, end(), tmp + (position - begin() + n));
	_alloc.deallocate(begin(), capacity());
	// _alloc.destroy(begin());
	_last_allocated = tmp + len;
	_last = tmp + size() + n;
	_first = tmp;
    }
    return position;
}

iterator insert(iterator position, 
		       const_iterator first, 
		       const_iterator last) {
    if (first == last) return;
    size_type n = 0;
    std::distance(first, last, n);
    if (_last_allocated - _last >= n) {
	if (end() - position > n) {
	    std::uninitialized_copy(end() - n, end(), end());
	    std::copy_backward(position, end() - n, end());
	    std::copy(first, last, position);
	} else {
	    std::uninitialized_copy(position, end(), position + n);
	    std::copy(first, first + (end() - position), position);
	    std::uninitialized_copy(first + (end() - position), last, end());
	}
	_last += n;
    } else {
	size_type len = size() + max(size(), n);
	iterator tmp = _alloc.allocate(len);
	std::uninitialized_copy(begin(), position, tmp);
	std::uninitialized_copy(first, last, tmp + (position - begin()));
	std::uninitialized_copy(position, end(), tmp + (position - begin() + n));
	_alloc.deallocate(begin(), capacity());
	// _alloc.destroy(begin());
	_last_allocated = tmp + len;
	_last = tmp + size() + n;
	_first = tmp;
    }
    return position;
}

iterator erase(iterator position) {
    if (position + 1 != end())
  std::copy(position + 1, end(), position);
    _alloc.destroy(--_last);
    return position;
}

iterator erase(iterator first, iterator last) {
    iterator i = std::copy(last, end(), first);
    std::for_each(i, end(), _alloc.destroy);
    _last = _last - (last - first);
    return first;
}
};

template <class T, class Alloc>
bool operator==(const vector<T,Alloc>& x, const vector<T,Alloc>& y);

template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& x, const vector<T,Alloc>& y);

template <class T, class Alloc>
bool operator!=(const vector<T,Alloc>& x, const vector<T,Alloc>& y) {
    return !(x == y);
}

template <class T, class Alloc>
bool operator>(const vector<T,Alloc>& x, const vector<T,Alloc>& y) {
    return y < x;
}

template <class T, class Alloc>
bool operator<=(const vector<T,Alloc>& x, const vector<T,Alloc>& y) {
    return !(y < x);
}

template <class T, class Alloc>
bool operator>=(const vector<T,Alloc>& x, const vector<T,Alloc>& y) {
    return !(x < y);
}

};

#endif
/*
   namespace std {
   template <class T, class Allocator = allocator<T> >
   class vector {
   public:
// types:
typedef typename Allocator::reference reference;
typedef typename Allocator::const_reference const_reference;
typedef uint size_type; // See 23.1
typedef implementation defined iterator; // See 23.1
typedef implementation defined const_iterator; // See 23.1
typedef implementation defined difference_type;// See 23.1
typedef T value_type;
typedef Allocator allocator_type;
typedef typename Allocator::pointer pointer;
typedef typename Allocator::const_pointer const_pointer
typedef std::reverse_iterator<iterator> reverse_iterator;
typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
explicit vector(const Allocator& = Allocator());
explicit vector(size_type n, const T& value = T(),
const Allocator& = Allocator());
template <class InputIterator>
vector(InputIterator first, InputIterator last,
const Allocator& = Allocator());
vector(const vector<T,Allocator>& x);
~vector();
vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
template <class InputIterator>
void assign(InputIterator first, InputIterator last);
void assign(size_type n, const T& u);
allocator_type get_allocator() const;
// iterators:
iterator begin();
const_iterator begin() const;
iterator end();
const_iterator end() const;
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
reverse_iterator rend();
const_reverse_iterator rend() const;
// 23.2.4.2 capacity:
size_type size() const;
size_type max_size() const;
void resize(size_type sz, T c = T());
size_type capacity() const;
bool empty() const;
void reserve(size_type n);
// element access:
reference operator[](size_type n);
const_reference operator[](size_type n) const;
const_reference at(size_type n) const;
reference at(size_type n);
reference front();
const_reference front() const;
reference back();
const_reference back() const;
// 23.2.4.3 modifiers:
void push_back(const T& x);
void pop_back();
iterator insert(iterator position, const T& x);
void insert(iterator position, size_type n, const T& x);
template <class InputIterator>
void insert(iterator position,
InputIterator first, InputIterator last);
iterator erase(iterator position);
iterator erase(iterator first, iterator last);
void swap(vector<T,Allocator>&);
void clear();
};
template <class T, class Allocator>
bool operator==(const vector<T,Allocator>& x,
const vector<T,Allocator>& y);
template <class T, class Allocator>
bool operator< (const vector<T,Allocator>& x,
    const vector<T,Allocator>& y);
template <class T, class Allocator>
bool operator!=(const vector<T,Allocator>& x,
    const vector<T,Allocator>& y);
template <class T, class Allocator>
bool operator> (const vector<T,Allocator>& x,
    const vector<T,Allocator>& y);
template <class T, class Allocator>
bool operator>=(const vector<T,Allocator>& x,
    const vector<T,Allocator>& y);
template <class T, class Allocator>
bool operator<=(const vector<T,Allocator>& x,
    const vector<T,Allocator>& y);
// specialized algorithms:
template <class T, class Allocator>
void swap(vector<T,Allocator>& x, vector<T,Allocator>& y);
}
*/
