#include "CifradoHill.h"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <cctype>

using namespace std;

std::vector<std::vector<int>> CifradoHill::crearMatrizClave(const std::string &clave, int n) {
    std::vector<std::vector<int>> matriz(n, std::vector<int>(n));
    int k = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = toupper(clave[k++]) - 'A'; // Convertir char a int (0-25)
        }
    }
    return matriz;
}

int CifradoHill::modularInversa(int a, int m) {
    // Algoritmo de Euclides extendido para encontrar la inversa modular
    int t = 0, newT = 1;
    int r = m, newR = a;
    
    while (newR != 0) {
        int quotient = r / newR;
        t = t - quotient * newT;
        r = r - quotient * newR;
        std::swap(t, newT);
        std::swap(r, newR);
    }

    if (r > 1) return -1;  // No tiene inversa
    if (t < 0) t = t + m;  // Asegurar que el resultado sea positivo

    return t;
}

std::vector<std::vector<int>> CifradoHill::invertirMatriz(const std::vector<std::vector<int>>& matriz, int n) {
    int det = calcularDeterminante(matriz, n);
    int invDet = modularInversa(det, 26);

    if (invDet == -1) {
        throw std::invalid_argument("La matriz no es invertible");
    }

    std::vector<std::vector<int>> adjunto(n, std::vector<int>(n));
    calcularAdjunto(matriz, adjunto, n);

    std::vector<std::vector<int>> inversa(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inversa[i][j] = (adjunto[i][j] * invDet) % 26;
        }
    }

    return inversa;
}

int CifradoHill::calcularDeterminante(const std::vector<std::vector<int>>& matriz, int n) {
    if (n == 1) return matriz[0][0];

    int det = 0;
    std::vector<std::vector<int>> submatriz(n - 1, std::vector<int>(n - 1));

    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) continue;
                submatriz[subi][subj] = matriz[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matriz[0][x] * calcularDeterminante(submatriz, n - 1);
    }

    return det % 26;
}

void CifradoHill::calcularAdjunto(const std::vector<std::vector<int>>& matriz, std::vector<std::vector<int>>& adjunto, int n) {
    if (n == 1) {
        adjunto[0][0] = 1;
        return;
    }

    std::vector<std::vector<int>> submatriz(n - 1, std::vector<int>(n - 1));
    int sign = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int subi = 0;
            for (int x = 0; x < n; ++x) {
                if (x == i) continue;
                int subj = 0;
                for (int y = 0; y < n; ++y) {
                    if (y == j) continue;
                    submatriz[subi][subj] = matriz[x][y];
                    subj++;
                }
                subi++;
            }
            adjunto[j][i] = (sign * calcularDeterminante(submatriz, n - 1)) % 26;
            sign = -sign;
        }
    }
}

std::string CifradoHill::cifrar(const std::string &mensaje, const std::string &clave, int n) {
    std::vector<std::vector<int>> matrizClave = crearMatrizClave(clave, n);
    std::string mensajeCifrado = "";
    std::vector<int> bloque(n);

    for (int i = 0; i < mensaje.size(); i += n) {
        for (int j = 0; j < n; ++j) {
            bloque[j] = toupper(mensaje[i + j]) - 'A'; // Convertir el char a int
        }

        std::vector<int> resultado(n);
        for (int j = 0; j < n; ++j) {
            resultado[j] = 0;
            for (int k = 0; k < n; ++k) {
                resultado[j] = (resultado[j] + matrizClave[j][k] * bloque[k]) % 26;
            }
            mensajeCifrado += (resultado[j] + 'A');
        }
    }

    return mensajeCifrado;
}

std::string CifradoHill::descifrar(const std::string &mensaje, const std::string &clave, int n) {
    std::vector<std::vector<int>> matrizClave = crearMatrizClave(clave, n);
    std::vector<std::vector<int>> matrizInversa = invertirMatriz(matrizClave, n);
    std::string mensajeDescifrado = "";
    std::vector<int> bloque(n);

    for (int i = 0; i < mensaje.size(); i += n) {
        for (int j = 0; j < n; ++j) {
            bloque[j] = toupper(mensaje[i + j]) - 'A'; // Convertir el char a int
        }

        std::vector<int> resultado(n);
        for (int j = 0; j < n; ++j) {
            resultado[j] = 0;
            for (int k = 0; k < n; ++k) {
                resultado[j] = (resultado[j] + matrizInversa[j][k] * bloque[k]) % 26;
            }
            mensajeDescifrado += (resultado[j] + 'A');
        }
    }

    return mensajeDescifrado;
}
