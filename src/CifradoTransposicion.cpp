#include "CifradoTransposicion.h"
#include <vector>
#include <algorithm>

std::string CifradoTransposicion::cifrar(const std::string &mensaje, int numColumnas) {
    int longitud = mensaje.size();
    int filas = (longitud + numColumnas - 1) / numColumnas;
    std::vector<std::vector<char>> tabla(filas, std::vector<char>(numColumnas, ' '));

    int k = 0;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < numColumnas; ++j) {
            if (k < longitud) {
                tabla[i][j] = mensaje[k++];
            }
        }
    }

    std::string mensajeCifrado;
    for (int j = 0; j < numColumnas; ++j) {
        for (int i = 0; i < filas; ++i) {
            if (tabla[i][j] != ' ') {
                mensajeCifrado += tabla[i][j];
            }
        }
    }

    return mensajeCifrado;
}

std::string CifradoTransposicion::descifrar(const std::string &mensaje, int numColumnas) {
    int longitud = mensaje.size();
    int filas = (longitud + numColumnas - 1) / numColumnas;
    std::vector<std::vector<char>> tabla(filas, std::vector<char>(numColumnas, ' '));

    int k = 0;
    for (int j = 0; j < numColumnas; ++j) {
        for (int i = 0; i < filas; ++i) {
            if (k < longitud) {
                tabla[i][j] = mensaje[k++];
            }
        }
    }

    std::string mensajeDescifrado;
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < numColumnas; ++j) {
            if (tabla[i][j] != ' ') {
                mensajeDescifrado += tabla[i][j];
            }
        }
    }

    return mensajeDescifrado;
}
