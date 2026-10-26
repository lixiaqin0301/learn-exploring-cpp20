/** Listing 52-8. Defining the Assignment Operator Function Template */
template <class T>
class rational {
public:
    template <class U> rational<T> &operator=(rational<U> const &rhs);
    void assign(int, int) { }

    T numerator() const { return 0; }
    T denominator() const { return 1; }
};

template <class T>
template <class U>
rational<T> &
rational<T>::operator=(rational<U> const &rhs)
{
    assign(rhs.numerator(), rhs.denominator());
    return *this;
}

int
main()
{
    rational<int> r1;
    rational<long> r2;
    r1 = r2;
    r2 = r1;
    return sizeof(r2) == sizeof(r1);
}
