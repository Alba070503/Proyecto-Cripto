#ifndef CIFRADO_PLAYFAIR_H
#define CIFRADO_PLAYFAIR_H

#include <string>

class CifradoPlayfair {
public:
    static std::string cifrar(const std::string &mensaje, const std::string &clave);
    static std::string descifrar(const std::string &mensaje, const std::string &clave);
};

#endif // CIFRADO_PLAYFAIR_H