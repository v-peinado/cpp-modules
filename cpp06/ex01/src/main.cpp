#include "Serializer.hpp"

/*
    La serialización es el proceso de convertir un objeto en una secuencia
    de bytes para almacenarlo o transmitirlo a través de una red y que 
    después pueda ser reconstruido.
    En este ejemplo se serializa el puntero en un entero sin signo de 64 bits,
    que es lo suficientemente grande para almacenar la dirección de memoria y 
    facil de almacenar en un archivo o enviar por la red, donde a veces no se
    pueden enviar punteros o se intentan almacenar en estructuras que no admiten
    punteros.
    Resumiendo, El uso de 'uintptr_t' para serializar punteros es una técnica que permite la manipulación,
    almacenamiento y transmisión de punteros en contextos donde los punteros directos
    no son aplicables o no tienen sentido. 

    El tipo de cast 'reinterpret_cast' realiza conversiones que simplemente 
    reinterpretan los bits de un tipo como de otro tipo.
    No realiza ninguna verificación sobre la validez de la conversión. 
    Es útil para conversiones de bajo nivel, pero debe usarse con extrema precaución.
    Suele usarse para conversion de  tipo de puntero a cualquier otro tipo de puntero, 
    o tipos de datos primitivos(siempre que pueda contenerlos)
    y punteros a estructuras o clases. 
    Es un casteo que carece de seguridad de tipo y no se debe usar a menos que sea
    absolutamente necesario.
*/

int main()
{
    Data* data = new Data;
    data->value = 42;

    // Serializar
    uintptr_t rawData = Serializer::serialize(data);

    // Deserializar
    Data* retData = Serializer::deserialize(rawData);

    // Imprimir resultados
    std::cout << "Data address: " << data << std::endl;
    std::cout << "Data value: " << data->value << std::endl;
    std::cout << "Raw address: " << rawData << std::endl;
    std::cout << "Data deserialized address: " << retData << std::endl;
    std::cout << "Data deserialized value: " << retData->value << std::endl;

    // Liberar memoria
    delete data;
    return 0;
}