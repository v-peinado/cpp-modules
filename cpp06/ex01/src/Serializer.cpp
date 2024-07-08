#include "Serializer.hpp"

/**************
* Constructor *
**************/


/*******************
* Member Functions *
*******************/

uintptr_t Serializer::serialize(Data* ptr)
{
    //Provocar fallo con static_cast
    //return static_cast<uintptr_t>(ptr);
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}