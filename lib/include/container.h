#pragma once

#include <vector>
#include <cstddef>

class Container {
private:
    struct Element {
        long double data = 0.0;
        long double sum = 0.0;
        long double square_sum = 0.0;
        unsigned long position = 0;

        long double moving_average = 0.0;
        long double standart_deviation = 0.0;
    };

public:
    Container() = default;
    ~Container() = default;
    Element elem;

    void add(const long double &data_, const unsigned long &position_);

    long double get_moving_average();

    long double get_standart_deviation();

    unsigned long get_position();
};