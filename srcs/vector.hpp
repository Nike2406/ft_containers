#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

namespace ft {
    template<class T, class Allocator = std::allocator<T> >
    class vector {
    public:
        typedef T                                           value_type;
        typedef Allocator                                   allocator_type;
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef typename allocator_type::difference_type    difference_type;
        typedef typename allocator_type::size_type          size_type;

        typedef T iterator;
        typedef T const_iterator;
        typedef T reverse_iterator;
        typedef T const_reverse_iterator;
    };
}

#endif
