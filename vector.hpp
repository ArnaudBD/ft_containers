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
    typedef typename  Allocator::reference        reference;
    typedef typename  Allocator::const_reference  const_reference;
    typedef           T                           value_type;
    typedef           size_t                      size_type;
    typedef           Allocator                   allocator_type;
    typedef           T*                          iterator;
    typedef           const T*                    const_iterator;
    typedef typename  Allocator::pointer          pointer;

    private:
    value_type*                 _first;
    value_type*                 _last;
    value_type*                 _last_allocated;
    std::allocator<value_type>  _alloc;

    public:

  // CONSTRUCTORS
    explicit vector( const allocator_type& alloc = allocator_type() ) : _alloc(alloc) {
      _first = NULL;
      _last = NULL;
      _last_allocated = NULL;
    }

    explicit vector(size_type n, const T& value = T(), const allocator_type& = allocator_type()) {
      _first = _alloc.allocate(n);
std::cout << "constructor" << value << std::endl;
      for (size_type i = 0; i < n; ++i) {
        _alloc.construct(_first + i, value);
      }
      _last = _first + n;
      _last_allocated = _last;
    }

  // DESTRUCTOR  
    ~vector() {
      for (size_type i = 0; i < size(); ++i) {
        _alloc.destroy(_first + i);
      }
std::cout << "destructor" << *this->begin() << std::endl;
      _alloc.deallocate(_first, capacity());
    }

  // CAPACITY
    size_type size() const {
      return std::distance(_first, _last);
    }
    size_type max_size() const {
      return _alloc.max_size();
    }

    size_type capacity() const {
      return std::distance(_first, _last_allocated);
    }

    void reserve (size_type new_cap) {
      if (new_cap > max_size()) {
        throw std::length_error("vector::reserve");
      }
      if (new_cap > capacity()) {
        pointer new_first = _alloc.allocate(new_cap);
        std::uninitialized_copy(_first, _last + 1, new_first);
        size_type old_size = size();
        _alloc.deallocate(_first, capacity());
        _last_allocated = new_first + new_cap;
        _last = new_first + old_size;
        _first = new_first;
      }
    }

  // ELEMENT ACCESS
    reference operator[](size_type n) {
      return _first[n];
    }

  // ITERATORS
  iterator begin() {
      return _first;
    }
  const_iterator begin() const {
    return _first;
      }
  iterator end() {
    return _last + 1;
      }
  const_iterator end() const {
    return _last + 1;
    }

  // MODIFIERS
  iterator insert (iterator position, const value_type& val) {
    if (_last == _last_allocated) {
      pointer new_first = _alloc.allocate(size() * 2);
      std::uninitialized_copy(_first, position, new_first);
      std::uninitialized_copy(position, _last, new_first + std::distance(_first, position) + 1);
      _alloc.construct(new_first + std::distance(_first, position), val);
      for (size_type i = 0; i < size(); ++i) {
        _alloc.destroy(_first + i);
      }
      _alloc.deallocate(_first, capacity());
      size_type old_size = size();
      _first = new_first;
      _last = _first + old_size + 1;
      _last_allocated = _first + size() * 2;
    } else {
      iterator old_last = _last;
      ++_last;
      std::copy_backward(position, old_last, position + 1);
      *position = val;
    }
    return position;
  }

  void insert (iterator position, size_type n, const value_type& val) {
    if (n == 0) {
      return;
    }
    if (n > max_size() - size()) {
      throw std::length_error("vector::insert");
    }
    if (n > capacity() - size()) {
      reserve(size() + n);
    }
    iterator old_last = _last;
    _last += n;
    std::copy_backward(position, old_last, position + n);
    for (size_type i = 0; i < n; ++i) {
      _alloc.construct(position + i, val);
    }
  }
};
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
