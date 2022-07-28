#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory> // for std::allocator

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

    private:
        pointer         _array;
        size_type       _size;
        size_type       _capacity;
        allocator_type  _alloc;

    public:
        /***** Member functions ******/
        /***** Canonical form ******/
        // default
        explicit vector(const allocator_type &alloc = allocator_type())
                : _array(0), _size(0), _capacity(0), _alloc(alloc) {};

        // fill
        explicit vector(size_type n, const value_type &val = value_type(),
                        const allocator_type &alloc = allocator_type())
                : _array(0), _size(0), _capacity(0), _alloc(alloc) {
            if (n == 0)
                return;
            pointer newArray = _alloc.allocate(n);
            for (size_t i = 0; i < n; i++) {
                _alloc.construcr(_array + i, val);
            }
            _size = n;
        };

        // range
        template<class InputIterator>
        vector(InputIterator first, InputIterator last,
               const allocator_type &alloc = allocator_type()) {};

        // copy
        vector(const vector &x) {};
//////////////////////////////////

    };
}

#endif
