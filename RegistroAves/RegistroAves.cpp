#include <iostream>
#include "Bitacora.h"
#include "AnalisisAves.h"

using namespace EIF201;

int main() {

    NodoAve* lista = nullptr;

    Bitacora bitacora("datos/anillamientos.txt");

    bitacora.registrarAve("TS-0427", "Garza Tigre", 850.5, 'H', "2026-05-20");
    bitacora.registrarAve("TS-0428", "Ibis Blanco", 600.2, 'M', "2026-05-20");

    int cargadas = bitacora.cargarValidas(lista);

    std::cout << "Aves validas cargadas: " << cargadas << std::endl;
    std::cout << "Lineas descartadas: " << bitacora.getDescartadas() << std::endl;

    AnalisisAves analisis;

    std::cout << "\n--- Lista cronologica ---" << std::endl;
    analisis.imprimirCronologico(lista);

    std::cout << "\nTotal de aves: " << analisis.contar(lista) << std::endl;
    std::cout << "Peso acumulado: " << analisis.sumaPesos(lista) << " gramos" << std::endl;

    std::cout << "Garzas Tigre registradas: "
        << analisis.contarEspecie(lista, "Garza Tigre") << std::endl;

    if (analisis.existeEspecie(lista, "Garza Tigre")) {
        std::cout << "Si existe la especie Garza Tigre." << std::endl;
    }
    else {
        std::cout << "No existe la especie Garza Tigre." << std::endl;
    }

    NodoAve* pesada = analisis.aveMasPesada(lista);

    if (pesada != nullptr) {
        std::cout << "\nAve mas pesada: "
            << pesada->anillo << " | "
            << pesada->especie << " | "
            << pesada->peso << "g" << std::endl;
    }

    std::cout << "\n--- Lista inversa ---" << std::endl;
    analisis.imprimirInverso(lista);

    Bitacora::liberarLista(lista);

    return 0;
}