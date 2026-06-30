#include "GrafoInt.h"

#ifdef GRAFO_INT_LISTA

//Si necestita otra estructura se puede definir aqui

struct NodoA{

    int destino;
    int peso;
    NodoA* sig;
};
struct _representacionGrafoInt {

    int cantVertices;
    int cantAristas;
    bool dirigido;
    NodoA** ListaAdy;
};

GrafoInt crearGrafo(int numVertices, bool dirigido){

    GrafoInt ret = new _representacionGrafoInt;
    ret->cantVertices = numVertices;
    ret->cantAristas = 0;
    ret->dirigido = dirigido;

    if (numVertices > 0)
    {
        ret->ListaAdy = new NodoA * [numVertices];

        for (int i = 0; i < numVertices; i++)
        {
            ret->ListaAdy[i] = NULL;
        }

    }
    else {
        ret->ListaAdy = NULL;
    }
    return ret;
}

void agregarArista(GrafoInt& grafo, int origen, int destino, int peso){

    if (grafo != NULL)
    {
        NodoA* aux = grafo->ListaAdy[origen];

        while (aux !=NULL)
        {
            if (aux->destino = destino)
            {
                aux->peso = peso;

                if (grafo->dirigido == false && origen != destino)
                {
                    NodoA* inv = grafo->ListaAdy[destino];

                    while (inv != NULL)
                    {
                        if (inv->destino == origen)
                        {
                            inv->peso = peso;
                        }

                        inv = inv->sig;
                    }

                }
            }
            aux = aux->sig;

        }

        NodoA * nuevo = new NodoA;
        nuevo->destino = destino;
        nuevo->peso = peso;
        nuevo->sig = grafo->ListaAdy[origen];
        grafo->ListaAdy[origen] = nuevo;
        
        if (grafo->dirigido == false && origen != destino)
        {
            NodoA* nuevoInv = new NodoA;
            nuevoInv->destino = origen;
            nuevoInv->peso = peso;
            nuevoInv->sig = grafo->ListaAdy[destino];
            grafo->ListaAdy[destino] = nuevoInv;
        }

        grafo->cantAristas++;
    }
}

void eliminarArista(GrafoInt& grafo, int origen, int destino){

    if (grafo != NULL)
    {
        if (tieneArista(grafo, origen, destino))
        {

            NodoA* aux = grafo->ListaAdy[origen];
            NodoA* ant = NULL;
            while (aux != NULL && aux->destino != destino )
            {
                ant = aux;
                aux = aux->sig;

            }


            if (aux != NULL)
            {
                if (ant == NULL)
                {
                    grafo->ListaAdy[origen] = aux->sig;
                }

                else
                {
                    ant->sig = aux->sig;
                }
                delete aux;

            }

            if (grafo->dirigido == false && origen != destino)
            {
                NodoA* actInv = grafo->ListaAdy[destino];
                NodoA* antInv = NULL;

                while (actInv != NULL && actInv->destino != origen)
                {
                    antInv = actInv;
                    actInv = actInv->sig;

                }

                if (actInv != NULL)
                {
                    if (antInv == NULL)
                    {
                        grafo->ListaAdy[destino] = actInv->sig;
                    }
                    else
                    {
                        antInv->sig = actInv->sig;
                    }

                    delete actInv;
                }
            }

            grafo->cantAristas--;
        }

    }
}

bool tieneArista(GrafoInt grafo, int origen, int destino){

    if (grafo != NULL)
    {

        NodoA* aux = grafo->ListaAdy[origen];

        while (aux != NULL)
        {
            if (aux->destino == destino)
            {
                return true;
            }
            aux = aux->sig;
        }
        if (aux == NULL)
        {
            return false;
        }

    }
    return false;
}

int pesoArista(GrafoInt grafo, int origen, int destino){

    if (grafo != NULL)
    {

        NodoA* aux = grafo->ListaAdy[origen];

        while (aux != NULL)
        {
            if (aux->destino == destino)
            {
                return aux->peso;
            }
            aux = aux->sig;
        }

    }
    return -1;
}

int cantidadConexiones(GrafoInt grafo, int vertice){

    int cant = 0;

    if (grafo != NULL)
    {
        NodoA* aux = grafo->ListaAdy[vertice];

        while (aux != NULL)
        {
            cant++;
            aux = aux->sig;

        }
    }    
    return cant;
}

int* vecinos(GrafoInt grafo, int vertice){

    if (grafo != NULL)
    {

        int vecinos = cantidadConexiones(grafo, vertice);

        if (vecinos == 0 )
        {
            return NULL;
        }
        int* ret = new int[vecinos];

        NodoA* aux = grafo->ListaAdy[vertice];
  
        for (int i = 0; i < vecinos; i++)
        {
            ret[i] = aux->destino;
            aux = aux->sig;

        }

        return ret;
    }
    return NULL;
}

bool esDirigido(GrafoInt grafo){

    if (grafo != NULL)
    {

        return grafo->dirigido;

    }

    return false;

}

int cantidadVertices(GrafoInt grafo){
    if (grafo != NULL)
    {
        return grafo->cantVertices;

    }    
    return 0;
}

int cantidadAristas(GrafoInt grafo){
    if (grafo != NULL)
    {
        return grafo->cantAristas;
    } 
    return 0;
}

GrafoInt clon(GrafoInt grafo){

    if (grafo != NULL)
    {
        GrafoInt copia = crearGrafo(grafo->cantVertices, grafo->dirigido);
        copia->cantAristas = grafo->cantAristas;

        if (grafo->cantAristas == 0)
        {
            return copia;
        }
   
        for (int i = 0; i < grafo->cantVertices; i++)
        {
            NodoA* actOrigin = grafo->ListaAdy[i];

            if (actOrigin != NULL)
            {
                NodoA* nuevo = new NodoA;

                nuevo->destino = actOrigin->destino;
                nuevo->peso = actOrigin->peso;
                nuevo->sig = NULL;
                copia->ListaAdy[i] = nuevo;


                NodoA* ultimo = nuevo;
                actOrigin = actOrigin->sig;

                while (actOrigin != NULL)
                {
                    NodoA* NodoSig = new NodoA;
                    NodoSig->destino = actOrigin->destino;
                    NodoSig->peso = actOrigin->peso;
                    NodoSig->sig = NULL;

                    ultimo->sig = NodoSig;
                    ultimo = NodoSig;

                    actOrigin = actOrigin->sig;

                }

            }

        }

    }
    return NULL;
}

void destruir(GrafoInt& grafo){

    if (grafo != NULL)
    {
        if (grafo->ListaAdy != NULL)
        {


            for (int i = 0; i < grafo->cantVertices; i++)
            {
                NodoA* aux = grafo->ListaAdy[i];

                while (aux != NULL)
                {
                    NodoA* borrar = aux;

                    aux = aux->sig;
                    delete[] borrar;
                }


            }

            delete[] grafo->ListaAdy;
        }

        delete grafo;
        grafo = NULL;
    }
}

#endif
