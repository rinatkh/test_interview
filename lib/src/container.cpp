#include "container.h"
#include <cmath>
#include <iostream>


void Container::add(const long double &data_, const unsigned long &position_) {

    elem.data = data_;
    elem.sum = elem.sum + data_;
    elem.square_sum = elem.square_sum + pow(data_, 2);

    elem.position = position_;
    std::cout << elem.position << " " << elem.data << " " << elem.sum << " " << elem.square_sum << '\n';
}

long double Container::get_standart_deviation() {
    if (elem.standart_deviation != 0) {
        return elem.standart_deviation;
    }
    elem.standart_deviation = sqrt(
            (elem.square_sum + elem.position * pow(elem.moving_average, 2) -
             2 * elem.standart_deviation) / (elem.position - 1));
    return elem.standart_deviation;
}

long double Container::get_moving_average() {
    if (elem.moving_average != 0) {
        return elem.moving_average;
    }
    elem.moving_average = elem.sum / elem.position;
    return elem.moving_average;
}

Container::Container() : elem() {}

unsigned long Container::get_position() {
    return elem.position;
}

Container::Element::Element() : data(0),
                                sum(0),
                                square_sum(0),
                                position(0),
                                moving_average(0),
                                standart_deviation(0) {}
