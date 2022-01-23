#pragma once

#include "container.h"

#include <iostream>

class Operation {

private:
    std::vector<Container> list;
    const char *filename;

    void thread_function(const int &count, const char *region, const uintmax_t &file_size,
                         const unsigned long &position);

public:

    explicit Operation(const char *filename_, const std::vector<unsigned int> &positions_);

    Operation() = delete;

    ~Operation() = default;

    void get_numbers(std::vector<std::pair<long double, long double>> &vec);

};
