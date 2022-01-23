#include "container.h"
#include <cmath>

void Container::add(const long double &data_, const unsigned long &position_) {

    elem.data = data_;
    elem.sum = elem.sum + data_;
    elem.square_sum = elem.square_sum + pow(data_, 2);

    elem.position = position_;
}

long double Container::get_standart_deviation() {
    if (elem.position == 1) {
        return 0;
    }
    if (elem.standart_deviation != 0) {
        return elem.standart_deviation;
    }
    elem.standart_deviation = sqrt(
            (elem.square_sum - (pow(elem.sum, 2) / elem.position)) / (elem.position - 1));
    return elem.standart_deviation;
}

long double Container::get_moving_average() {
    if (elem.moving_average != 0) {
        return elem.moving_average;
    }
    elem.moving_average = elem.sum / elem.position;
    return elem.moving_average;
}

unsigned long Container::get_position() {
    return elem.position;
}
