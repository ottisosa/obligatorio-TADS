#include "ColaInt.h"

#ifdef COLA_INT_IMP

//Si necestita otra estructura se puede definir aqui
struct NodoLista {

	int dato;
	NodoLista* sig;

};

struct _representacionColaInt {

	NodoLista * inicio;
	NodoLista * fin;
	int largo;

};

ColaInt crearColaInt() {

	ColaInt c = new _representacionColaInt;
	c->inicio = NULL;
	c->fin = NULL;
	c->largo = 0;

	return c;

}

void encolar(ColaInt& c, int e) {

	if (c->inicio == NULL)
	{
		c->inicio = new NodoLista;
		c->inicio->dato = e;
		c->inicio->sig = NULL;
		c->fin = c->inicio;
		c->largo++;
	}
	else {
	

		c->inicio->sig = new NodoLista;
		c->fin = c->inicio->sig;
		c->inicio->dato = e;
		c->inicio->sig = NULL;

		c->largo++;
	


	}

}

int principio(ColaInt c) {
	
	return c->inicio->dato;
}

void desencolar(ColaInt& c) {
	// NO IMPLEMENTADO
}

bool esVacia(ColaInt c) {
	// NO IMPLEMENTADO
	return true;
}

unsigned int cantidadElementos(ColaInt c) {
	// NO IMPLEMENTADO
	return 0;
}

ColaInt clon(ColaInt c) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(ColaInt& c) {
	// NO IMPLEMENTADO
}

#endif
