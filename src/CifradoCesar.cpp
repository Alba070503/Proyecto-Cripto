#include "CifradoCesar.h"
#include <cctype>

std::string CifradoCesar::cifrar(const std::string &mensaje, int desplazamiento) {
    std::string mensajeCifrado = mensaje;

    for (char &c : mensajeCifrado) {
        if (std::isalpha(c)) {
            char limite = std::isupper(c) ? 'A' : 'a';
            c = (c - limite + desplazamiento) % 26 + limite;
        }
    }

    return mensajeCifrado;
}

std::string CifradoCesar::descifrar(const std::string& mensajeCifrado, int desplazamiento) {
    return cifrar(mensajeCifrado, 26 - (desplazamiento % 26));
}
