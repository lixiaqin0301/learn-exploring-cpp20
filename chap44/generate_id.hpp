#ifndef GENERATE_ID_HPP_
#define GENERATE_ID_HPP_

class generate_id {
public:
    generate_id(): counter_ { 0 } { }
    long operator()();

private:
    short counter_;
    static short prefix_;
    static short constexpr max_counter_ { 32767 };
};

#endif
