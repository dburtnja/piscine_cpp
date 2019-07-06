#include <iostream>
#include <tuple>
#include <regex>
#include <iomanip>

const char IMPOSSIBLE[] = "impossible" ;


double  get_result(std::string input, bool &error) {
    error = false;
    std::regex reg("\'(a)\'");
    input = std::regex_replace(input, reg, "$1");

    double result;
    if (input.size() == 1 && !std::isdigit(input[0]))
    {
        result = static_cast<double>(input[0]);
    }
    else
    {
        try
        {
            result = std::stod(input);
        }
        catch (std::exception& e)
        {
            std::cout << e.what() << std::endl;
            result = -1;
            error = true;
        }
    }
    return result;
}

std::string get_result_char(double input) {
    if (input > std::numeric_limits<char>::max() or input != input)
        return IMPOSSIBLE;
    char c = static_cast<char>(input);
    return std::isprint(c) ? "'" + std::string(1, c) + "'" : "Non displayable";
}

void print_result(double result) {
    std::cout << std::setprecision(1) << std::fixed;
    std::cout << "char: " << get_result_char(result) << std::endl;
    std::cout << "int: ";
    if (result > std::numeric_limits<int>::max() or result != result)
        std::cout << IMPOSSIBLE;
    else
        std::cout << static_cast<int>(result);
    std::cout << std::endl;
    std::cout
            << "float: " << static_cast<float>(result) << "f" << std::endl
            << "double: " << result << std::endl;
}

int main(int argc, char **argv) {
    bool error;

    if (argc == 2) {
        auto result = get_result(argv[1], error);
        if (error)
        {
            for (auto name : {"char", "int", "float", "double"}) {
                std::cout << name << ": impossible" << std::endl;
            }
            return EXIT_FAILURE;
        }
        print_result(result);
    }
    return EXIT_SUCCESS;
}