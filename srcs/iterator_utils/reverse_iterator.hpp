#ifndef FT_CONTAINERS_REVERSE_ITERATOR_HPP
#define FT_CONTAINERS_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
    template<class Iterator>
    class reverse_iterator {

    public:
        typedef Iterator                                                iterator_type;
        typedef typename iterator_traits<Iterator>::iterator_category   iterator_category;
        typedef typename iterator_traits<Iterator>::value_type          value_type;
        typedef typename iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename iterator_traits<Iterator>::pointer             pointer;
        typedef typename iterator_traits<Iterator>::reference           reference;

    private:
        iterator_type _iter;

    public:
        /***** Member functions ******/
        // default
        reverse_iterator() : _iter(0) {}

        // initialization
        explicit reverse_iterator(iterator_type it) : _iter(it) {}

        // copy
        template<class Iter>
        reverse_iterator(const reverse_iterator<Iter> &rev_it) : _iter(rev_it.base()) {}

        // destructor
        virtual ~reverse_iterator() {}

        reverse_iterator &operator=(const reverse_iterator &rev_it) {
            if (this == &rev_it) {
                return *this;
            }
            this->_iter = rev_it._iter;
            return *this;
        }

        iterator_type base() const {
            return _iter;
        }

        reference operator*() const {
            iterator_type tmp = _iter;
            return *tmp;
        }

        pointer operator->() const {
            return &operator*();
        }

        reference operator[](difference_type n) const {
            return base()[-n - 1];
        }

        reverse_iterator &operator++() {
            --_iter;
            return *this;
        }

        reverse_iterator &operator--() {
            ++_iter;
            return *this;
        }

        reverse_iterator operator++(int) {
            reverse_iterator copy = *this;
            --_iter;
            return copy;
        }

        reverse_iterator operator--(int) {
            reverse_iterator copy = *this;
            ++_iter;
            return copy;
        }

        reverse_iterator &operator+=(difference_type n) {
            _iter -= n;
            return *this;
        }

        reverse_iterator &operator-=(difference_type n) {
            _iter += n;
            return *this;
        }

        reverse_iterator operator+(difference_type n) const {
            return reverse_iterator<Iterator>(_iter - n);
        }

        reverse_iterator operator-(difference_type n) const {
            return reverse_iterator<Iterator>(_iter + n);
        }

        bool operator==(const reverse_iterator &other) const {
            return this->base() == other.base();
        }

        bool operator!=(const reverse_iterator &other) const {
            return this->base() != other.base();
        }

        bool operator<(const reverse_iterator &other) const {
            return this->base() > other.base();
        }

        bool operator<=(const reverse_iterator &other) const {
            return this->base() >= other.base();
        }

        bool operator>(const reverse_iterator &other) const {
            return this->base() < other.base();
        }

        bool operator>=(const reverse_iterator &other) const {
            return this->base() <= other.base();
        }
    };

    /***** Non-member function overloads ******/
    // relational operators
    template<class Iter1, class Iter2>
    bool operator==(reverse_iterator<Iter1> &lhs, reverse_iterator<Iter2> &rhs) {
        return lhs.base() == rhs.base();
    }

    template<class Iter1, class Iter2>
    bool operator!=(reverse_iterator<Iter1> &lhs, reverse_iterator<Iter2> &rhs) {
        return lhs.base() != rhs.base();
    }

    template<class Iter1, class Iter2>
    bool operator<(reverse_iterator<Iter1> &lhs, reverse_iterator<Iter2> &rhs) {
        return lhs.base() > rhs.base();
    }

    template<class Iter1, class Iter2>
    bool operator<=(reverse_iterator<Iter1> &lhs, reverse_iterator<Iter2> &rhs) {
        return lhs.base() >= rhs.base();
    }

    template<class Iter1, class Iter2>
    bool operator>(reverse_iterator<Iter1> &lhs, reverse_iterator<Iter2> &rhs) {
        return lhs.base() < rhs.base();
    }

    template<class Iter1, class Iter2>
    bool operator>=(reverse_iterator<Iter1> &lhs, reverse_iterator<Iter2> &rhs) {
        return lhs.base() <= rhs.base();
    }

    // operator+
    template<class Iterator>
    reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
                                         const reverse_iterator<Iterator> &other) {
        return other + n;
    }

    // operator-
    template<class Iterator>
    reverse_iterator<Iterator> operator-(typename reverse_iterator<Iterator>::difference_type n,
                                         const reverse_iterator<Iterator> &other) {
        return n - other;
    }

    template<class Iter1, class Iter2>
    typename reverse_iterator<Iter1>::difference_type operator-(reverse_iterator<Iter1> &lhs, reverse_iterator<Iter2> &rhs) {
        return rhs.base() - lhs.base();
    }
}

#endif
