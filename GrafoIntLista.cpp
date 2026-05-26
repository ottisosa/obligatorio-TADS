#include "GrafoInt.h"

#ifdef GRAFO_INT_LISTA

//Si necestita otra estructura se puede definir aqui

struct _representacionGrafoInt {
    // NO IMPLEMENTADO
};

GrafoInt crearGrafo(int numVertices, bool dirigido){
    // NO IMPLEMENTADO
    return NULL;
}

void agregarArista(GrafoInt& grafo, int origen, int destino, int peso){
    // NO IMPLEMENTADO
}

void eliminarArista(GrafoInt& grafo, int origen, int destino){
    // NO IMPLEMENTADO
}

bool tieneArista(GrafoInt grafo, int origen, int destino){
    // NO IMPLEMENTADO
    return false;
}

int pesoArista(GrafoInt grafo, int origen, int destino){
    // NO IMPLEMENTADO
    return 0;
}

int cantidadConexiones(GrafoInt grafo, int vertice){
    // NO IMPLEMENTADO
    return 0;
}

int* vecinos(GrafoInt grafo, int vertice){
    // NO IMPLEMENTADO
    return NULL;
}

bool esDirigido(GrafoInt grafo){
    // NO IMPLEMENTADO
    return false;
}

int cantidadVertices(GrafoInt grafo){
    // NO IMPLEMENTADO
    return 0;
}

int cantidadAristas(GrafoInt grafo){
    // NO IMPLEMENTADO
    return 0;
}

GrafoInt clon(GrafoInt grafo){
    // NO IMPLEMENTADO
    return NULL;
}

void destruir(GrafoInt& grafo){
    // NO IMPLEMENTADO
}

#endif
