#ifndef CIFRADO_RAILFENCE_H
#define CIFRADO_RAILFENCE_H

#include <string>

class CifradoRailFence {
public:
    static std::string cifrar(const std::string &mensaje, int numFilas);
    static std::string descifrar(const std::string &mensaje, int numFilas);
};

#endif // CIFRADO_RAILFENCE_H