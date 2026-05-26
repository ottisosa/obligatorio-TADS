#pragma once

#include "FuncAux.h"
#include "FuncAuxTAD.h"
#include "Ejercicios.h"


void pruebaEstaContenida(const char* pila1, const char* pila2);
void pruebaEliminarMaximos(const char* cola);
void pruebaObtenerRepetidos(const char* multiset);
void pruebaRestringirDominio(const char* keys, const char* values, const char* permitidos);
void pruebaEsConexoBFS(const char* origenes, const char* destinos, const char* pesos, int nroVertices, int dirigido);
void pruebaRecorridaDFS(const char* origenes, const char* destinos, const char* pesos, int nroVertices, int dirigido, int origen);
