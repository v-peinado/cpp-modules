#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2 || !argv[1][0])
    {
        std::cerr << "Usage: ./convert [value]" << std::endl;
        return 1;
    }     
    try
    {   
        //std::string input = argv[1];
        std::string input(argv[1]);
        ScalarConverter::convert(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        std::cerr << std::endl;
    }
    return 0;
}
