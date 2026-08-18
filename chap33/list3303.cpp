/** Listing 33-3. Assignment of an Integer to a rational */
class rational {
public:
    rational() = default;
    rational(rational const &) = default;
    rational(rational &&) = default;
    rational &operator=(rational const &) = default;
    rational &operator=(rational &&) = default;
    rational &operator=(int num)
    {
        this->numerator = num;
        this->denominator = 1; // no need to call reduce()
        return *this;
    }

private:
    int numerator = 0;
    int denominator = 1;
};
int
main()
{
    rational r {};
    r = 2;
    return 0;
}
