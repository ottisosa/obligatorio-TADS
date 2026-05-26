#include "PilaInt.h"

#ifdef PILA_INT_IMP

//Si necestita otra estructura se puede definir aqui


struct NodoLista {

	int dato;

	NodoLista* sig;

};


struct _representacionPilaInt {

	NodoLista* inicio;

	int largo;

};


PilaInt crearPilaInt(){

	PilaInt p = new _representacionPilaInt;
	p->inicio = NULL;
	p->largo = 0;

	return p;
}

void push(PilaInt& p, int e) {



		NodoLista* aux = new NodoLista;
		aux->dato = e;
		aux->sig = p->inicio;
		p->inicio = aux;
	
		p->largo++;


}

int top(PilaInt p) {

	return p->inicio->dato;
}

void pop(PilaInt& p) {


	NodoLista* aux = p->inicio;
	p->inicio = p->inicio->sig;
	delete aux;

	p->largo--;
}

unsigned int cantidadElementos(PilaInt p) {

	return p->largo;
}

bool esVacia(PilaInt p) {

	return (p == NULL ||p->inicio == NULL);
}

PilaInt clon(PilaInt p) {

	PilaInt aux = crearPilaInt();
	PilaInt ret = crearPilaInt();
	NodoLista* pos = p->inicio;

	while (pos != NULL)
	{
		push(aux, pos->dato);

		pos = pos->sig;
	}


	while (!esVacia(aux))
	{

		push(ret, top(aux));
		pop(aux);
	}

	destruir(aux);

	return ret;
}

void destruir(PilaInt& p) {


	if (p == NULL)
	{
		return;
	}else{

	
		while (p->inicio != NULL)
		{

			NodoLista* aux = p->inicio;

			p->inicio = p->inicio->sig;

			delete aux;
	
		}

		delete p;
		p = NULL;

	}
}


#endif