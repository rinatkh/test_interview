#pragma once

#include "container.h"

#include <vector>
#include <iostream>
#include <cassert>
#include <fcntl.h>
#include <cstdio>
#include <sys/mman.h>
#include <unistd.h>
#include <cstring>
#include <cstdint>
#include <filesystem>
#include <thread>

class Operation {

private:
    std::vector<Container> list;
    const char *filename;
public:

    explicit Operation(const char *filename_, const std::vector<unsigned int> &positions_);

    Operation() = delete;

    std::vector<std::pair<long double, long double>> get_numbers();

    static void threadFunction(const int &count, const char *region, const uintmax_t &file_size,
                               const unsigned long &position);
};
