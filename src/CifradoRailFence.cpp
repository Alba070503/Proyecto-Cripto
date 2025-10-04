#include "CifradoRailFence.h"
#include <vector>
#include <string>
#include <iostream>

std::string CifradoRailFence::cifrar(const std::string &mensaje, int numFilas) {
    if (numFilas == 1) return mensaje;  // Si hay una sola fila, no se cambia el mensaje

    std::vector<std::string> rail(numFilas);
    int fila = 0;
    bool abajo = true;

    // Rellenar las "rails" de acuerdo al zigzag
    for (int i = 0; i < mensaje.size(); ++i) {
        rail[fila] += mensaje[i];
        if (abajo) {
            if (fila < numFilas - 1) {
                fila++;
            } else {
                abajo = false;
                fila--;
            }
        } else {
            if (fila > 0) {
                fila--;
            } else {
                abajo = true;
                fila++;
            }
        }
    }

    // Leer las filas para formar el mensaje cifrado
    std::string mensajeCifrado;
    for (const auto &r : rail) {
        mensajeCifrado += r;
    }

    return mensajeCifrado;
}

std::string CifradoRailFence::descifrar(const std::string &mensaje, int numFilas) {
    if (numFilas == 1) return mensaje;  // Si hay una sola fila, no se cambia el mensaje

    std::vector<std::string> rail(numFilas);
    int *railLengths = new int[numFilas]();
    int fila = 0;
    bool abajo = true;

    // Calcular la longitud de cada "rail"
    for (int i = 0; i < mensaje.size(); ++i) {
        railLengths[fila]++;
        if (abajo) {
            if (fila < numFilas - 1) {
                fila++;
            } else {
                abajo = false;
                fila--;
            }
        } else {
            if (fila > 0) {
                fila--;
            } else {
                abajo = true;
                fila++;
            }
        }
    }

    // Distribuir las letras en las "rails"
    int k = 0;
    for (int i = 0; i < numFilas; ++i) {
        rail[i] = mensaje.substr(k, railLengths[i]);
        k += railLengths[i];
    }

    // Leer los rails para reconstruir el mensaje
    std::string mensajeDescifrado;
    fila = 0;
    abajo = true;
    int *railIndices = new int[numFilas]();

    for (int i = 0; i < mensaje.size(); ++i) {
        mensajeDescifrado += rail[fila][railIndices[fila]++];
        if (abajo) {
            if (fila < numFilas - 1) {
                fila++;
            } else {
                abajo = false;
                fila--;
            }
        } else {
            if (fila > 0) {
                fila--;
            } else {
                abajo = true;
                fila++;
            }
        }
    }

    delete[] railLengths;
    delete[] railIndices;

    return mensajeDescifrado;
}
