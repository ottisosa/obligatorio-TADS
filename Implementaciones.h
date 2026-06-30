#pragma once

// Elegir la implementacion a usar de GrafoInt (solo 1 descomentada a la vez):
//#define GRAFO_INT_LISTA         // Implementación como Listas de Adyacencia
#define GRAFO_INT_MATRIZ      // Implementación como Matríz de Adyacencia

// No modificar de aca en adelante
#if defined(GRAFO_INT_LISTA)
#include "GrafoIntLista.h"
#elif defined(GRAFO_INT_MATRIZ)
#include "GrafoIntMatriz.h"
#endif

#define COLA_INT_IMP
#if defined(COLA_INT_IMP)
#include "ColaIntImp.h"
#endif

#define MULTISET_INT_IMP
#if defined(MULTISET_INT_IMP)
#include "MultisetIntImp.h"
#endif

#define LISTA_POS_INT_IMP
#if defined(LISTA_POS_INT_IMP)
#include "ListaPosIntImp.h"
#endif

#define PILA_INT_IMP
#if defined(PILA_INT_IMP)
#include "PilaIntImp.h"
#endif

#define TABLA_INT_STRING_IMP
#if defined(TABLA_INT_STRING_IMP)
#include "TablaIntStringImp.h"
#endif
