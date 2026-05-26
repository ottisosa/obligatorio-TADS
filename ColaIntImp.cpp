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
		c->inicio = c->inicio->sig;
		c->inicio->dato = e;
		c->inicio->sig = NULL;
		c->largo++;
	


	}

}

int principio(ColaInt c) {
	
	return c->fin->dato;
}

void desencolar(ColaInt& c) {


	
		 NodoLista* aux = c->fin;
		 c->fin = c->fin->sig;
		 c->largo--;
		 delete aux;


		 if (c->fin == NULL)
		 {
			 c->inicio = NULL;
		 }


	
}

bool esVacia(ColaInt c) {

	if (c->inicio == NULL && c->fin == NULL)
	{
		return true;
	}
	else {
	
		return false;
	}
}

unsigned int cantidadElementos(ColaInt c) {

	return c->largo;
}

ColaInt clon(ColaInt c) {
	// NO IMPLEMENTADO
	return NULL;
}

void destruir(ColaInt& c) {
	// NO IMPLEMENTADO
}

#endif
