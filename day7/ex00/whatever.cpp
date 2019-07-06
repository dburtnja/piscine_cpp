//
// Created by denys on 06.07.19.
//


#include <iostream>

template<typename T>
void swap(T &first, T &second) {
    T   temp;
    temp = first;
    first = second;
    second = temp;
}

template<typename T>
const T &min(const T &first, const T &second) {
    if (second <= first)
        return second;
    return first;
}

template<typename T>
const T &max(const T &fist, const T &second) {
    if (second >= fist)
        return second;
    return fist;
}

int main()
{
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    return (0);
}
