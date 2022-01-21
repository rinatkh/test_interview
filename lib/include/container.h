#pragma once

#include <vector>
#include <cstddef>

class Container {
private:
    struct Element {
        Element();

        long double data;
        long double sum;
        long double square_sum;
        unsigned long position;

        long double moving_average;
        long double standart_deviation;
    };

public:
    Container();

    Element elem;

    void add(const long double &data_, const unsigned long &position_);

    long double get_moving_average();

    long double get_standart_deviation();
};