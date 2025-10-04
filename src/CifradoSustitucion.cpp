#include "CifradoSustitucion.h"
#include <iostream>
#include <unordered_map>

std::string CifradoSustitucion::cifrar(const std::string &mensaje, const std::string &clave) {
    std::string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Alfabeto en mayúsculas
    std::string mensajeCifrado = mensaje;
    
    // Crear un mapa de sustitución de letras
    std::unordered_map<char, char> mapaSustitucion;
    for (int i = 0; i < 26; ++i) {
        mapaSustitucion[alfabeto[i]] = clave[i];
    }

    // Realizar la sustitución
    for (char &c : mensajeCifrado) {
        if (std::isalpha(c)) {
            char limite = std::islower(c) ? 'a' : 'A';
            c = mapaSustitucion[std::toupper(c)] + (std::islower(c) ? 32 : 0); // Mantener el caso
        }
    }
    
    return mensajeCifrado;
}

std::string CifradoSustitucion::descifrar(const std::string &mensaje, const std::string &clave) {
    std::string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Alfabeto en mayúsculas
    std::string mensajeDescifrado = mensaje;

    // Crear un mapa de sustitución inversa
    std::unordered_map<char, char> mapaSustitucionInversa;
    for (int i = 0; i < 26; ++i) {
        mapaSustitucionInversa[clave[i]] = alfabeto[i];
    }

    // Realizar la sustitución inversa
    for (char &c : mensajeDescifrado) {
        if (std::isalpha(c)) {
            char limite = std::islower(c) ? 'a' : 'A';
            c = mapaSustitucionInversa[std::toupper(c)] + (std::islower(c) ? 32 : 0); // Mantener el caso
        }
    }
    
    return mensajeDescifrado;
}
