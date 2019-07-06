#include <iostream>
#include <vector>

template <typename T>
void iter(T *array, std::size_t size, void(*f)(T&)) {
    for (std::size_t i = 0; i < size; ++i) {
        f(array[i]);
    }
}

template <typename T>
void    test(T &input) {
    input = input + input;
}

template <typename T>
void    print(T &input) {
    std::cout << input << std::endl;
}

int main()
{
    int				array_ints[] = {
            11, 222, 33, 42, 5555
    };
    std::string		array_strings[] = {
            "1AA", "2BB", "3CC", "4DD", "5EE"
    };

    iter(array_ints, 5, &test);
    iter(array_strings, 5, &test);

    iter(array_ints, 5, &print);
    iter(array_strings, 5, &print);
    return EXIT_SUCCESS;
}