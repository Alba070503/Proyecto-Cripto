#ifndef CIFRADO_AUTOKEY_H
#define CIFRADO_AUTOKEY_H

#include <string>

class CifradoAutokey {
public:
    static std::string cifrar(const std::string &mensaje, const std::string &clave);
    static std::string descifrar(const std::string &mensaje, const std::string &clave);
};

#endif // CIFRADO_AUTOKEY_H