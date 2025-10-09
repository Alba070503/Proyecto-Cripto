// main.cpp

#include "CifradoCesar.h"
#include "CifradoVigenere.h"
#include "CifradoTransposicion.h"
#include "CifradoSustitucion.h"
#include "CifradoAtbash.h"
#include "CifradoPlayfair.h"
#include "CifradoRailFence.h"
#include "CifradoHill.h"
#include "CifradoAutokey.h"
#include "CifradoXor.h"
#include "AnalisisFrecuencia.h"
#include <iostream>
#include <string>

void mostrarMenu() {
    std::cout << "========================================\n";
    std::cout << "Seleccione un algoritmo de cifrado:\n";
    std::cout << "1. Cifrado César\n";
    std::cout << "2. Cifrado Vigenère\n";
    std::cout << "3. Cifrado por Transposición de Columnas\n";
    std::cout << "4. Cifrado por Sustitución Simple\n";
    std::cout << "5. Cifrado Atbash\n";
    std::cout << "6. Cifrado Playfair\n";
    std::cout << "7. Cifrado Rail Fence\n";
    std::cout << "8. Cifrado Hill\n";
    std::cout << "9. Cifrado Autokey\n";
    std::cout << "10. Cifrado XOR\n";
    std::cout << "11. Análisis de Frecuencia\n";
    std::cout << "12. Salir\n";
    std::cout << "========================================\n";
}

int main() {
    int opcion;
    std::string mensaje;
    int desplazamiento;
    std::string claveVigenere;
    int numColumnas;
    std::string claveSustitucion;
    std::string clavePlayfair;
    int numFilasRailFence;
    std::string claveHill;
    std::string claveAutokey;
    std::string claveXor;
    int matrizSize;

    while (true) {
        mostrarMenu();
        std::cout << "Opción: ";
        std::cin >> opcion;
        std::cin.ignore();  // Limpiar el buffer de entrada para usar getline después

        if (opcion == 1) {
            // Cifrado César
            std::cout << "Ingrese el mensaje a cifrar: ";
            std::getline(std::cin, mensaje);
            std::cout << "Ingrese el desplazamiento (número entero): ";
            std::cin >> desplazamiento;

            // Cifrado y Descifrado
            std::string mensajeCifrado = CifradoCesar::cifrar(mensaje, desplazamiento);
            std::cout << "Mensaje Cifrado: " << mensajeCifrado << std::endl;

            std::string mensajeDescifrado = CifradoCesar::descifrar(mensajeCifrado, desplazamiento);
            std::cout << "Mensaje Descifrado: " << mensajeDescifrado << std::endl;
        }
        else if (opcion == 2) {
            // Cifrado Vigenère
            std::cout << "Ingrese el mensaje a cifrar: ";
            std::getline(std::cin, mensaje);
            std::cout << "Ingrese la clave para Vigenère: ";
            std::getline(std::cin, claveVigenere);

            // Cifrado y Descifrado
            std::string mensajeCifrado = CifradoVigenere::cifrar(mensaje, claveVigenere);
            std::cout << "Mensaje Cifrado: " << mensajeCifrado << std::endl;

            std::string mensajeDescifrado = CifradoVigenere::descifrar(mensajeCifrado, claveVigenere);
            std::cout << "Mensaje Descifrado: " << mensajeDescifrado << std::endl;
        }
        else if (opcion == 3) {
            // Cifrado por Transposición de Columnas
            std::cout << "Ingrese el mensaje a cifrar: ";
            std::getline(std::cin, mensaje);
            std::cout << "Ingrese el número de columnas: ";
            std::cin >> numColumnas;

            // Cifrado y Descifrado
            std::string mensajeCifrado = CifradoTransposicion::cifrar(mensaje, numColumnas);
            std::cout << "Mensaje Cifrado: " << mensajeCifrado << std::endl;

            std::string mensajeDescifrado = CifradoTransposicion::descifrar(mensajeCifrado, numColumnas);
            std::cout << "Mensaje Descifrado: " << mensajeDescifrado << std::endl;
        }
        else if (opcion == 4) {
            // Cifrado por Sustitución Simple
            std::cout << "Ingrese el mensaje a cifrar: ";
            std::getline(std::cin, mensaje);
            std::cout << "Ingrese la clave de sustitución (alfabeto permutado): ";
            std::getline(std::cin, claveSustitucion);

            // Cifrado y Descifrado
            std::string mensajeCifrado = CifradoSustitucion::cifrar(mensaje, claveSustitucion);
            std::cout << "Mensaje Cifrado: " << mensajeCifrado << std::endl;

            std::string mensajeDescifrado = CifradoSustitucion::descifrar(mensajeCifrado, claveSustitucion);
            std::cout << "Mensaje Descifrado: " << mensajeDescifrado << std::endl;
        }
        else if (opcion == 5) {
            // Cifrado Atbash
            std::cout << "Ingrese el mensaje a cifrar: ";
            std::getline(std::cin, mensaje);

            // Cifrado y Descifrado
            std::string mensajeCifrado = CifradoAtbash::cifrar(mensaje);
            std::cout << "Mensaje Cifrado: " << mensajeCifrado << std::endl;

            std::string mensajeDescifrado = CifradoAtbash::descifrar(mensajeCifrado);
            std::cout << "Mensaje Descifrado: " << mensajeDescifrado << std::endl;
        }
        else if (opcion == 6) {
            // Cifrado Playfair
            std::cout << "Ingrese el mensaje a cifrar: ";
            std::getline(std::cin, mensaje);
            std::cout << "Ingrese la clave para Playfair: ";
            std::getline(std::cin, clavePlayfair);

            // Cifrado y Descifrado
            std::string mensajeCifrado = CifradoPlayfair::cifrar(mensaje, clavePlayfair);
            std::cout << "Mensaje Cifrado: " << mensajeCifrado << std::endl;

            std::string mensajeDescifrado = CifradoPlayfair::descifrar(mensajeCifrado, clavePlayfair);
            std::cout << "Mensaje Descifrado: " << mensajeDescifrado << std::endl;
        }
        else if (opcion == 7) {
            // Cifrado Rail Fence
            std::cout << "Ingrese el mensaje a cifrar: ";
            std::getline(std::cin, mensaje);
            std::cout << "Ingrese el número de filas: ";
            std::cin >> numFilasRailFence;

            // Cifrado y Descifrado
            std::string mensajeCifrado = CifradoRailFence::cifrar(mensaje, numFilasRailFence);
            std::cout << "Mensaje Cifrado: " << mensajeCifrado << std::endl;

            std::string mensajeDescifrado = CifradoRailFence::descifrar(mensajeCifrado, numFilasRailFence);
            std::cout << "Mensaje Descifrado: " << mensajeDescifrado << std::endl;
        }
        else if (opcion == 8) {
            // Cifrado Hill
            std::cout << "Ingrese el mensaje a cifrar: ";
            std::getline(std::cin, mensaje);
            std::cout << "Ingrese la clave para Hill (clave de tamaño n): ";
            std::getline(std::cin, claveHill);
            std::cout << "Ingrese el tamaño de la matriz (2 o 3): ";
            std::cin >> matrizSize;

            // Cifrado y Descifrado
            std::string mensajeCifrado = CifradoHill::cifrar(mensaje, claveHill, matrizSize);
            std::cout << "Mensaje Cifrado: " << mensajeCifrado << std::endl;

            std::string mensajeDescifrado = CifradoHill::descifrar(mensajeCifrado, claveHill, matrizSize);
            std::cout << "Mensaje Descifrado: " << mensajeDescifrado << std::endl;
        }
        else if (opcion == 9) {
            // Cifrado Autokey
            std::cout << "Ingrese el mensaje a cifrar: ";
            std::getline(std::cin, mensaje);
            std::cout << "Ingrese la clave para Autokey: ";
            std::getline(std::cin, claveAutokey);

            // Cifrado y Descifrado
            std::string mensajeCifrado = CifradoAutokey::cifrar(mensaje, claveAutokey);
            std::cout << "Mensaje Cifrado: " << mensajeCifrado << std::endl;

            std::string mensajeDescifrado = CifradoAutokey::descifrar(mensajeCifrado, claveAutokey);
            std::cout << "Mensaje Descifrado: " << mensajeDescifrado << std::endl;
        }
        else if (opcion == 10) {
            // Cifrado XOR
            std::cout << "Ingrese el mensaje a cifrar: ";
            std::getline(std::cin, mensaje);
            std::cout << "Ingrese la clave para XOR: ";
            std::getline(std::cin, claveXor);

            // Cifrado y Descifrado
            std::string mensajeCifrado = CifradoXor::cifrar(mensaje, claveXor);
            std::cout << "Mensaje Cifrado: " << mensajeCifrado << std::endl;

            std::string mensajeDescifrado = CifradoXor::descifrar(mensajeCifrado, claveXor);
            std::cout << "Mensaje Descifrado: " << mensajeDescifrado << std::endl;
        }
        else if (opcion == 11) {
            // Análisis de Frecuencia
            std::cout << "Ingrese el mensaje para analizar la frecuencia: ";
            std::getline(std::cin, mensaje);

            // Realizar el análisis de frecuencia
            AnalisisFrecuencia::analizar(mensaje);
        }
        else if (opcion == 12) {
            std::cout << "Saliendo del programa...\n";
            break;
        }
        else {
            std::cout << "Opción no válida, intente nuevamente.\n";
        }

        std::cout << std::endl;
    }

    return 0;
}
