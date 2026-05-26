#pragma once

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "PruebasAuxEntrega.h"

#include "PruebasPilaInt.h"
#include "PruebasColaInt.h"
#include "PruebasListaPosInt.h"
#include "PruebasTablaIntString.h"
#include "PruebasMultisetInt.h"
#include "PruebasGrafoInt.h"

class PruebasPropias : public Prueba  
{

public:
	PruebasPropias(ConductorPrueba* conductor);
	virtual ~PruebasPropias();
	virtual void correrPruebaConcreta();

protected:
	ManejadorImpresionPrueba mImpresion;
	virtual const char* getNombre() const;

private:
	
};

