#include "Bureaucrat.hpp"

/*******************
    Constructors
*******************/

Bureaucrat::Bureaucrat(std::string name, int lvl) : _name(name), _level(lvl) {
    std::cout << "Bureaucrat " << _name << "has been created" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat " << _name << "has been destroyed" << std::endl;
}

