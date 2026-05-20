#ifndef EIF201_ANALISIS_AVES_H
#define EIF201_ANALISIS_AVES_H

#include "NodoAve.h"
#include <string>

namespace EIF201 {

    class AnalisisAves {
    private:
        void imprimirInversoAux(NodoAve* cab) const;
        NodoAve* maxAux(NodoAve* cab, NodoAve* mejor) const;

    public:
        AnalisisAves() = default;

        int contar(NodoAve* cab) const;
        double sumaPesos(NodoAve* cab) const;
        int contarEspecie(NodoAve* cab, const std::string& especie) const;
        bool existeEspecie(NodoAve* cab, const std::string& especie) const;
        NodoAve* aveMasPesada(NodoAve* cab) const;
        void imprimirCronologico(NodoAve* cab) const;
        void imprimirInverso(NodoAve* cab) const;
    };

}

#endif
