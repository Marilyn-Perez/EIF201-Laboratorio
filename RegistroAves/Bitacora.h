#ifndef EIF201_BITACORA_H
#define EIF201_BITACORA_H

#include "NodoAve.h"
#include <string>

namespace EIF201 {

    class Bitacora {
    private:
        std::string ruta_;
        int validas_;
        int descartadas_;

    public:
        Bitacora(const std::string& ruta);

        bool registrarAve(const std::string& anillo,
            const std::string& especie,
            double peso,
            char sexo,
            const std::string& fecha);

        int cargarTodas(NodoAve*& cabeza);
        int cargarValidas(NodoAve*& cabeza);

        int getValidas() const;
        int getDescartadas() const;

        static void liberarLista(NodoAve*& cabeza);
    };

}

#endif