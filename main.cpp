#include <iostream>
#include "container.h"
#include "operation.h"

const char *filename = "../files/variance_calc.tsv";

int main() {
    const std::vector<unsigned int> positions = {1, 100, 1000000, 500000000};
    Operation operation(filename, positions);
    auto result = operation.get_numbers();
    std::cout << "Позиция 1:        Cкользящее среднее  :" << result[1].first
              << "Стандартное отклонение  :" << result[1].second;
    std::cout << "Позиция 100:      Cкользящее среднее  :" << result[100].first
              << "Стандартное отклонение  :" << result[100].second;
    std::cout << "Позиция 1000000:  Cкользящее среднее  :" << result[1000000].first
              << "Стандартное отклонение  :" << result[1000000].second;
    std::cout << "Позиция 500000000:Cкользящее среднее  :" << result[500000000].first
              << "Стандартное отклонение  :" << result[500000000].second;

    return 0;
}
