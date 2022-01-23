#include "operation.h"

#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <cstdint>
#include <filesystem>
#include <thread>
#include <cassert>

Operation::Operation(const char *filename_, const std::vector<unsigned int> &positions) : filename(
        filename_),
                                                                                          list(positions.size(),
                                                                                               Container()) {
    if (filename == nullptr) {
        assert(false);
    }
    const std::uintmax_t file_size = std::filesystem::file_size(filename);
    int fd = open(filename, O_RDWR);
    char *region = static_cast<char *>(mmap(nullptr, file_size, PROT_READ, MAP_PRIVATE, fd, 0));
    if (region == MAP_FAILED) {
        close(fd);
        assert(false);
    }

    std::vector<std::thread> threads;
    for (size_t i = 0; i < positions.size(); ++i) {

        threads.emplace_back(std::thread(&Operation::thread_function, this, i, region, file_size,
                                         positions[i]));
    }
    for (size_t i = 0; i < positions.size(); ++i) {
        threads[i].join();
    }

    if (munmap(region, file_size) != 0) {
        close(fd);
        assert(false);
    }
    close(fd);
}

void Operation::thread_function(const int &count, const char *region, const uintmax_t &file_size,
                                const unsigned long &position) {
    auto &elem = list[count];
    if (region == nullptr) {
        assert(false);
    }
    unsigned long pos = 0;
    std::string ss;

    for (unsigned long j = 0; j < file_size; j++) {
        char c = region[j];
        if (c != '\n') {
            ss += c;
        } else {
            elem.add(stod(ss), position);
            ss = "";
            if (pos++ == position - 1) {
                break;
            }
        }
    }
}

void Operation::get_numbers(std::vector<std::pair<long double, long double>> &vec) {

    for (auto &i: list) {
        vec.emplace_back(i.get_moving_average(),i.get_standart_deviation());
    }
}


