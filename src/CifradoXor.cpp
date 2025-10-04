#include "CifradoXor.h"

std::string CifradoXor::cifrar(const std::string &mensaje, const std::string &clave) {
    std::string mensajeCifrado = mensaje;
    for (int i = 0; i < mensaje.size(); ++i) {
        mensajeCifrado[i] = mensaje[i] ^ clave[i % clave.size()]; // XOR entre mensaje y clave
    }
    return mensajeCifrado;
}

std::string CifradoXor::descifrar(const std::string &mensaje, const std::string &clave) {
    // El cifrado y el descifrado son el mismo proceso en XOR
    return cifrar(mensaje, clave);
}
