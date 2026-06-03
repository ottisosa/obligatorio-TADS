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


	if (c != NULL)
	{
		NodoLista* nuevo = new NodoLista;
		nuevo->dato = e;
		nuevo->sig = NULL;

		if (c->inicio == NULL)
		{
			c->inicio = nuevo;
		}
		else {
	
			c->fin->sig = nuevo;

		}

		c->fin = nuevo;
		c->largo++;

	}
}

int principio(ColaInt c) {
	
	
	return c->inicio->dato;

}

void desencolar(ColaInt& c) {


	
		 NodoLista* aux = c->inicio;
		 c->inicio = c->inicio->sig;
		 c->largo--;
		 delete aux;


		 if (c->inicio == NULL)
		 {
			 c->fin = NULL;
		 }


	
}

bool esVacia(ColaInt c) {


	if (c != NULL && c->inicio == NULL)
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

	ColaInt ret = crearColaInt();
	
		if (!esVacia(c))
		{

			NodoLista * actual = c->inicio;

			while (actual != NULL)
			{
				encolar(ret, actual->dato);


				actual = actual->sig;
			}


		}

		return ret;

}

void destruir(ColaInt& c) {

	if (c != NULL)
	{
		while (c->inicio != NULL)
		{

			NodoLista* aux = c->inicio;

			c->inicio = c->inicio->sig;

			delete aux;

		}

		delete c;

		c = NULL;
	}
}

#endif
