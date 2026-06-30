#include "MultisetInt.h"

#ifdef MULTISET_INT_IMP

//Si necestita otra estructura se puede definir aqui

struct ABB {

	int dato;
	int cant;
	ABB* izq;
	ABB* der;

};

struct _representacionMultisetInt {
	

	int cantElem;
	ABB* raiz;
};

MultisetInt crearMultisetInt() {

	MultisetInt nuevo = new _representacionMultisetInt;
	
	nuevo->cantElem = 0;
	nuevo->raiz = NULL;
	return nuevo;
}

// PRE: El numero de ocurrencias es mayor que 0
//POS : si e no existe crea el nodo, sino incrementa las ocurrencias

void agregarAux(ABB*& raiz, int e, unsigned int ocurrencias) {


	if (raiz == NULL)
	{
		raiz = new ABB;
		raiz->dato = e;
		raiz->cant = ocurrencias;
		raiz->izq = NULL;
		raiz->der = NULL;
	
	}
	else if (e < raiz->dato) {

		agregarAux(raiz->izq, e, ocurrencias);

	}
	else if (e > raiz->dato)
	{

		agregarAux(raiz->der, e, ocurrencias);
	}
	else
	{
		raiz->cant += ocurrencias;
	}

}

void agregar(MultisetInt& m, int e, unsigned int ocurrencias){

	if (ocurrencias > 0) 
	{

		agregarAux(m->raiz, e, ocurrencias);
		m->cantElem += ocurrencias;
	}

}

//PRE: Recibe un arbol no vacio
//POS: retorna el minimo elemento de le arbol en parametros
ABB* min(ABB* raiz) {

	while (raiz->izq != NULL) {
	
		raiz = raiz->izq;

	}

	return raiz;
}
//PRE: recibe un arbol no vacio y un elemento perteneciente a ese arbol
//POS: elimina el nodo de el elemento perteneciente al arbol

void borrarNodoAux(ABB*& raiz , int e) {


	if (raiz != NULL)
	{
		
		if (raiz->dato < e) {
	
			borrarNodoAux(raiz->der, e);
		}
		else if (raiz->dato > e)
		{
			borrarNodoAux(raiz->izq, e);
		}
		else {
		
				ABB* aux = raiz;
				raiz = raiz->der;

				delete aux;

		}
	}
}

// PRE: -
//POS: Si encuentra e, decrementa su cantidad si su cantidad es  1 borra el nodo

bool borrarAux(ABB*& raiz, int e) {

	if (raiz == NULL)
	{
		return false;
	}

	if (raiz->dato > e)
	{
		return borrarAux(raiz->izq, e);

	}
    else if (raiz->dato < e)
	{
		return borrarAux(raiz->der, e);

	}
	else {
		if (raiz->cant > 1)
		{
			raiz->cant--;
			return true;

		}
		else {



			if (raiz->izq == NULL)
			{

				ABB* aux = raiz;
				raiz = raiz->der;
				delete aux;


			}
			else if (raiz->der == NULL)
			{
				ABB* aux = raiz;
				raiz = raiz->izq;
				delete aux;

			}
			else
			{
				ABB* aux = min(raiz->der);
				raiz->dato = aux->dato;
				raiz->cant = aux->cant;
				borrarNodoAux(raiz->der, aux->dato);

			}

			return true;
		}
	}
}



void borrar(MultisetInt& m, int e) {

	if (m != NULL && m->raiz!=NULL)
	{
		if (borrarAux(m->raiz ,e))
		{
			m->cantElem--;
		}
		
	}
}


//PRE: raiz != NULL
//POS:retorna true si el elemento e se encuentra en raiz

bool buscar(ABB * raiz , int e){


	if (raiz != NULL)
	{


		if (raiz->dato == e)
		{
			return true;

		}
		else if (raiz->dato < e)
		{

			return buscar(raiz->der, e);

		}
		else if (raiz->dato > e)
		{
			return buscar(raiz->izq, e);


		}

	}

	return false;


}

bool pertenece(MultisetInt m, int e) {

	if (m != NULL && m->raiz != NULL)
	{
		return buscar(m->raiz, e);

	}
	return false;
}

//PRE:-
//POS: devuelve la cantidad de ocurrencias del elemento e en la raiz
int obtenerCant(ABB* raiz, int e) {

	if (raiz == NULL)
	{
		return 0;

	}
	if (raiz->dato == e)
	{
		return raiz->cant;

	}
	if (raiz->dato < e)
	{
		return obtenerCant(raiz->der, e);
	}
	return obtenerCant(raiz->izq, e);
}

//PRE: recibe un res y raiz != NULL
//POS: recorre raiz de M2 y le suma las ocurrencias faltantes 

void unionAux(MultisetInt res,ABB*raiz) {

	if (raiz !=NULL)
	{

		int cantRes = obtenerCant(res->raiz, raiz->dato);

		if (raiz->cant > cantRes)
		{

		
	    	agregar(res, raiz->dato, raiz->cant - cantRes);
		}


		unionAux(res, raiz->der);
		unionAux(res, raiz->izq);


	}
}
	
MultisetInt unionConjuntos(MultisetInt m1, MultisetInt m2) {


	if (m1 == NULL && m2 == NULL)
	{

		return crearMultisetInt();

	}
	if (m1 != NULL && m2 == NULL)
	{
		return clon(m1);
	}
	if (m1 == NULL && m2 != NULL)
	{
		return clon(m2);
	}


	MultisetInt ret = clon(m1);
	unionAux(ret, m2->raiz);
	return ret;
}

//PRE:recibe 2 ABB !=NULL
//POS: Si el dato de R1 esta en R2 se agrega a el multiset ret
void interseccionAux(MultisetInt ret,ABB* R1,ABB* R2) {


	if (R1 == NULL)
	{
		return;
	}


	int cant = obtenerCant(R2, R1->dato);

	if (cant > 0)
	{

		int minC = cant;

		if (R1->cant < cant)
		{
			minC = R1->cant;

		}

		agregar(ret, R1->dato, minC);

	}




	interseccionAux(ret, R1->der, R2);
	interseccionAux(ret, R1->izq, R2);


}



MultisetInt interseccionConjuntos(MultisetInt m1, MultisetInt m2) {

	MultisetInt ret = crearMultisetInt();
	if (m1 != NULL && m2 != NULL)
	{
		interseccionAux(ret, m1->raiz, m2->raiz);
	}

		
	return ret;
}


//PRE: se reciben 2 ABB != NULL
//POS:si el dato de R1 NO estaen R2 se agrega a el multiset

void diferenciaAux(MultisetInt ret, ABB* R1, ABB* R2) {

	if (R1 == NULL)
	{
		return;

	}

	int cantR2 = obtenerCant(R2 , R1->dato);

	if (R1->cant > cantR2)
	{
		agregar(ret, R1->dato, R1->cant - cantR2);

	}

	diferenciaAux(ret, R1->der, R2);
	diferenciaAux(ret, R1->izq, R2);


}


MultisetInt diferenciaConjuntos(MultisetInt m1, MultisetInt m2) {


	if (m1 == NULL || m1->raiz == NULL){

		return crearMultisetInt();
	}
	if (m2 == NULL || m2->raiz == NULL)
	{
		return clon(m1);
	}
	
	MultisetInt ret = crearMultisetInt();

	diferenciaAux(ret, m1->raiz, m2->raiz);
	return ret;
	
}


//PRE: -
//POS: retorna true si solo si los elementos de R1 estan contenidos en R2

bool contenidos(ABB* R1, ABB* R2) {

	if (R1 == NULL)
	{
		return true;
	}

	int cantR2 = obtenerCant(R2, R1->dato);

	if (R1->cant > cantR2)
	{
		return false;
	}

	return contenidos(R1->der, R2) && contenidos(R1->izq , R2);
}

bool contenidoEn(MultisetInt m1, MultisetInt m2) {

	if (m1 == NULL || m1 ->raiz == NULL)
	{

		return true;
	}
	if (m2 == NULL || m2->raiz == NULL)
	{

		return false;
	}


	return contenidos(m1->raiz, m2->raiz);

}

int elemento(MultisetInt m) {
	
	if (m != NULL && m->raiz != NULL)
	{

		return m->raiz->dato;


	}

	return 0;  // para evitar advertencias
}

bool esVacio(MultisetInt m) {

	if (m == NULL || m->raiz == NULL)
	{
		return true;
	}

	return false;
}

unsigned int cantidadElementos(MultisetInt m) {

	if (m != NULL)
	{


		return m->cantElem;

	}

	return 0;
}

// PRE: -
//POS: Elimina los nodos de raiz
void destruirAux(ABB* raiz){

	if(raiz!= NULL)
	{
		destruirAux(raiz->izq);
		destruirAux(raiz->der);
	
		delete raiz;
	}

}

void destruir(MultisetInt& m) {

	if (m !=NULL)
	{
		destruirAux(m->raiz);

		delete m;
		m = NULL;
	}
}
//PRE: -
//POS: crea una copia de raiz

ABB* clonarAux(ABB* raiz) {

	if (raiz == NULL)
	{
		return NULL;
	}
	ABB* ret = new ABB;
	ret->cant = raiz->cant;
	ret->dato = raiz->dato;
	ret->der = clonarAux(raiz->der);
	ret->izq = clonarAux(raiz->izq);

	return ret;
}
MultisetInt clon(MultisetInt m) {

	MultisetInt ret = crearMultisetInt();
	
	if (m != NULL)
	{
		ret->cantElem = m->cantElem;

		ret->raiz = clonarAux(m->raiz);

	}
	
	return ret;
}

#endif
