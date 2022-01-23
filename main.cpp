#include "container.h"
#include "operation.h"

const char *filename = "../files/variance_calc.tsv";

int main() {
    const std::vector<unsigned int> positions = {1, 100, 1000000, 500000000};
    Operation operation(filename, positions);
    std::vector<std::pair<long double, long double>> vec;
    operation.get_numbers(vec);

    int pos = 0;
    for (auto &i: vec) {
        std::cout << "Позиция :   " << positions[pos++] << "  Cкользящее среднее  :  "
                  << std::to_string(i.first)
                  << "   Стандартное отклонение  :  " << std::to_string(i.second)
                  << '\n';
    }
    return 0;
}
