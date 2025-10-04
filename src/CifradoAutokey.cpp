#include "CifradoAutokey.h"
#include <cctype>

std::string CifradoAutokey::cifrar(const std::string &mensaje, const std::string &clave) {
    std::string mensajeCifrado = mensaje;
    std::string claveGenerada = clave + mensaje; // La clave se concatena con el mensaje
    int k = 0; // Índice para la clave generada

    for (int i = 0; i < mensaje.size(); i++) {
        if (std::isalpha(mensaje[i])) {
            char limite = std::islower(mensaje[i]) ? 'a' : 'A';
            mensajeCifrado[i] = (mensaje[i] - limite + (std::toupper(claveGenerada[k]) - 'A')) % 26 + limite;
            k++;  // Avanzar en la clave generada
        }
    }

    return mensajeCifrado;
}

std::string CifradoAutokey::descifrar(const std::string &mensaje, const std::string &clave) {
    std::string mensajeDescifrado = mensaje;
    std::string claveGenerada = clave; // La clave es igual a la clave inicial
    int k = 0; // Índice para la clave generada

    for (int i = 0; i < mensaje.size(); i++) {
        if (std::isalpha(mensaje[i])) {
            char limite = std::islower(mensaje[i]) ? 'a' : 'A';
            mensajeDescifrado[i] = (mensaje[i] - limite - (std::toupper(claveGenerada[k]) - 'A') + 26) % 26 + limite;
            claveGenerada += mensajeDescifrado[i];  // Agregar al final de la clave generada
            k++;  // Avanzar en la clave generada
        }
    }

    return mensajeDescifrado;
}