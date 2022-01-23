#include <iostream>
#include "container.h"
#include "operation.h"

const char *filename = "../files/variance_calc.tsv";

int main() {
    const std::vector<unsigned int> positions = {1, 100};
//    const std::vector<unsigned int> positions = {1, 100, 1000000, 500000000};
    Operation operation(filename, positions);
    operation.get_numbers();

    return 0;
}
