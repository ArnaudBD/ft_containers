#ifndef PAIR_HPP
#define PAIR_HPP


namespace ft {
template< class T1, class T2 >
class pair {
  public:
    T1 first;
    T2 second;

    pair() : first(), second() { }
    pair( const T1&, const  ) : first(), second() { }
    template< class U1, class U2 >
    pair( const pair<U1, U2>& ) : first(), second() { }
    pair& operator=( const pair& ) { return *this; }
    ~pair() {}

    void swap( pair& ) {
        T1 tmp = first;
        first = second;
        second = tmp;
    }

    
};
}

#endif
