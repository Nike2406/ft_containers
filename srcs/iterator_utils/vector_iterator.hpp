#ifndef FT_CONTAINERS_VECTOR_ITERATOR_HPP
#define FT_CONTAINERS_VECTOR_ITERATOR_HPP

# include <memory>

namespace ft {
    template<class T>
    class vector_iterator {
    public:
        typedef std::ptrdiff_t                  difference_type;
        typedef T                               value_type;
        typedef value_type                      *pointer;
        typedef const value_type                *const_pointer;
        typedef value_type                      &reference;
        typedef const value_type                &const_reference;
        typedef std::random_access_iterator_tag iterator_category;

    private:
        pointer _pointer;
    public:

        vector_iterator() : _pointer(0) {}

        explicit vector_iterator(pointer ptr) : _pointer(ptr) {}

        vector_iterator(const vector_iterator &other) : _pointer(other._pointer) {}

        virtual ~vector_iterator() {}

        vector_iterator &operator=(const vector_iterator &other) {
            if (this == &other) {
                return *this;
            }
            this->_pointer = other._pointer;
            return *this;
        }

        operator vector_iterator<const value_type>() const {
            return vector_iterator<const value_type>(_pointer);
        }

        /***** Member functions ******/
        reference operator*() {
            return *_pointer;
        }

        const_reference operator*() const {
            return *_pointer;
        }

        pointer operator->() {
            return _pointer;
        }

        const_pointer operator->() const {
            return _pointer;
        }

        reference operator[](difference_type n) {
            return *(_pointer + n);
        }

        const_reference operator[](difference_type n) const {
            return *(_pointer + n);
        }

        pointer base(void) const {
            return _pointer;
        }

        vector_iterator &operator++() {
            ++_pointer;
            return *this;
        }

        vector_iterator &operator--() {
            --_pointer;
            return *this;
        }

        vector_iterator operator++(int) {
            vector_iterator copy = *this;
            ++_pointer;
            return copy;
        }

        vector_iterator operator--(int) {
            vector_iterator copy = *this;
            --_pointer;
            return copy;
        }

        vector_iterator &operator+=(difference_type n) {
            _pointer += n;
            return *this;
        }

        vector_iterator &operator-=(difference_type n) {
            _pointer -= n;
            return *this;
        }

        vector_iterator operator+(difference_type n) const {
            return vector_iterator<T>(_pointer + n);
        }

        vector_iterator operator-(difference_type n) const {
            return vector_iterator<T>(_pointer - n);
        }

        difference_type operator+(const vector_iterator &other) const {
            return base() + other.base();
        }

        difference_type operator-(const vector_iterator &other) const {
            return base() - other.base();
        }

        bool operator==(const vector_iterator &other) const {
            return base() == other.base();
        }

        bool operator!=(const vector_iterator &other) const {
            return base() != other.base();
        }

        bool operator<(const vector_iterator &other) const {
            return base() < other.base();
        }

        bool operator<=(const vector_iterator &other) const {
            return base() <= other.base();
        }

        bool operator>(const vector_iterator &other) const {
            return base() > other.base();
        }

        bool operator>=(const vector_iterator &other) const {
            return base() >= other.base();
        }
    };

    /***** Non-member function overloads ******/
    template<class T, class V>
    bool operator==(vector_iterator<T> &first, vector_iterator<V> &second) {
        return first.base() == second.base();
    }

    template<class T, class V>
    bool operator!=(vector_iterator<T> &first, vector_iterator<V> &second) {
        return first.base() != second.base();
    }

    template<class T, class V>
    bool operator<(vector_iterator<T> &first, vector_iterator<V> &second) {
        return first.base() < second.base();
    }

    template<class T, class V>
    bool operator<=(vector_iterator<T> &first, vector_iterator<V> &second) {
        return first.base() <= second.base();
    }

    template<class T, class V>
    bool operator>(vector_iterator<T> &first, vector_iterator<V> &second) {
        return first.base() > second.base();
    }

    template<class T, class V>
    bool operator>=(vector_iterator<T> &first, vector_iterator<V> &second) {
        return first.base() >= second.base();
    }

    template<class T>
    vector_iterator<T> operator+(typename ft::vector_iterator<T>::difference_type n,
                                 const vector_iterator<T> &other) {
        return (other + n);
    }
}
#endif
