#ifndef CIFRADO_TRANSPOSICION_H
#define CIFRADO_TRANSPOSICION_H

#include <string>

class CifradoTransposicion {
public:
    static std::string cifrar(const std::string &mensaje, int numColumnas);
    static std::string descifrar(const std::string &mensaje, int numColumnas);
};

#endif // CIFRADO_TRANSPOSICION_H
