#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct _representacionListaPosInt {

	unsigned int capacidad;
	unsigned int cantElem;
	int* datos;


};

ListaPosInt crearListaPosInt()
{

	ListaPosInt nuevo = new _representacionListaPosInt;

	nuevo->cantElem = 0;
	nuevo->capacidad = 10;  // Reservo 10 lugares de inicio
	nuevo->datos = new int[nuevo->capacidad];

	return nuevo;
}

void agregar(ListaPosInt& l, int e, unsigned int pos)
{
	if (l != NULL)
	{
		if (l->cantElem == l->capacidad)
		{

			int capacidadNuevo = l->capacidad * 2;
			int* nuevo = new int[capacidadNuevo];

			for (int i = 0; i < l->capacidad; i ++) {
			
				nuevo[i] = l->datos[i];
			}
		
			delete[] l->datos;

			l->datos = nuevo;
			l->capacidad = capacidadNuevo;
		}


		if (pos >= l->cantElem)
		{
			pos = l->cantElem;
		}


		for (int i = l->cantElem; i > pos ; i--)
		{
			l->datos[i] = l->datos[i - 1];
		}


		l->datos[pos] = e;
		l->cantElem++;


	}
}

void borrar(ListaPosInt& l, unsigned int pos)
{
	if (l!= NULL)
	{

		if (pos < l->cantElem)
		{
			for (unsigned int i = pos; i < l->cantElem - 1; i++)
			{

				l->datos[i] = l->datos[i + 1];

			}


			l->cantElem--;

		}
	}
}

int elemento(ListaPosInt l, unsigned int pos)
{

	// se asume que l no es NULL por las pecondiciones

	return l->datos[pos];
}

bool esVacia(ListaPosInt l)
{

	return (l == NULL) || (l->cantElem == 0);
}

unsigned int cantidadElementos(ListaPosInt l)
{
	if (l != NULL)
	{

		return l->cantElem;
	}
	else
	{
		return 0;
	}

}

ListaPosInt clon(ListaPosInt l)
{
	if (l != NULL)
	{

	
		ListaPosInt ret = new _representacionListaPosInt;
		ret->cantElem = l->cantElem;
		ret->capacidad = l->capacidad;

		ret->datos = new int[ret->capacidad];

		for (int i = 0; i < ret->capacidad; i++)
		{
			ret->datos[i] = l->datos[i];
		}

		return ret;
	}
	else
	{
		return NULL;
	}

}

void destruir(ListaPosInt& l)
{

	if (l != NULL)
	{

		delete[] l->datos;
		delete l;
		l = NULL;
	}
}


#endif