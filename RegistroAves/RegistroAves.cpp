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