#ifndef CIFRADO_XOR_H
#define CIFRADO_XOR_H

#include <string>

class CifradoXor {
public:
    static std::string cifrar(const std::string &mensaje, const std::string &clave);
    static std::string descifrar(const std::string &mensaje, const std::string &clave);
};

#endif // CIFRADO_XOR_H