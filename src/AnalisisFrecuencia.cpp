#include "AnalisisFrecuencia.h"
#include <iostream>
#include <map>
#include <string>
#include <cctype>  // Para isalpha

void AnalisisFrecuencia::analizar(const std::string &mensaje) {
    std::map<char, int> frecuencias;

    // Contar la frecuencia de cada letra
    for (char c : mensaje) {
        if (std::isalpha(c)) {
            c = std::toupper(c);  // Convertir el caracter a mayúscula
            frecuencias[c]++;
        }
    }

    // Mostrar el análisis de frecuencia
    std::cout << "Análisis de Frecuencia:\n";
    for (const auto &par : frecuencias) {
        std::cout << par.first << ": " << par.second << " veces\n";
    }
}