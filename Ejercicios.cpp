#include "Ejercicios.h"

bool EstaContenida(PilaInt p1, PilaInt p2){

    PilaInt pila1 = clon(p1);
    PilaInt pila2 = clon(p2);

    if (esVacia(pila1))
    {
        destruir(pila1);
        destruir(pila2);

        return true;
    }
        

    while (!esVacia(pila1))
    {

        PilaInt aux = crearPilaInt();
        bool esta = false;
        int valor = top(pila1);

        while (!esVacia(pila2) && !esta)
        {

            if (valor == top(pila2))
            {

                pop(pila2);
                esta = true;

            }
            else
            {
                push(aux, top(pila2));
                pop(pila2);
            }

        }

        while (!esVacia(aux))
        {
            push(pila2, top(aux));

            pop(aux);
        }


        if (!esta)
        {
            destruir(pila1);
            destruir(pila2);
            return false;
        }


        pop(pila1);
     
    }

    destruir(pila1);
    destruir(pila2);

    return true;
}


void EliminarMaximos(ColaInt& c){
    //IMPLEMENTAR SOLUCION
}

ListaPosInt ObtenerRepetidos(MultisetInt m){
    //IMPLEMENTAR SOLUCION
    return NULL;
}

void RestringirDominio(TablaIntString& t, MultisetInt permitidos){
    //IMPLEMENTAR SOLUCION
}

ColaInt RecorridaDFS(GrafoInt grafo, int origen){
    //IMPLEMENTAR SOLUCION
    return NULL;
}
