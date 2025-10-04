#include "CifradoAtbash.h"
#include <cctype>

std::string CifradoAtbash::cifrar(const std::string &mensaje) {
    std::string mensajeCifrado = mensaje;
    
    // Aplicamos la sustitución inversa
    for (char &c : mensajeCifrado) {
        if (std::isalpha(c)) {
            char limite = std::islower(c) ? 'a' : 'A';
            c = limite + ('Z' - std::toupper(c));  // Invertir el alfabeto
        }
    }

    return mensajeCifrado;
}

std::string CifradoAtbash::descifrar(const std::string &mensaje) {
    // El cifrado y descifrado son iguales en Atbash
    return cifrar(mensaje);
}
