/** Listing 33-3. Assignment of an Integer to a rational */
class rational {
public:
    rational &operator=(int num)
    {
        this->numerator = num;
        this->denominator = 1; // no need to call reduce()
        return *this;
    }
    int numerator, denominator;
};
int
main()
{
    rational r {};
    r = 2;
    return 0;
}
