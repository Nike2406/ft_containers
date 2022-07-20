#ifndef FT_CONTAINERS_STACK_HPP
#define FT_CONTAINERS_STACK_HPP

# include "vector.hpp"
# include <vector>

namespace ft {
    template<class T, class Container = std::vector<T> >
    class stack {
    public:
        typedef T value_type;
        typedef Container container_type;
        typedef typename Container::size_type size_type;

        /*===== Canonical form ======*/
        // This form from off docs
        explicit stack(const container_type &container = container_type()) : _container(container) {}

        stack(const stack &other) : _container(other._container) {}

        stack &operator=(const stack &other) {
            if (this != other)
                _container = other._container;
            return *this;
        }

        ~stack() {}

        /*===== Member functions =====*/
        // Is container empty?
        bool empty() const                  { return (_container.empty()); }
        // Return size
        size_type size() const              { return (_container.size()); }
        // Returns a reference to the top element
        value_type& top()                   { return _container.back(); }
        const value_type& top() const       { return _container.back(); }
        // Removes the element on top
        void pop()                          { _container.pop_back(); }
        // Inserts a new element at the top
        void push (const value_type& val)   { _container.push_back(val); }

        /*===== Relational operators =====*/
        template <class T1, class Container1>
        friend bool operator== (const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

        template <class T1, class Container1>
        friend bool operator!= (const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

        template <class T1, class Container1>
        friend bool operator<  (const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

        template <class T1, class Container1>
        friend bool operator<= (const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

        template <class T1, class Container1>
        friend bool operator> (const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

        template <class T1, class Container1>
        friend bool operator>= (const stack<T1, Container1>& lhs, const stack<T1, Container1>& rhs);

    protected:
        container_type _container;
    };

    template <class T, class Container>
    bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs)    { lhs._container == rhs._container; }

    template <class T, class Container>
    bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)    { lhs._container != rhs._container; }

    template <class T, class Container>
    bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs)    { lhs._container < rhs._container; }

    template <class T, class Container>
    bool operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)    { lhs._container <= rhs._container; }

    template <class T, class Container>
    bool operator> (const stack<T, Container>& lhs, const stack<T, Container>& rhs)     { lhs._container > rhs._container; }

    template <class T, class Container>
    bool operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)    { lhs._container >= rhs._container; }
}

#endif