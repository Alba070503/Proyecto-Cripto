#ifndef CIFRADO_SUSTITUCION_H
#define CIFRADO_SUSTITUCION_H

#include <string>

class CifradoSustitucion {
public:
    static std::string cifrar(const std::string &mensaje, const std::string &clave);
    static std::string descifrar(const std::string &mensaje, const std::string &clave);
};

#endif // CIFRADO_SUSTITUCION_H
