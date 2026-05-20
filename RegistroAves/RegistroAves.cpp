#include <iostream>
#include <string>
#include "Bitacora.h"
#include "AnalisisAves.h"

using namespace EIF201;

int main() {

    NodoAve* lista = nullptr;

    Bitacora bitacora("datos/anillamientos.txt");

    AnalisisAves analisis;

    int opcion = 0;

    do {
        std::cout << "\n===== REFUGIO DE AVES =====\n";
        std::cout << "1. Registrar ave\n";
        std::cout << "2. Cargar/actualizar aves validas\n";
        std::cout << "3. Mostrar aves en orden cronologico\n";
        std::cout << "4. Mostrar aves en orden inverso\n";
        std::cout << "5. Contar aves\n";
        std::cout << "6. Sumar pesos\n";
        std::cout << "7. Contar aves por especie\n";
        std::cout << "8. Buscar especie\n";
        std::cout << "9. Mostrar ave mas pesada\n";
        std::cout << "10. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::string anillo, especie, fecha;
            double peso;
            char sexo;

            std::cin.ignore(1000, '\n');

            std::cout << "Codigo de anillo: ";
            std::getline(std::cin, anillo);

            std::cout << "Especie: ";
            std::getline(std::cin, especie);

            std::cout << "Peso en gramos: ";
            std::cin >> peso;

            std::cout << "Sexo (M/H/X): ";
            std::cin >> sexo;

            std::cin.ignore(1000, '\n');

            std::cout << "Fecha (YYYY-MM-DD): ";
            std::getline(std::cin, fecha);

            if (bitacora.registrarAve(anillo, especie, peso, sexo, fecha)) {
                std::cout << "Ave registrada correctamente.\n";
            }
            else {
                std::cout << "Error al registrar el ave.\n";
            }

        }
        else if (opcion == 2) {
            Bitacora::liberarLista(lista);

            int cargadas = bitacora.cargarValidas(lista);

            std::cout << "Aves validas cargadas: " << cargadas << "\n";
            std::cout << "Lineas descartadas: " << bitacora.getDescartadas() << "\n";

        }
        else if (opcion == 3) {
            std::cout << "\n--- Aves en orden cronologico ---\n";
            analisis.imprimirCronologico(lista);

        }
        else if (opcion == 4) {
            std::cout << "\n--- Aves en orden inverso ---\n";
            analisis.imprimirInverso(lista);

        }
        else if (opcion == 5) {
            std::cout << "Total de aves: " << analisis.contar(lista) << "\n";

        }
        else if (opcion == 6) {
            std::cout << "Peso acumulado: " << analisis.sumaPesos(lista) << " gramos\n";

        }
        else if (opcion == 7) {
            std::string especie;

            std::cin.ignore(1000, '\n');

            std::cout << "Ingrese la especie: ";
            std::getline(std::cin, especie);

            std::cout << "Cantidad de aves de esa especie: "
                << analisis.contarEspecie(lista, especie) << "\n";

        }
        else if (opcion == 8) {
            std::string especie;

            std::cin.ignore(1000, '\n');

            std::cout << "Ingrese la especie a buscar: ";
            std::getline(std::cin, especie);

            if (analisis.existeEspecie(lista, especie)) {
                std::cout << "La especie si existe.\n";
            }
            else {
                std::cout << "La especie no existe.\n";
            }

        }
        else if (opcion == 9) {
            NodoAve* pesada = analisis.aveMasPesada(lista);

            if (pesada != nullptr) {
                std::cout << "Ave mas pesada: "
                    << pesada->anillo << " | "
                    << pesada->especie << " | "
                    << pesada->peso << "g | "
                    << pesada->sexo << " | "
                    << pesada->fecha << "\n";
            }
            else {
                std::cout << "No hay aves cargadas.\n";
            }

        }
        else if (opcion == 10) {
            std::cout << "Saliendo del sistema...\n";

        }
        else {
            std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 10);

    Bitacora::liberarLista(lista);

    return 0;
}