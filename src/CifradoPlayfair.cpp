#include "CifradoPlayfair.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>

// Función auxiliar para crear la matriz Playfair a partir de una clave
std::vector<std::vector<char>> CifradoPlayfair::crearMatriz(const std::string &clave) {
    std::vector<std::vector<char>> matriz(5, std::vector<char>(5));
    std::string alfabeto = "ABCDEFGHIKLMNOPQRSTUVWXYZ";  // Sin la letra J, la cual se reemplaza por I

    std::string claveFiltrada = "";
    for (char c : clave) {
        c = std::toupper(c);
        if (alfabeto.find(c) != std::string::npos && claveFiltrada.find(c) == std::string::npos) {
            claveFiltrada += c;
        }
    }

    for (char c : alfabeto) {
        if (claveFiltrada.find(c) == std::string::npos) {
            claveFiltrada += c;
        }
    }

    int index = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            matriz[i][j] = claveFiltrada[index++];
        }
    }

    return matriz;
}

// Función para cifrar el mensaje usando la matriz Playfair
std::string CifradoPlayfair::cifrar(const std::string &mensaje, const std::string &clave) {
    std::vector<std::vector<char>> matriz = crearMatriz(clave);
    std::string mensajeCifrado = "";
    std::string mensajeModificado = "";

    // Preparar el mensaje (reemplazar J por I y agregar X si hay letras duplicadas en un par)
    for (char c : mensaje) {
        if (std::isalpha(c)) {
            mensajeModificado += std::toupper(c);
        }
    }

    for (int i = 0; i < mensajeModificado.size(); i += 2) {
        if (i + 1 >= mensajeModificado.size()) {
            mensajeModificado += 'X';  // Si el mensaje tiene un número impar de caracteres
        }
    }

    // Cifrar el mensaje en pares
    for (int i = 0; i < mensajeModificado.size(); i += 2) {
        char char1 = mensajeModificado[i];
        char char2 = mensajeModificado[i + 1];
        int row1, col1, row2, col2;

        // Encontrar la posición de char1 y char2 en la matriz
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 5; ++c) {
                if (matriz[r][c] == char1) {
                    row1 = r;
                    col1 = c;
                }
                if (matriz[r][c] == char2) {
                    row2 = r;
                    col2 = c;
                }
            }
        }

        // Reglas de cifrado del Playfair
        if (row1 == row2) {
            // Si están en la misma fila, se reemplazan por los caracteres a su derecha
            mensajeCifrado += matriz[row1][(col1 + 1) % 5];
            mensajeCifrado += matriz[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            // Si están en la misma columna, se reemplazan por los caracteres debajo de ellos
            mensajeCifrado += matriz[(row1 + 1) % 5][col1];
            mensajeCifrado += matriz[(row2 + 1) % 5][col2];
        } else {
            // Si están en filas y columnas diferentes, se forman un rectángulo
            mensajeCifrado += matriz[row1][col2];
            mensajeCifrado += matriz[row2][col1];
        }
    }

    return mensajeCifrado;
}

// Función para descifrar el mensaje usando la matriz Playfair
std::string CifradoPlayfair::descifrar(const std::string &mensaje, const std::string &clave) {
    std::vector<std::vector<char>> matriz = crearMatriz(clave);
    std::string mensajeDescifrado = "";

    for (int i = 0; i < mensaje.size(); i += 2) {
        char char1 = mensaje[i];
        char char2 = mensaje[i + 1];
        int row1, col1, row2, col2;

        // Encontrar la posición de char1 y char2 en la matriz
        for (int r = 0; r < 5; ++r) {
            for (int c = 0; c < 5; ++c) {
                if (matriz[r][c] == char1) {
                    row1 = r;
                    col1 = c;
                }
                if (matriz[r][c] == char2) {
                    row2 = r;
                    col2 = c;
                }
            }
        }

        // Reglas de descifrado del Playfair
        if (row1 == row2) {
            // Si están en la misma fila, se reemplazan por los caracteres a su izquierda
            mensajeDescifrado += matriz[row1][(col1 + 4) % 5];
            mensajeDescifrado += matriz[row2][(col2 + 4) % 5];
        } else if (col1 == col2) {
            // Si están en la misma columna, se reemplazan por los caracteres encima de ellos
            mensajeDescifrado += matriz[(row1 + 4) % 5][col1];
            mensajeDescifrado += matriz[(row2 + 4) % 5][col2];
        } else {
            // Si están en filas y columnas diferentes, se forman un rectángulo
            mensajeDescifrado += matriz[row1][col2];
            mensajeDescifrado += matriz[row2][col1];
        }
    }

    return mensajeDescifrado;
}
