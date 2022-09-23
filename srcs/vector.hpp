#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <memory> // for std::allocator
#include <iostream>
#include "./utils/enable_if.hpp"
#include "./utils/is_integral.hpp"
#include "./utils/equal.hpp"
#include "./utils/lexicographical_compare.hpp"

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
        vector(InputIterator first,
               InputIterator last,
               const allocator_type &alloc = allocator_type(),
               typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
                : _array(0), _size(0), _capacity(0), _alloc(alloc) {
            clear();
            reserve(std::distance(first, last));
            for (InputIterator it = first; it != last; it++) {
                _alloc.constuct(_array + _size, *it);
                ++_size;
            }
        };

        // copy
        vector(const vector &x)
        : _array(0), _size(0), _capacity(0), _alloc(x._alloc) {
            clear();
            reserve(x._capacity);
            for (int i = 0; i <x._size; ++i) {
                this->_alloc.construct(this->_array + i, x._array[i]);
            }
            this->_size = x._size;
        };

        vector& operator=(const vector& other)
        {
            if (this != &other)
            {
                clear();
                this->allocator.deallocate(_array, _capacity);
                this->_size = other.size();
                this->_capacity = other.capacity();
                this->array = _alloc.allocate(_capacity);
                for (size_t i = 0; i < other._size; ++i)
                    this->allocator.construct(this->array + i, other.array[i]);
            }
            return *this;
        }

        // destructor
        virtual ~vector() {
            clear();
            if (_capacity) {
                _alloc.deallocate(_array, _capacity);
            }
        }

        /***** Iterators ******/
        iterator                begin()             { return iterator(_array); } // Return iterator to beginning
        const_iterator          begin() const       { return const_iterator(_array); } // Return iterator to end
        iterator                end()               { return iterator(_array + _size); } // Return reverse iterator to reverse beginning
        const_iterator          end() const         { return const_iterator(_array + _size); } // Return reverse iterator to reverse end
        reverse_iterator        rbegin()            { return reverse_iterator(--end()); } // Return const_iterator to beginning
        const_reverse_iterator  rbegin() const      { return const_reverse_iterator(--end()); } // Return const_iterator to end
        reverse_iterator        rend()              { return reverse_iterator(begin()); } // Return const_reverse_iterator to reverse beginning
        const_reverse_iterator  rend() const        { return const_reverse_iterator(begin()); } // Return const_reverse_iterator to reverse end

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
                    pop_back();
                }
            } else if (n > _size) {
                while (_size < n) {
                    push_back(val);
                }
            }
        }

        // returns vector capacity
        size_type capacity() const      { return this->_capacity; }

        // returns whether the vector is empty
        bool empty() const      { return this->_size == 0; };

        // reserve n elements for container
        void reserve(size_t n) { // std::vector::reserve
            try {
                if (n > _capacity) {
                    pointer newArray = _alloc.allocate(n);
                    for (size_t i = 0; i < _size; i++) {
                        _alloc.construct(newArray + i, _array[i]);
                        _alloc.destroy(_array + i);
                    }
                    _alloc.deallocate(_array, _capacity);
                    _array = newArray;
                    _capacity = n;
                } else {
                    return;
                }
            } catch (const std::length_error &le) {
                std::cerr << "Length error: " << le.what() << '\n';
            }
        }

        /***** Element access ******/
        reference operator[] (size_type n)                  { return *(_array + n); } //Access element
        const_reference operator[] (size_type n) const      { return *(_array + n); }
        reference front()                                   { return *_array; } // Access first element
        const_reference front() const                       { return *_array; }
        reference back()                                    { return *(_array + (_size - 1)); } // Access last element
        const_reference back() const                        { return *(_array + (_size - 1)); }
        value_type* data()                                  { return _array; } // Access data
        const value_type* data() const                      { return _array; }

        reference at (size_type n) { // Access element
            if (n >= _size)
                throw std::out_of_range("Vector is out of range!");
            return *(_array + n);
        }
        const_reference at (size_type n) const {
            if (n >= _size)
                throw std::out_of_range("Vector is out of range!");
            return *(_array + n);
        }

        /***** Modifiers ******/
        // Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
        template <class InputIterator>
        void assign (InputIterator first,
                     InputIterator last,
                     typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) {
            clear();
            reserve(std::distance(first, last));
            while (first != last) {
                push_back(*first);
                first++;
            }
        }

        void assign (size_type n, const value_type& val) {
            if (n > 0) {
                clear();
                reserve(n);
                for (int i = 0; i < n; ++i) {
                    push_back(val);
                }
            } else {
                clear();
            }
        }

        // Add element at the end
        void push_back (const value_type& val) {
            if (_capacity == _size && _capacity) {
                reserve(_capacity * 2);
            } else {
                reserve(1);
            }
            _alloc.construct(_array + _size, val);
            _size++;
        }

        // Delete last element
        void pop_back() {
            _alloc.destroy(_array + _size - 1);
            _size--;
        }

        // Delete all elements from vector
        void clear() {
            if (!_array)
                return;
            for (int i = 0; i < _size; ++i) {
                _alloc.destroy(_array + i);
            }
            _size = 0;
        }

        // Insert elements
        iterator insert (iterator position, const value_type& val) {
            difference_type start = std::distance(this->begin());
            size_type i = 0;

            if (_capacity == _size && _capacity) {
                reserve(_capacity * 2);
            } else {
                reserve(1);
            }
            for (i = _size; i > static_cast<size_type>(start) ; i--) {
                _array[i] = _array[i - 1];
            }
            _alloc.construct(_array + i, val);
            _size++;
            return iterator(_array + start);
        }

        void insert (iterator position, size_type n, const value_type& val) {
            difference_type start = std::distance(this->begin());
            if (n == 0)
                return;
            if (_size + n > _capacity) {
                if (n > _size)
                    reserve(_size + n);
                else
                    reserve(_capacity * 2);
            }
            for (size_type i = _size; i > static_cast<size_type>(start) ; i--) {
                _array[i + n - 1] = _array[i - 1];
            }
            for (size_type i = 0; i < n; i++) {
                _alloc.construct(_array + start + i, val);
            }
            _size += n;
        }

        template <class InputIterator>
        void insert (iterator position,
                     InputIterator first,
                     InputIterator last,
                     typename ft::enable_if< !ft::is_integral< InputIterator >::value, InputIterator >::type* = 0) {
            size_t range_size = last - first;
            if (!valid_iterator(first, last, range_size))
                throw std::exception();
            size_t new_size = _size + range_size;

            int last_index = (position - begin()) + range_size - 1;
            if (range_size >= _capacity) {
                reserve(_capacity + range_size);
                _size = new_size;
            } else {
                while (_size != new_size) {
                    if (_size == _capacity)
                        reserve(_capacity * 2);
                    _size++;
                }
            }
            for (int i = _size - 1; i >= 0; --i) {
                if (i == last_index) {
                    for (; range_size > 0; --range_size, --i) {
                        _array[i] = *--last;
                    }
                    return;
                }
                _array[i] = _array[i - range_size];
            }
        }

        // Removes from the vector either a single element (position) or a range of elements
        iterator erase(iterator pos)
        {
            difference_type start = std::distance(this->begin(), pos);
            _alloc.destroy(_array + start);
            start = static_cast<size_type>(start);
            for (size_type i = start; i < _size - 1; ++i) {
                _array[i] = _array[i + 1];
            }
            --_size;
            return pos;
        }

        iterator erase(iterator first, iterator last) {
            difference_type start = std::distance(this->begin(), first);
            if (first == last) {
                return iterator(_array + start);
            }
            difference_type count = std::distance(first, last);
            for (iterator it = first; it != last; ++it) {
                _alloc.destroy(&(*it));
            }
            for (size_type i = static_cast<size_type>(start); i < _size - count; ++i) {
                _array[i] = _array[i + count];
            }
            _size -= count;
            return first;
        }

        // Exchanges the content of the container by the content of x, which is another vector object
        // of the same type. Sizes may differ.
        void swap (vector& x) {
            value_type *tmp_box = this->_box;
            size_type tmp_size = this->_size;
            size_type tmp_capacity = this->_capacity;

            this->_box = x._box;
            this->_size = x._size;
            this->_capacity = x._capacity;

            x._box = tmp_box;
            x._size = tmp_size;
            x._capacity = tmp_capacity;
        }

        /***** Allocator ******/
        allocator_type get_allocator() const {
            return this->_alloc;
        }

    private:
        template<class InputIt>
        typename ft::enable_if<!ft::is_integral<InputIt>::value, bool>::type
        valid_iterator(InputIt first, InputIt last, size_t range) {
            pointer reserved_buffer;
            reserved_buffer = _alloc.allocate(range);
            bool result = true;
            size_t i = 0;

            for (;first != last; ++first, ++i) {
                try {
                    reserved_buffer[i] = *first;
                }
                catch (...) {
                    result = false; break;
                }
            }
            _alloc.deallocate(reserved_buffer, range);
            return result;
        }
    };

        /***** Non-member function ******/

        template <class T, class Alloc>
        void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
            x.swap(y);
        }

        template <class T1, class T2>
        bool operator== (const ft::vector<T1,T2>& lhs, const ft::vector<T1,T2>& rhs) {
            if (lhs.size() == rhs.size())
                return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
            return false;
        }
        template <class T1, class T2>
        bool operator!= (const vector<T1,T2>& lhs, const vector<T1,T2>& rhs) {
            return !(lhs == rhs);
        }
        template <class T1, class T2>
        bool operator<  (const vector<T1,T2>& lhs, const vector<T1,T2>& rhs) {
            return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }
        template <class T1, class T2>
        bool operator<= (const vector<T1,T2>& lhs, const vector<T1,T2>& rhs) {
            if (lhs == rhs) return true;
            return (lhs < rhs);
        }
        template <class T1, class T2>
        bool operator>  (const vector<T1,T2>& lhs, const vector<T1,T2>& rhs) {
            return ft::lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
        }
        template <class T1, class T2>
        bool operator>= (const vector<T1,T2>& lhs, const vector<T1,T2>& rhs) {
            if (lhs == rhs) return true;
            return (lhs > rhs);
        }
}

#endif
