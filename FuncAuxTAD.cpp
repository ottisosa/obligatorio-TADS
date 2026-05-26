#include "FuncAuxTAD.h"

ListaPosInt FrameworkA1::ConvertirAListaPos(NodoListaIntFramework *l) {
	ListaPosInt ret = crearListaPosInt();
	unsigned int pos = 0;
	while (l != NULL) {
		agregar(ret, l->dato, pos++);
        l = l->sig;
    }
	return ret;
}

PilaInt FrameworkA1::ConvertirAPila(NodoListaIntFramework *l) {
	PilaInt ret = crearPilaInt();
	while (l != NULL) {
		push(ret, l->dato);
        l = l->sig;
    }
	return ret;
}

ColaInt FrameworkA1::ConvertirACola(NodoListaIntFramework *l) {
	ColaInt ret = crearColaInt();
	while (l != NULL) {
		encolar(ret, l->dato);
        l = l->sig;
    }
	return ret;
}


MultisetInt FrameworkA1::ConvertirAMultiSet(NodoListaIntFramework *l) {
	MultisetInt ret = crearMultisetInt();
	while (l != NULL) {
		agregar(ret, l->dato, 1);
        l = l->sig;
    }
	return ret;
}

TablaIntString FrameworkA1::ConvertirATabla(NodoListaIntFramework *d, NodoListaStringFramework *r) {
	TablaIntString ret = crearTablaIntString(10);
	while (d != NULL && r != NULL) {
		agregar(ret, d->dato, r->dato);
		d = d->sig;
		r = r->sig;
    }
	assert (d == NULL && r == NULL);
	return ret;
}


GrafoInt FrameworkA1::ConvertirAGrafo(NodoListaIntFramework *o, NodoListaIntFramework *d, NodoListaIntFramework *p, int nv, int dir) {
    GrafoInt g = crearGrafo(nv, dir);
    
    while (o != NULL && d != NULL && p != NULL) {
        agregarArista(g, o->dato, d->dato, p->dato);
        o = o->sig;
        d = d->sig;
        p = p->sig;
    }
    
    return g;
}



