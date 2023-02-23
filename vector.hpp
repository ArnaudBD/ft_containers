#ifndef VECTOR_HPP
#define VECTOR_HPP
#include <memory>
#include <string>
#include <iostream>
#include <iterator>
#include <limits>
#include <algorithm>
#include "type_traits.hpp"

namespace ft {

  template <class T, class Allocator = std::allocator<T> >
  class iterator {
  public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;

    iterator() : _ptr(NULL) {}
    iterator(pointer ptr) : _ptr(ptr) {}
    iterator(const iterator& other) : _ptr(other._ptr) {}
    ~iterator() {}

    iterator& operator=(const iterator& other) {
      _ptr = other._ptr;
      return *this;
    }

    iterator& operator++() {
      ++_ptr;
      return *this;
    }

    iterator operator++(int) {
      iterator tmp(*this);
      ++_ptr;
      return tmp;
    }

    iterator& operator--() {
      --_ptr;
      return *this;
    }

    iterator operator--(int) {
      iterator tmp(*this);
      --_ptr;
      return tmp;
    }

    iterator operator+(difference_type n) const {
      return iterator(_ptr + n);
    }

    iterator operator-(difference_type n) const {
      return iterator(_ptr - n);
    }

    iterator& operator+=(difference_type n) {
      _ptr += n;
      return *this;
    }

    iterator& operator-=(difference_type n) {
      _ptr -= n;
      return *this;
    }

    reference operator*() const {
      return *_ptr;
    }

    pointer operator->() const {
      return _ptr;
    }

    reference operator[](difference_type n) const {
      return _ptr[n];
    }

    friend bool operator==(const iterator& lhs, const iterator& rhs) {
      return lhs._ptr == rhs._ptr;
    }

    friend bool operator!=(const iterator& lhs, const iterator& rhs) {
      return lhs._ptr != rhs._ptr;
    }

    friend bool operator<(const iterator& lhs, const iterator& rhs) {
      return lhs._ptr < rhs._ptr;
    }

    friend bool operator<=(const iterator& lhs, const iterator& rhs) {
      return lhs._ptr <= rhs._ptr;
    }

    friend bool operator>(const iterator& lhs, const iterator& rhs) {
      return lhs._ptr > rhs._ptr;
    }

    friend bool operator>=(const iterator& lhs, const iterator& rhs) {
      return lhs._ptr >= rhs._ptr;
    }

    friend difference_type operator-(const iterator& lhs, const iterator& rhs) {
      return lhs._ptr - rhs._ptr;
    }

  private:
    pointer _ptr;

  };

  template <class T, class Allocator = std::allocator<T> >
  class const_iterator {
  public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef std::ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;

    const_iterator() : _ptr(NULL) {}
    const_iterator(pointer ptr) : _ptr(ptr) {}
    const_iterator(const const_iterator& other) : _ptr(other._ptr) {}
    const_iterator(const iterator<T, Allocator>& other) : _ptr(other._ptr) {}
    ~const_iterator() {}

    const_iterator& operator=(const const_iterator& other) {
      _ptr = other._ptr;
      return *this;
    }

    const_iterator& operator++() {
      ++_ptr;
      return *this;
    }

    const_iterator operator++(int) {
      const_iterator tmp(*this);
      ++_ptr;
      return tmp;
    }

    const_iterator& operator--() {
      --_ptr;
      return *this;
    }

    const_iterator operator--(int) {
      const_iterator tmp(*this);
      --_ptr;
      return tmp;
    }

    const_iterator operator+(difference_type n) const {
      return const_iterator(_ptr + n);
    }

    const_iterator operator-(difference_type n) const {
      return const_iterator(_ptr - n);
    }

    const_iterator& operator+=(difference_type n) {
      _ptr += n;
      return *this;
    }

    const_iterator& operator-=(difference_type n) {
      _ptr -= n;
      return *this;
    }

    reference operator*() const {
      return *_ptr;
    }

    pointer operator->() const {
      return _ptr;
    }

    reference operator[](difference_type n) const {
      return _ptr[n];
    }

    friend bool operator==(const const_iterator& lhs, const const_iterator& rhs) {
      return lhs._ptr == rhs._ptr;
    }

    friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs) {
      return lhs._ptr != rhs._ptr;
    }

    friend bool operator<(const const_iterator& lhs, const const_iterator& rhs) {
      return lhs._ptr < rhs._ptr;
    }

    friend bool operator<=(const const_iterator& lhs, const const_iterator& rhs) {
      return lhs._ptr <= rhs._ptr;
    }

    friend bool operator>(const const_iterator& lhs, const const_iterator& rhs) {
      return lhs._ptr > rhs._ptr;
    }

    friend bool operator>=(const const_iterator& lhs, const const_iterator& rhs) {
      return lhs._ptr >= rhs._ptr;
    }

    friend difference_type operator-(const const_iterator& lhs, const const_iterator& rhs) {
      return lhs._ptr - rhs._ptr;
    }

  private:
    pointer _ptr;
  };


  template < class T, class Allocator = std::allocator<T> >
  class vector
  {
  public:
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

    template <class InputIterator>
iterator insert_dispatch(iterator position, 
		      InputIterator first, 
		      InputIterator last,
          false_type) {
    if (first == last) return position;
    size_type n = std::distance(first, last);
    unsigned surplus = _last_allocated - _last;
    if (surplus >= n) {
      size_type after_pos = end() - position;
	if (after_pos >= n) {
	    std::uninitialized_copy(end() - n, end(), end());
	    std::copy_backward(position, end() - n, end());
	    std::copy(first, last, position);
	} else {
	    std::uninitialized_copy(position, end(), position + n);
	    std::uninitialized_copy(first, last, position);
	    // std::uninitialized_copy(first + (end() - position), last, end());
	}
	_last += n;
    } else {
	size_type len = size() + std::max(size(), n);
	iterator tmp = _alloc.allocate(len);
	std::uninitialized_copy(begin(), position, tmp);
	std::uninitialized_copy(first, last, tmp + (position - begin()));
	std::uninitialized_copy(position, end(), tmp + (position - begin() + n));
  for (size_type i = 0; i < size(); ++i) {
    _alloc.destroy(_first + i);
  }
	_alloc.deallocate(begin(), capacity());
	// _alloc.destroy(begin());
	_last_allocated = tmp + len;
	_last = tmp + size() + n;
	_first = tmp;
    }
    return position;
}

iterator insert_dispatch(iterator position, size_type n, const T& x, true_type) {
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
	size_type len = size() +  std::max(n, size());
	iterator tmp = _alloc.allocate(len);
	std::uninitialized_copy(begin(), position, tmp);
	std::uninitialized_fill_n(tmp + (position - begin()), n, x);
	std::uninitialized_copy(position, end(), tmp + (position - begin() + n));
  for (size_type i = 0; i < size(); ++i) {
    _alloc.destroy(_first + i);
  }
	_alloc.deallocate(begin(), capacity());
	// _alloc.destroy(begin());
	_last_allocated = tmp + len;
	_last = tmp + size() + n;
	_first = tmp;
    }
    return position;
}

  public:

  // CONSTRUCTORS

    explicit vector( const allocator_type& alloc = allocator_type() ) : _alloc(alloc) {
      _first = NULL;
      _last = NULL;
      _last_allocated = NULL;
    }


    void vector_aux(size_type n, const T& value = T(), true_type = true_type(), const allocator_type& = allocator_type() ) {
      _first = _alloc.allocate(n);
      std::uninitialized_fill_n(_first, n, value);
      _last = _first + n;
      _last_allocated = _last;
    }
    explicit vector( size_type n, const T& value = T(), const allocator_type& alloc = allocator_type()) {
    vector_aux(n, value, true_type(), alloc);
    }

    template <class InputIterator>
    void vector_aux( InputIterator first, InputIterator last, false_type, const allocator_type& = allocator_type() ) {
      _first = _alloc.allocate(std::distance(first, last));
      std::uninitialized_copy(first, last, _first);
      _last = _first + (std::distance(first, last));
      _last_allocated = _last;
    }
    template <class InputIterator>
    vector( InputIterator first, InputIterator last, const allocator_type& = allocator_type() ) {
      vector_aux(first, last, is_integral<InputIterator>());
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
        if (_first + i != NULL)
          _alloc.destroy(_first + i);
      }
      _alloc.deallocate(_first, capacity());
      _first = NULL;
      _last = NULL;
      _last_allocated = NULL;
    }

  // ASSIGNMENT OPERATOR
    vector& operator=(const vector& x) {
      if (this != &x) {
        clear();
        reserve(x.size());
        std::uninitialized_copy(x.begin(), x.end(), _first);
        _last = _first + x.size();
      }
      return *this;
    }

  void assign (size_type n, const value_type& val) {
    aux_assign(n, val, true_type());
  }

  void aux_assign (size_type n, const value_type& val, true_type) {
    clear();
    reserve(n);
    std::uninitialized_fill_n(_first, n, val);
    _last = _first + n;
  }

  template <class InputIterator>
  void aux_assign (InputIterator first, InputIterator last, false_type) {
    clear();
    size_type n = std::distance(first, last);
    reserve(n);
    std::uninitialized_copy(first, last, _first);
    _last = _first + n;
  }

  template <class InputIterator>
  void assign (InputIterator first, InputIterator last) {
    aux_assign(first, last, typename is_integral<InputIterator>::type());
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
        for (size_type i = 0; i < old_size; ++i) {
          _alloc.destroy(_first + i);
        }
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
  for (size_type i = 0; i < size(); ++i) {
    _alloc.destroy(_first + i);
  }
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
    return insert_dispatch(position, n, x, true_type());
}

template <class InputIterator>
iterator insert(iterator position, InputIterator first, InputIterator last){
    return insert_dispatch(position, first, last, ft::is_integral<InputIterator>());
}

iterator erase(iterator position) {
    if (position + 1 != end())
  std::copy(position + 1, end(), position);
    _alloc.destroy(--_last);
    return position;
}

iterator erase(iterator first, iterator last) {
    iterator i = std::copy(last, end(), first);
    for (; i != end(); ++i)
      _alloc.destroy(i);
    _last = _last - (last - first);
    return first;
}

void push_back(const T& x) {
    if (_last != _last_allocated) {
  _alloc.construct(_last, x);
  ++_last;
    } else
  insert(end(), x);
}

void pop_back() {
    _alloc.destroy(--_last);
}

void resize(size_type new_size, T x = T()) {
    if (new_size < size()) erase(begin() + new_size, end());
    else insert(end(), new_size - size(), x);
}

void clear() {
    erase(begin(), end());
}

void swap(vector& other) {
  pointer tmp_first = _first;
  pointer tmp_last = _last;
  pointer tmp_last_allocated = _last_allocated;

  _first = other._first;
  _last = _first + other.size();
  _last_allocated = _first + other.capacity();
  other._first = tmp_first;
  other._last = tmp_last;
  other._last_allocated = tmp_last_allocated;
}



  // ALLOCATOR
  allocator_type get_allocator() const {
    return _alloc;
  }

};

template <class T, class Alloc>
bool operator==(const vector<T,Alloc>& x, const vector<T,Alloc>& y) {
    return x.size() == y.size() && std::equal(x.begin(), x.end(), y.begin());
}

template <class T, class Alloc>
bool operator<(const vector<T,Alloc>& x, const vector<T,Alloc>& y) {
    return std::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());}

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

template <class T, class Alloc>
void swap(vector<T,Alloc>& x, vector<T,Alloc>& y) {
    x.swap(y);
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
