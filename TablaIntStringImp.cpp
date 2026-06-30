#include "TablaIntString.h"

#ifdef TABLA_INT_STRING_IMP

//Si necestita otra estructura se puede definir aqui


struct Nodo {

	int clave;
	char* valor;
	Nodo* sig;

};

struct _representacionTablaIntString {

	Nodo** hash;
	int cota;
	int cantElem;
};


//PRE: la cota debe ser mayor a 0
//POS: retorna una poscicion entre 0 y cota -1 donde se buscan o se insertan elementos claves de k

int h(int k, int cota){

	return abs(k) % cota;
}

TablaIntString crearTablaIntString(unsigned int esperados) {


	TablaIntString nuevo = new _representacionTablaIntString;
	nuevo->cota = esperados;
	nuevo->cantElem = 0;
	nuevo->hash = new Nodo*[nuevo->cota];
	
	for (int i = 0; i < nuevo->cota; i++)
	{
		nuevo->hash[i] = NULL;
	}

	return nuevo;
}

//PRE: -
//POS: retorna el largo de un string

int largoPalabra(const char * r) {

	int largo = 0;
	while (r[largo] != '\0')
	{
		largo++;
	}

	return largo;
}

//PRE: -
//POS: copia la palabra de el origen al destino

void copiarPalabra(const char* origen,  char* destino) {

	int i = 0;

	while (origen[i] != '\0')
	{
		destino[i] = origen[i];
		i++;
	}
	destino[i] = '\0';
}

void agregar(TablaIntString& t, int d, const char* r) {

	    int indice = h(d,t->cota);

		Nodo* actual = t->hash[indice];
		bool esta = false;

	
		while (actual != NULL && !esta)
		{

			if (actual->clave == d)
			{

				delete[] actual->valor;

				int largo = largoPalabra(r);
				actual->valor = new char[largo +1];
				copiarPalabra(r, actual->valor);
				esta = true;
			}
			actual = actual->sig;

		}
		if (!esta)
		{
			Nodo* nuevo = new Nodo;
			nuevo->clave = d;


			int largo = largoPalabra(r);
			nuevo->valor = new char[largo + 1];
			copiarPalabra(r, nuevo->valor);

			nuevo->sig = t->hash[indice];
			t->hash[indice] = nuevo;
			t->cantElem++;
		}



}

bool estaDefinida(TablaIntString t, int d) {

	if (t!= NULL)
	{

	
		int indice = h(d, t->cota);
		Nodo* actual = t->hash[indice];
		while (actual != NULL) // O(1) promedio por la funcion de dispersion
		{
			if (actual->clave == d)
			{
				return true;

			}

			actual = actual->sig;
		}

	}
	return false;
}

const char* recuperar(TablaIntString t, int d) {

	int indice = h(d, t->cota);
	Nodo* nodo = t->hash[indice];

	while (nodo != NULL) // O(1) promedio por la funcion de dispersion
	{
		if (nodo->clave  == d)
		{
			return nodo->valor;
		}
		nodo = nodo->sig;
	}
	return NULL;
}

void borrar(TablaIntString& t, int d) {
	
	if (t != NULL)
	{

	
		int indice = h(d, t->cota);
		Nodo* nodo = t->hash[indice];
		Nodo* ant = NULL;
		while (nodo != NULL && nodo->clave != d)
		{
			  ant = nodo;
			  nodo = nodo->sig;
		}

		if (nodo != NULL)
		{
			if (ant == NULL)
			{
				t->hash[indice] = nodo->sig;

			}
			else {

				ant->sig = nodo->sig;
			}

		
		

			delete[] nodo->valor;

			delete nodo;

			t->cantElem--;

		}
	}
}

int elemento(TablaIntString t) {


	for (int i = 0; i < t->cota; i++)
	{
		if (t->hash[i] != NULL)
		{
			return t->hash[i]->clave;
		}

	}
}

bool esVacia(TablaIntString t) {

	if (t == NULL || t->hash == NULL)
	{
		return true;
	}
	return t->cantElem == 0;
}

unsigned int cantidadElementos(TablaIntString t) {
	
	if (t == NULL)
	{
		return 0;
	}
	return t->cantElem;
}

void destruir(TablaIntString& t) {

	if (t != NULL)
	{

		for (int i = 0; i < t->cota; i++)
		{
			Nodo* nodo = t->hash[i];

			while (nodo != NULL)
			{
				Nodo* aux = nodo;
				nodo = nodo->sig;

				delete [] aux->valor;
				delete aux;
			}

		}

		delete[] t->hash;
		delete t;

		t = NULL;

	}
}

TablaIntString clon(TablaIntString t) {

	TablaIntString ret = crearTablaIntString(t->cota);

	if (t->hash != NULL)
	{

	
		for (int i = 0; i < t->cota; i++)
		{
          
			Nodo* aux = t->hash[i];

			while (aux != NULL)
			{
				agregar(ret, aux->clave, aux->valor);
				aux = aux->sig;
			}

		}
		
	}
	return ret;

}

#endif