#include "operation.h"


Operation::Operation(const char *filename_, const std::vector<unsigned int> &positions) : filename(
        filename_) {
    list.resize(positions.size(), Container());
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
    int count_positions = 0;
    const size_t thread_nom = std::thread::hardware_concurrency();
    for (size_t j = 0; j < (positions.size() - 1) / thread_nom + 1; ++j) {
        for (size_t i = 0; i < thread_nom; ++i) {
            std::thread thr(threadFunction, count_positions, region, file_size,
                            positions[count_positions]);
            thr.join();
            if (count_positions++ >= positions.size()) {
                break;
            }
        }
    }
}

void Operation::threadFunction(const int &count, const char *region, const uintmax_t &file_size,
                               const unsigned long &position) {
    auto &elem = list[count];
    if (region == nullptr) {
        assert(false);
    }
    unsigned long pos = 0;
    for (unsigned long j = 0; j < file_size; j++) {
        char c = region[j];
        std::string ss;
        if (c != '\n') {
            ss += c;
        } else {
            elem.add(std::stold(ss), position);
            ss = "";
            if (pos++ >= position) {
                break;
            }
        }
    }
}

std::vector<std::pair<long double, long double>> Operation::get_numbers() {
    std::vector<std::pair<long double, long double>> result;

    for (auto &i: list) {
        result.emplace_back(i.get_moving_average(), i.get_standart_deviation());
    }
    return result;
}


