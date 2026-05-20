#include "Bitacora.h"
#include <fstream>
#include <sstream>
#include <iostream>

namespace EIF201 {

    Bitacora::Bitacora(const std::string& ruta)
        : ruta_(ruta), validas_(0), descartadas_(0) {
    }

    bool Bitacora::registrarAve(const std::string& anillo,
        const std::string& especie,
        double peso,
        char sexo,
        const std::string& fecha) {
        std::ofstream archivo(ruta_, std::ios::app);

        if (!archivo.is_open()) {
            return false;
        }

        archivo << anillo << ";"
            << especie << ";"
            << peso << ";"
            << sexo << ";"
            << fecha << "\n";

        archivo.close();
        return true;
    }

    int Bitacora::cargarTodas(NodoAve*& cabeza) {
        cabeza = nullptr;

        std::ifstream archivo(ruta_);

        if (!archivo.is_open()) {
            return 0;
        }

        std::string linea;
        int cantidad = 0;
        NodoAve* ultimo = nullptr;

        while (std::getline(archivo, linea)) {
            std::stringstream ss(linea);

            std::string anillo;
            std::string especie;
            std::string pesoTexto;
            std::string sexoTexto;
            std::string fecha;

            std::getline(ss, anillo, ';');
            std::getline(ss, especie, ';');
            std::getline(ss, pesoTexto, ';');
            std::getline(ss, sexoTexto, ';');
            std::getline(ss, fecha, ';');

            double peso = std::stod(pesoTexto);
            char sexo = sexoTexto[0];

            NodoAve* nuevo = new NodoAve(anillo, especie, peso, sexo, fecha);

            if (cabeza == nullptr) {
                cabeza = nuevo;
            }
            else {
                ultimo->siguiente = nuevo;
            }

            ultimo = nuevo;
            cantidad++;
        }

        archivo.close();
        return cantidad;
    }

    int Bitacora::cargarValidas(NodoAve*& cabeza) {
        cabeza = nullptr;
        validas_ = 0;
        descartadas_ = 0;

        std::ifstream archivo(ruta_);

        if (!archivo.is_open()) {
            return 0;
        }

        std::string linea;
        NodoAve* ultimo = nullptr;

        while (std::getline(archivo, linea)) {
            if (linea.empty()) {
                descartadas_++;
                continue;
            }

            std::stringstream ss(linea);

            std::string anillo;
            std::string especie;
            std::string pesoTexto;
            std::string sexoTexto;
            std::string fecha;

            bool camposCorrectos =
                static_cast<bool>(std::getline(ss, anillo, ';')) &&
                static_cast<bool>(std::getline(ss, especie, ';')) &&
                static_cast<bool>(std::getline(ss, pesoTexto, ';')) &&
                static_cast<bool>(std::getline(ss, sexoTexto, ';')) &&
                static_cast<bool>(std::getline(ss, fecha, ';'));

            if (!camposCorrectos || anillo.empty() || especie.empty() || sexoTexto.empty() || fecha.empty()) {
                descartadas_++;
                continue;
            }

            double peso;

            try {
                peso = std::stod(pesoTexto);
            }
            catch (...) {
                descartadas_++;
                continue;
            }

            char sexo = sexoTexto[0];

            if (peso <= 0 || !(sexo == 'M' || sexo == 'H' || sexo == 'X')) {
                descartadas_++;
                continue;
            }

            NodoAve* nuevo = new NodoAve(anillo, especie, peso, sexo, fecha);

            if (cabeza == nullptr) {
                cabeza = nuevo;
            }
            else {
                ultimo->siguiente = nuevo;
            }

            ultimo = nuevo;
            validas_++;
        }

        archivo.close();
        return validas_;
    }

    int Bitacora::getValidas() const {
        return validas_;
    }

    int Bitacora::getDescartadas() const {
        return descartadas_;
    }

    void Bitacora::liberarLista(NodoAve*& cabeza) {
        while (cabeza != nullptr) {
            NodoAve* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }

        cabeza = nullptr;
    }

}