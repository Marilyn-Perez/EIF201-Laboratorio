#include "AnalisisAves.h"
#include <iostream>

namespace EIF201 {

	void AnalisisAves::imprimirInversoAux(NodoAve* cab) const
	{
		if (cab == nullptr) {
			return;
		}
	}

	NodoAve* AnalisisAves::maxAux(NodoAve* cab, NodoAve* mejor) const
	{
		if (cab == nullptr) {
			return mejor;
		}
		return maxAux(cab->siguiente, mejor);
	}

	int AnalisisAves::contar(NodoAve* cab) const
	{
		if (cab == nullptr) {
			return 0;
		}
		return 1 + contar(cab->siguiente);
	}

	double AnalisisAves::sumaPesos(NodoAve* cab) const
	{
		if (cab == nullptr) {
			return 0.0;
		}
		return cab->peso + sumaPesos(cab->siguiente);
	}

	int AnalisisAves::contarEspecie(NodoAve* cab, const std::string& especie) const
	{
		if (cab == nullptr) {
			return 0;
		}
		if (cab->especie == especie) {
			return 1 + contarEspecie(cab->siguiente, especie);
		}

		return contarEspecie(cab->siguiente, especie);
	}

	bool AnalisisAves::existeEspecie(NodoAve* cab, const std::string& especie) const
	{
		if (cab == nullptr) {
			return false;
		}

		if (cab->especie == especie) {
			return true;
		}

		return existeEspecie(cab->siguiente, especie);
	}

	NodoAve* AnalisisAves::aveMasPesada(NodoAve* cab) const
	{
		if (cab == nullptr) {
			return nullptr;
		}

		return maxAux(cab, cab);
	}

	void AnalisisAves::imprimirCronologico(NodoAve* cab) const
	{
		if (cab == nullptr) {
			return;
		}

		std::cout << cab->anillo << " | "
			<< cab->especie << " | "
			<< cab->peso << " | "
			<< cab->sexo << " | "
			<< cab->fecha << std::endl;

		imprimirCronologico(cab->siguiente);

	}

	void AnalisisAves::imprimirInverso(NodoAve* cab) const
	{
		imprimirInversoAux(cab);
	}



}

