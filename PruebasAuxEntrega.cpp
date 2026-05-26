#include "PruebasAuxEntrega.h"

void pruebaEstaContenida(const char* pila1, const char* pila2)
{
	cout << "Llamada: " << "EstaContenida" << "(" << pila1 << ", " << pila2 << ")" << endl;
	int largoLista1;
	int largoLista2;
	NodoListaIntFramework* lista1 = (NodoListaIntFramework*)FrameworkA1::parsearColeccion(pila1, largoLista1);
	NodoListaIntFramework* lista2 = (NodoListaIntFramework*)FrameworkA1::parsearColeccion(pila2, largoLista2);

	PilaInt p1 = FrameworkA1::ConvertirAPila(lista1);
	PilaInt p2 = FrameworkA1::ConvertirAPila(lista2);

	bool res = EstaContenida(p1, p2);

	if (res)
	{
		cout << "Esta contenida" << endl;
	}
	else
	{
		cout << "No esta contenida" << endl;
	}

	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);

	destruir(p1);
	destruir(p2);
}


void pruebaEliminarMaximos(const char* cola)
{
    cout << "Llamada: " << "EliminarMaximos" << "(" << cola << ")" << endl;
    int largoLista1;
    NodoListaIntFramework* lista1 = (NodoListaIntFramework*)FrameworkA1::parsearColeccion(cola, largoLista1);

    ColaInt c = FrameworkA1::ConvertirACola(lista1);
 
    EliminarMaximos(c);
    
    if (c != NULL) {
        if (esVacia(c)) {
            cout << "No hay elementos" << endl;
        }
        else {
            while (!esVacia(c))
            {
                int e = principio(c);
                cout << e;
                desencolar(c);
                if (!esVacia(c)) cout << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "NULL" << endl;
    }
    
    FrameworkA1::destruir(lista1);
    destruir(c);
}

// Devuelve una nueva lista con los elementos de 'l' ordenados de menor a mayor.
// No modifica 'l' y no comparte memoria con la lista original.
ListaPosInt OrdenarAscendente(ListaPosInt l) {
    // Caso base: lista vacía
    if (esVacia(l)) {
        return crearListaPosInt();
    }

    // Trabajamos sobre un clon para no modificar 'l'
    ListaPosInt tmp = clon(l);
    ListaPosInt res = crearListaPosInt();

    // Selección: extraer repetidamente el mínimo de 'tmp' y agregarlo al final de 'res'
    while (!esVacia(tmp)) {
        unsigned int n = cantidadElementos(tmp);

        // Buscar mínimo y su posición en 'tmp'
        int minVal = elemento(tmp, 0);
        unsigned int minPos = 0;
        for (unsigned int i = 1; i < n; ++i) {
            int v = elemento(tmp, i);
            if (v < minVal) {
                minVal = v;
                minPos = i;
            }
        }

        // Agregar al final de 'res'
        agregar(res, minVal, cantidadElementos(res));

        // Quitar esa aparición del mínimo de 'tmp'
        borrar(tmp, minPos);
    }

    destruir(tmp);
    return res;
}


void pruebaObtenerRepetidos(const char* multiset)
{
	cout << "Llamada: " << "ObtenerRepetidos" << "(" << multiset << ")" << endl;
	int largo;
	NodoListaIntFramework* listaParseada = (NodoListaIntFramework*)FrameworkA1::parsearColeccion(multiset, largo);

	MultisetInt m = FrameworkA1::ConvertirAMultiSet(listaParseada);

	ListaPosInt aux = ObtenerRepetidos(m);
    //se ordena ascendentemente para simplificar la comparación final
    ListaPosInt l = OrdenarAscendente(aux);

	if (l != NULL) {
		if (esVacia(l)) {
			cout << "No hay elementos" << endl;
		}
		else {
			while (!esVacia(l))
			{
				int e = elemento(l,0);
				cout << e;
				borrar(l,0);
				if (!esVacia(l)) cout << " ";
			}
			cout << endl;
		}
		destruir(l);
	}
	else {
		cout << "NULL" << endl;
	}

	FrameworkA1::destruir(listaParseada);
	destruir(m);
    destruir(aux);
}

// Ordena la lista enlazada por dato1 usando Bubble Sort
NodoListaIntStringFramework* ordenarListaPorDato1(NodoListaIntStringFramework* cabeza) {
    if (!cabeza || !cabeza->sig) return cabeza; // 0 o 1 nodo

    bool cambiado;
    NodoListaIntStringFramework* ptr;
    NodoListaIntStringFramework* ultimo = NULL;

    do {
        cambiado = false;
        ptr = cabeza;

        while (ptr->sig != ultimo) {
            if (ptr->dato1 > ptr->sig->dato1) {
                // Intercambiamos los valores, no los nodos
                int tmpDato1 = ptr->dato1;
                char* tmpDato2 = ptr->dato2;

                ptr->dato1 = ptr->sig->dato1;
                ptr->dato2 = ptr->sig->dato2;

                ptr->sig->dato1 = tmpDato1;
                ptr->sig->dato2 = tmpDato2;

                cambiado = true;
            }
            ptr = ptr->sig;
        }
        ultimo = ptr; // al final de cada pasada, el último ya está ordenado
    } while (cambiado);

    return cabeza;
}

char* copiarCharPtr(const char* origen) {
    if (origen == NULL) return NULL;

    size_t longitud = strlen(origen) + 1; // +1 para '\0'
    char* copia = new char[longitud];

    for(size_t i = 0; i < longitud; i++)
        copia[i] = origen[i];

    return copia;
}

void pruebaRestringirDominio(const char* keys, const char* values, const char* permitidos)
{
    cout << "Llamada: " << "RestringirDominio" << "(" << keys << ", " << values << ", " << permitidos << ")" << endl;
    int largoKey;
    int largoValue;
    NodoListaIntFramework* listaKey = (NodoListaIntFramework*)FrameworkA1::parsearColeccion(keys, largoKey);
    NodoListaStringFramework* listaValue = (NodoListaStringFramework*)FrameworkA1::parsearColeccion(values, largoValue);
    int largoMS;
    NodoListaIntFramework* listaParseada = (NodoListaIntFramework*)FrameworkA1::parsearColeccion(permitidos, largoMS);

    TablaIntString t = FrameworkA1::ConvertirATabla(listaKey, listaValue);
    MultisetInt m = FrameworkA1::ConvertirAMultiSet(listaParseada);

    RestringirDominio(t, m);
    
    if (t != NULL) {
        if (esVacia(t)) {
            cout << "No hay elementos" << endl;
        }
        else {
            NodoListaIntStringFramework* lista = NULL;
            while (!esVacia(t))
            {
                int elem = elemento(t);
                const char* r = recuperar(t, elem);
                char* r2 = copiarCharPtr(r);
                
                NodoListaIntStringFramework* aux = new NodoListaIntStringFramework(elem, r2);
                aux->sig = lista;
                lista = aux;
                
                borrar(t, elem);
            }
            
            lista = ordenarListaPorDato1(lista);
            
            while (lista != NULL)
            {
                int elem = lista->dato1;
                char* r = lista->dato2;
                
                cout << elem << "->" << r;
                
                NodoListaIntStringFramework* aux = lista;
                lista = lista->sig;
                delete []aux->dato2;
                delete aux;
                
                if (lista != NULL) cout << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "NULL" << endl;
    }
    
    FrameworkA1::destruir(listaKey);
    FrameworkA1::destruir(listaValue);
    FrameworkA1::destruir(listaParseada);
    destruir(t);
    destruir(m);
}


void pruebaRecorridaDFS(const char* origenes, const char* destinos, const char* pesos, int nroVertices, int dirigido, int origen){
    cout << "Llamada: " << "RecorridaDFS" << "(" << origenes << ", " << destinos << ", " << pesos << ", " << nroVertices << ", " << dirigido << ", " << origen << ")" << endl;
    int largoOrigenes;
    int largoDestinos;
    int largoPesos;
    NodoListaIntFramework* listaOrigenes = (NodoListaIntFramework*)FrameworkA1::parsearColeccion(origenes, largoOrigenes);
    NodoListaIntFramework* listaDestinos = (NodoListaIntFramework*)FrameworkA1::parsearColeccion(destinos, largoDestinos);
    NodoListaIntFramework* listaPesos = (NodoListaIntFramework*)FrameworkA1::parsearColeccion(pesos, largoPesos);
    
    GrafoInt g = FrameworkA1::ConvertirAGrafo(listaOrigenes, listaDestinos, listaPesos, nroVertices, dirigido);
    
    ColaInt c = RecorridaDFS(g, origen);
    
    if (c != NULL) {
        if (esVacia(c)) {
            cout << "No hay elementos" << endl;
        }
        else {
            while (!esVacia(c))
            {
                int e = principio(c);
                cout << e;
                desencolar(c);
                if (!esVacia(c)) cout << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "NULL" << endl;
    }
    
    FrameworkA1::destruir(listaOrigenes);
    FrameworkA1::destruir(listaDestinos);
    FrameworkA1::destruir(listaPesos);
    destruir(g);
    destruir(c);
}
