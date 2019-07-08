#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector vector = {1, 2, 3, 4};
    std::cout << easyfind(vector, 80) << std::endl;
    std::cout << easyfind(vector, 1) << std::endl;
    std::cout << easyfind(vector, 3) << std::endl;
    return EXIT_SUCCESS;
}