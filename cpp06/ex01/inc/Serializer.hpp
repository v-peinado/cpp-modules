#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct s_Data
{
    int value;
}Data;

class Serializer
{
    private:

        Serializer();
        Serializer(const Serializer &other);
        ~Serializer();
        Serializer &operator=(const Serializer &rhs);

    public:

        static uintptr_t serialize(Data* ptr);
        static Data *deserialize(uintptr_t raw);
};

#endif