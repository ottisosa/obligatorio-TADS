#include "GrafoInt.h"

#ifdef GRAFO_INT_MATRIZ

//Si necestita otra estructura se puede definir aqui

struct _representacionGrafoInt {

    int cantVertices;
    int cantAristas;
    bool dirigido;
    int** mat;
};

GrafoInt crearGrafo(int numVertices, bool dirigido)
{ 

    GrafoInt ret = new _representacionGrafoInt;
    ret->cantVertices = numVertices;
    ret->cantAristas = 0;
    ret->dirigido = dirigido;

    if (numVertices > 0)
    {
        ret->mat = new int* [numVertices];

        for (int i = 0; i < numVertices; i++)
        {
            ret->mat[i] = new int[numVertices];

            for (int j = 0; j < numVertices; j++)
            {
                ret->mat[i][j] = -1;
            }
        }

    }
    else
    {
        ret->mat = NULL;
    }

    return ret;
}

void agregarArista(GrafoInt& grafo, int origen, int destino, int peso)
{
    if (grafo !=NULL && grafo->mat != NULL)
    {
        if (grafo->mat[origen][destino] == -1)
        {
            grafo->cantAristas++;
        }

        grafo->mat[origen][destino] = peso;

        if (grafo->dirigido == false && origen != destino)
        {
            grafo->mat[destino][origen] = peso;
        }
    }

}

void eliminarArista(GrafoInt& grafo, int origen, int destino)
{

    if (grafo != NULL && tieneArista(grafo, origen, destino))
    {

        if (!grafo->dirigido)
        {
            grafo->mat[destino][origen] = -1;

        }
        grafo->mat[origen][destino] = -1;

        grafo->cantAristas--;
    }
}

bool tieneArista(GrafoInt grafo, int origen, int destino)
{
    if (grafo != NULL && grafo->mat != NULL)
    {

        return grafo->mat[origen][destino] != -1;

    }
    
    return false;
}

int pesoArista(GrafoInt grafo, int origen, int destino)
{

    if (grafo != NULL && grafo->mat != NULL)
    {

        return grafo->mat[origen][destino];

    }
    return -1;
}

int cantidadConexiones(GrafoInt grafo, int vertice)
{
    int cant = 0;

    if (grafo != NULL && grafo->mat != NULL)
    {

        for (int i = 0; i < grafo->cantVertices; i++)
        {

            if (grafo->mat[vertice][i] != -1)
            {
                cant++;
            }

        }


    }
    return cant;
}

int* vecinos(GrafoInt grafo, int vertice)
{

    if (grafo != NULL && grafo->mat != NULL)
    {

        int cantVecinos = cantidadConexiones(grafo, vertice);

        if (cantVecinos == 0)
        {
            return NULL;
        }


        int* ret = new int[cantVecinos];

        int pos = 0;

        for (int i = 0; i < grafo->cantVertices; i++)
        {
            if (grafo->mat[vertice][i] != -1)
            {
                ret[pos] = i;
                pos++;
            }

        }

        return ret;
    }
    return NULL;
}

bool esDirigido(GrafoInt grafo)
{

    if (grafo != NULL && grafo->mat != NULL)
    {
        return grafo->dirigido;
    }
    return false;
}

int cantidadVertices(GrafoInt grafo)
{
    if (grafo != NULL && grafo->mat != NULL)
    {
        return grafo->cantVertices;
    }

    return 0;
}

int cantidadAristas(GrafoInt grafo)
{

    if (grafo != NULL && grafo->mat != NULL)
    {
        return grafo->cantAristas;
    }

    return 0;

}

GrafoInt clon(GrafoInt grafo)
{

    if (grafo != NULL)
    {
        GrafoInt copia = crearGrafo(grafo->cantVertices, grafo->dirigido);
        copia->cantAristas = grafo->cantAristas;
        if (grafo->mat != NULL)
        {
            for (int i = 0; i < grafo->cantVertices; i++)
            {
                for (int j = 0; j < grafo->cantVertices; j++)
                {
                    copia->mat[i][j] = grafo->mat[i][j];


                }

            }
        }

        return copia;
    }
    return NULL;
}

void destruir(GrafoInt& grafo)
{

    if (grafo != NULL)
    {
        if (grafo->mat != NULL)
        {


            for (int i = 0; i < grafo->cantVertices; i++)
            {
                delete[] grafo->mat[i];
            }
        
        
            delete[] grafo->mat;


        }

        delete grafo;
        grafo = NULL;
    }
}

#endif
