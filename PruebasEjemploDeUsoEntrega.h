#pragma once

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "PruebasAuxEntrega.h"
#include "PruebasAuxDefensa.h"

#include "PruebasPilaInt.h"
#include "PruebasColaInt.h"
#include "PruebasListaPosInt.h"
#include "PruebasTablaIntString.h"
#include "PruebasMultisetInt.h"
#include "PruebasGrafoInt.h"

class PruebasEjemploDeUsoEntrega : public Prueba  
{

public:
	PruebasEjemploDeUsoEntrega(ConductorPrueba* conductor);
	virtual ~PruebasEjemploDeUsoEntrega();
	virtual void correrPruebaConcreta();

protected:
	virtual const char* getNombre() const;

private:
	ManejadorImpresionPrueba mImpresion;

	void PruebasEjerciciosTAD();

};
