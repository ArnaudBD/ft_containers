#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP





template<class T, T v>
struct integral_constant {
    static const T value = v;
    typedef T value_type;
    typedef integral_constant type;
	operator value_type() const { return value; }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template<typename T> struct is_integral : public integral_constant<bool, false> {};
template<> struct is_integral<bool> : public integral_constant<bool, true> {};
template<> struct is_integral<char> : public integral_constant<bool, true> {};
template<> struct is_integral<signed char> : public integral_constant<bool, true> {};
template<> struct is_integral<unsigned char> : public integral_constant<bool, true> {};
template<> struct is_integral<wchar_t> : public integral_constant<bool, true> {};
template<> struct is_integral<short> : public integral_constant<bool, true> {};
template<> struct is_integral<unsigned short> : public integral_constant<bool, true> {};
template<> struct is_integral<int> : public integral_constant<bool, true> {};
template<> struct is_integral<unsigned int> : public integral_constant<bool, true> {};
template<> struct is_integral<long> : public integral_constant<bool, true> {};
template<> struct is_integral<unsigned long> : public integral_constant<bool, true> {};
template<> struct is_integral<long long> : public integral_constant<bool, true> {};
template<> struct is_integral<unsigned long long> : public integral_constant<bool, true> {};

/*
struct true_type
{
	static const bool value = true;
};

struct false_type
{
	static const bool value = false;
};

template <typename T>
struct is_integral
{
	static const bool value = false;
};

template <>
struct is_integral<int> : type(true_type)
{
};

template <>
struct is_integral<unsigned int> : true_type
{
};

template <>
struct is_integral<long> : true_type
{
};

template <>
struct is_integral<unsigned long> : true_type
{
};

template <>
struct is_integral<long long> : true_type
{
};

template <>
struct is_integral<unsigned long long> : true_type
{
};

template <>
struct is_integral<char> : true_type
{
};

template <>
struct is_integral<unsigned char> : true_type
{
};

template <>
struct is_integral<short> : true_type
{
};

template <>
struct is_integral<unsigned short> : true_type
{
};

template <typename T>
struct is_integral<const T> : is_integral<T>
{
};
*/
#endif