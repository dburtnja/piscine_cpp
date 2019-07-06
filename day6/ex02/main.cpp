#include <iostream>
#include <random>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate() {
    char    val;
    std::random_device  device;
    std::mt19937        gen(device());
    std::uniform_int_distribution   distribution(0, 2);

    val = distribution(gen);
    switch (val) {
        case 0:
            std::cout << "Class A created" << std::endl;
            return new A{};
        case 1:
            std::cout << "Class B created" << std::endl;
            return new B{};
        case 2:
            std::cout << "Class C created" << std::endl;
            return new C{};
        default:
            std::cout << "Null ptr returned" << std::endl;
            return nullptr;
    }
}

void identify_from_pointer(Base *pBase) {
    if (dynamic_cast<A*>(pBase) != nullptr)
        std::cout << "A" << std::endl;
    if (dynamic_cast<B*>(pBase) != nullptr)
        std::cout << "B" << std::endl;
    if (dynamic_cast<C*>(pBase) != nullptr)
        std::cout << "C" << std::endl;

}

void identify_from_reference(Base &base) {
    try {
        dynamic_cast<A&>(base);
        std::cout << "A" << std::endl;
        return;
    } catch (std::bad_cast &e) {}
    try {
        dynamic_cast<B&>(base);
        std::cout << "B" << std::endl;
        return;
    } catch (std::bad_cast &e) {}
    try {
        dynamic_cast<C&>(base);
        std::cout << "C" << std::endl;
        return;
    } catch (std::bad_cast &e) {}
}

int main() {
    Base    *base;

    base = generate();
    identify_from_pointer(base);
    identify_from_reference(*base);
}