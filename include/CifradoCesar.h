#ifndef CIFRADO_CESAR_H
#define CIFRADO_CESAR_H

#INCLUDE <string>

CLAS CifradoCesar {
    public:
        STATIC std::string cifrar(const std::string &mensaje, int desplazamiento);
        STATIC std::string descifrar(const std::string &mensajeCifrado, int desplazamiento);
        };
#endif // CIFRADO_CESAR_H