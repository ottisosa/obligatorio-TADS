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

	if (c->fin == NULL)
	{
		c->fin = new NodoLista;
		c->fin->dato = e;
		c->fin->sig = NULL;
		c->inicio = c->fin;
		c->largo++;
	}
	else {
	
	
		c->fin->sig = new NodoLista;
		c->fin = c->fin->sig;
		c->fin->dato = e;
		c->fin->sig = NULL;
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

	if (c->inicio == NULL)
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

	//ColaInt ret = crearColaInt();
	//
	//	if (!esVacia(c))
	//	{

	//		ColaInt aux = c;
	//		ColaInt aux2 = crearColaInt();

	//		while (cantidadElementos(aux) != 0)
	//		{
	//			encolar(aux2, principio(aux));

	//			desencolar(aux);
	//		}


	//		while (cantidadElementos(aux2) != 0 )
	//		{
	//			
	//			encolar(ret, principio(aux2));
	//			desencolar(aux2);

	//		}
	//	}

	//	return ret;
}

void destruir(ColaInt& c) {
	// NO IMPLEMENTADO
}

#endif
