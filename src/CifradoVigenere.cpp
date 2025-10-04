#include "CifradoVigenere.h"
#include <cctype>

std::string CifradoVigenere::cifrar(const std::string &mensaje, const std::string &clave) {
    std::string mensajeCifrado = mensaje;
    int j = 0;
    for (int i = 0; i < mensaje.size(); i++) {
        if (std::isalpha(mensaje[i])) {
            char limite = std::islower(mensaje[i]) ? 'a' : 'A';
            mensajeCifrado[i] = (mensaje[i] - limite + (clave[j % clave.size()] - limite)) % 26 + limite;
            j++;
        }
    }
    return mensajeCifrado;
}

std::string CifradoVigenere::descifrar(const std::string &mensaje, const std::string &clave) {
    std::string mensajeDescifrado = mensaje;
    int j = 0;
    for (int i = 0; i < mensaje.size(); i++) {
        if (std::isalpha(mensaje[i])) {
            char limite = std::islower(mensaje[i]) ? 'a' : 'A';
            mensajeDescifrado[i] = (mensaje[i] - limite - (clave[j % clave.size()] - limite) + 26) % 26 + limite;
            j++;
        }
    }
    return mensajeDescifrado;
}
