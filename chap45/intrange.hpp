#ifndef INTRANGE_HPP_
#define INTRANGE_HPP_

class intrange {
public:
    /// Construct an integer range.
    /// If the parameters are in the wrong order, swap them to the right order.
    /// @param low the lower bound of the inclusive range
    /// @param high the upper bound of the inclusive range
    inline intrange(int low, int high): low_ { low }, high_ { high } { }

    /// Check whether a value lies within the inclusive range.
    /// @param test the value to test
    inline bool operator()(int test) const { return test >= low_ and test <= high_; }

private:
    int const low_;
    int const high_;
};

#endif
