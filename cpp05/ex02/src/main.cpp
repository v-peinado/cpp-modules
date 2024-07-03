
#include "AForm.hpp"
#include "Bureaucrat.hpp"

int main(void) {
    std::cout << "===========================" << std::endl;
    std::cout << "Create forms and bureacrats" << std::endl;
    std::cout << "===========================" << std::endl;

    Bureaucrat b("(O_O)", 9);
    std::cout << std::endl;
    std::cout << "============================" << std::endl;
    std::cout << "Overload of the («) operator" << std::endl;
    std::cout << "============================" << std::endl;

    std::cout << b << std::endl;
    std::cout << std::endl;

    return 0;
}