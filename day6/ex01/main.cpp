#include <iostream>
#include <random>

struct Data {
    std::string s1;
    int n;
    std::string s2;
};

void        print_data(const Data &data) {
    std::cout
    << data.s1 << std::endl
    << data.n << std::endl
    << data.s2 << std::endl;
}

std::string generate_string(size_t len, std::mt19937 gen) {
    std::string result{};
    std::uniform_int_distribution<char> distribution(0, std::numeric_limits<char>::max());
    char leter;

    while (result.length() < len) {
        leter = distribution(gen);
        if (std::isprint(leter))
            result.append(1, leter);
    }
    return result;
}

void    *serialize() {
    auto *result = new Data{};
    std::random_device  device;
    std::mt19937        gen{device()};
    std::uniform_int_distribution<int> distribution(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());


    result->s1 = generate_string(8, gen);
    result->s2 = generate_string(8, gen);
    result->n = distribution(gen);
    std::cout << "Input:" << std::endl;
    print_data(*result);
    return result;
}

Data    *deserialize(void *raw) {
    return reinterpret_cast<Data*>(raw);
}

int main() {
    void    *test = serialize();
    Data    *d = deserialize(test);

    std::cout << std::endl << "Result:" << std::endl;
    print_data(*d);
    return 0;
}