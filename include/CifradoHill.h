#ifndef CIFRADO_HILL_H
#define CIFRADO_HILL_H

#include <string>
#include <vector>

class CifradoHill {
public:
    static std::string cifrar(const std::string &mensaje, const std::string &clave, int n);
    static std::string descifrar(const std::string &mensaje, const std::string &clave, int n);
private:
    static std::vector<std::vector<int>> crearMatrizClave(const std::string &clave, int n);
    static int modularInversa(int a, int m);
    static std::vector<std::vector<int>> invertirMatriz(const std::vector<std::vector<int>>& matriz, int n);
    static int calcularDeterminante(const std::vector<std::vector<int>>& matriz, int n);
    static void calcularAdjunto(const std::vector<std::vector<int>>& matriz, std::vector<std::vector<int>>& adjunto, int n);
};

#endif // CIFRADO_HILL_H