#ifndef BURO_HPP
#define BURO_HPP

#define HIGH
#define LOW

#include <iostream>
#include <string>

class Bureaucrat {
    private:
        const std::string _name;
        int _level;
        Bureaucrat();
    public:
        Bureaucrat(std::string name, int lvl); 
        ~Bureaucrat();
}

#endif