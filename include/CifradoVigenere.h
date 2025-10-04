#ifndef CIFRADO_VIGENERE_H
#define CIFRADO_VIGENERE_H

#include <string>

class CifradoVigenere {
public:
    static std::string cifrar(const std::string &mensaje, const std::string &clave);
    static std::string descifrar(const std::string &mensaje, const std::string &clave);
};

#endif 


---