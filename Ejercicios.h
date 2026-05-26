#pragma once

#include "Definiciones.h"
#include "PilaInt.h"
#include "ColaInt.h"
#include "ListaPosInt.h"
#include "TablaIntString.h"
#include "MultisetInt.h"
#include "GrafoInt.h"

// Ver Ejercicios.txt para la documentaci—n de estas funciones

bool EstaContenida(PilaInt p1, PilaInt p2);
void EliminarMaximos(ColaInt& c);
ListaPosInt ObtenerRepetidos(MultisetInt m);
void RestringirDominio(TablaIntString& t, MultisetInt permitidos);
ColaInt RecorridaDFS(GrafoInt grafo, int origen);


