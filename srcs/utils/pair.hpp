#ifndef FT_CONTAINERS_PAIR_HPP
#define FT_CONTAINERS_PAIR_HPP

namespace ft
{
    template <class T1, class T2>
    struct pair
    {
        /*
         * This class couples together a pair of values, which may be of different types (T1 and T2).
         * The individual values can be accessed through its public members first and second.
         * */
        typedef T1 first_type;
        typedef T2 second_type;

        first_type  first;
        second_type second;

        pair(const first_type &x = first_type(), const second_type &y = second_type()) : first(x), second(y) {}

        template <class P1, class P2>
        pair(const pair<P1, P2> &other) : first(other.first), second(other.second) {}

        pair &operator=(const pair &other)
        {
            if (this != &other)
            {
                first = other.first;
                second = other.second;
            }
            return *this;
        }
    };

    // Construct pair object
    template <class P1, class P2>
    pair<P1, P2> make_pair(P1 x, P2 y)
    {
        return pair<P1, P2>(x, y);
    }

    template <class P1, class P2>
    bool operator==(const pair<P1, P2> &x, const pair<P1, P2> &y)
    {
        return (x.first == y.first && x.second == y.second);
    }

    template <class P1, class P2>
    bool operator!=(const pair<P1, P2> &x, const pair<P1, P2> &y)
    {
        return (x.first != y.first || x.second != y.second);
    }

    template <class P1, class P2>
    bool operator<(const pair<P1, P2> &x, const pair<P1, P2> &y)
    {
        return (x.first < y.first || (!(x.first < y.first) && x.second < y.second));
    }

    template <class P1, class P2>
    bool operator<=(const pair<P1, P2> &x, const pair<P1, P2> &y)
    {
        return !(y < x);
    }

    template <class P1, class P2>
    bool operator>(const pair<P1, P2> &x, const pair<P1, P2> &y)
    {
        return (y < x);
    }

    template <class P1, class P2>
    bool operator>=(const pair<P1, P2> &x, const pair<P1, P2> &y)
    {
        return !(x < y);
    }
}

#endif
