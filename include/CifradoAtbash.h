#ifndef CIFRADO_ATBASH_H
#define CIFRADO_ATBASH_H

#include <string>

class CifradoAtbash {
public:
    static std::string cifrar(const std::string &mensaje);
    static std::string descifrar(const std::string &mensaje);
};

#endif // CIFRADO_ATBASH_H
