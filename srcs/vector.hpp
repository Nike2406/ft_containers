#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory> // for std::allocator
#include <iostream>

namespace ft {
    template<class T, class Allocator = std::allocator<T> >
    class vector {
    public:
        typedef T value_type;
        typedef Allocator allocator_type;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::difference_type difference_type;
        typedef typename allocator_type::size_type size_type;

        typedef T iterator;
        typedef T const_iterator;
        typedef T reverse_iterator;
        typedef T const_reverse_iterator;

    private:
        pointer _array;
        size_type _size;
        size_type _capacity;
        allocator_type _alloc;

    public:
        /***** Member functions ******/
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
               const allocator_type &alloc = allocator_type())
                : _array(0), _size(0), _capacity(0), _alloc(alloc) {

        };

        // copy
        vector(const vector &x) {};
//////////////////////////////////

        /***** Capacity ******/
        // return vector size
        size_type size() const      { return _size; }
        // return maximum size which vector can allocate
        size_type max_size() const  { return _alloc.max_size(); }
        // change container size with n elements
        void resize (size_type n, value_type val = value_type()) {
            if (n > this->max_size())
                throw std::length_error("vector::_M_fill_insert");
            if (n == _size)
                return;
            else if (n < _size) {
                while (_size > n) {
                    // TODO realise after movement pop/push
                    // _alloc.destroy(last)
                }
            }
        }

        // reserve n elements for container
        void reserve(size_t n) { // std::vector::reserve
            try {
                if (_capacity < n) {
                    pointer newArray = _alloc.allocate(n);
                }
            } catch (const std::length_error &le) {
                std::cerr << "Length error: " << le.what() << '\n';
            }
        }
    };
}

#endif
