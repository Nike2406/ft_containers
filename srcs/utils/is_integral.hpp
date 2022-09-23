#ifndef FT_CONTAINERS_IS_INTEGRAL_HPP
#define FT_CONTAINERS_IS_INTEGRAL_HPP

namespace ft {
    template <class T, T v>
    struct integral_constant {
        typedef T value_type;
        typedef  integral_constant<T, v> type;

        static  const value_type value = v;

        operator value_type() const {
            return value;
        }
    };

    template<class T> struct is_integral : ft::integral_constant<bool, false> {};
    template<> struct is_integral<bool> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<char> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<wchar_t> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<short> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<int> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<long> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<long long> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned long> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned char> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned short> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned int> : ft::integral_constant<bool, true> {};
    template<> struct is_integral<unsigned long long> : ft::integral_constant<bool, true> {};
}

#endif
