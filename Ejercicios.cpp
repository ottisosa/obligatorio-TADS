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
            destruir(aux);
            destruir(pila1);
            destruir(pila2);
            return false;
        }

        destruir(aux);
        pop(pila1);
     
    }

    destruir(pila1);
    destruir(pila2);

    return true;
}


void EliminarMaximos(ColaInt& c){

    if (!esVacia(c))
    {

        ColaInt aux = crearColaInt();
        int maximo = principio(c);
        
        while (!esVacia(c))
        {
            encolar(aux, principio(c));

            if (principio(c) > maximo)
            {
                maximo = principio(c);
            }

            desencolar(c);
        }


        while (!esVacia(aux))
        {

            if (principio(aux) == maximo)
            {
                desencolar(aux);
            }
            else {
            
                encolar(c, principio(aux));

                desencolar(aux);
            }

        }

        destruir(aux);

    }
}

ListaPosInt ObtenerRepetidos(MultisetInt m){

   ListaPosInt ret = crearListaPosInt();
   MultisetInt copia = clon(m); // creo una copia para no modificar m
   while (!esVacio(copia))
   {
       int elem = elemento(copia);
       borrar(copia, elem);
       if (pertenece(copia, elem))
       {
           int pos = 0;
           agregar(ret,elem, pos);
           pos++;

           while (pertenece(copia,elem))
           {
               borrar(copia, elem);
           }
       }
   }
   return ret;
}

void RestringirDominio(TablaIntString& t, MultisetInt permitidos){

    if (t != NULL)
    {
        TablaIntString aux = crearTablaIntString(cantidadElementos(t));

        while (!esVacia(t))
        {
            if (pertenece(permitidos,elemento(t)))
            {
                agregar(aux,elemento(t), recuperar(t,elemento(t)));
            }
            borrar(t, elemento(t));

        }

        destruir(t);

        t = aux;
    }

}
ColaInt RecorridaDFS(GrafoInt grafo, int origen){

    ColaInt ret = crearColaInt();
    int n = cantidadVertices(grafo);

    bool* conocidos = new bool[n];

    for (int i = 0; i < n; i++)
    {

        conocidos[i] = false;

    }


    PilaInt stack = crearPilaInt();
    push(stack, origen);



    while (!esVacia(stack))
    {
        int valor = top(stack);
        pop(stack);
    
        if (valor >=0 && valor < n && !conocidos[valor])
        {
            conocidos[valor] = true;
            encolar(ret, valor);


            int cant = cantidadConexiones(grafo, valor);
            int* vecinosAct = vecinos(grafo, valor);
        

            for (int i = cant - 1; i >= 0 ; i--)
            {
                int vec = vecinosAct[i];

                if (!conocidos[vec])
                {
                    push(stack,vec);

                }

            }
            if (vecinosAct != NULL)
            {


                delete[] vecinosAct;
            }
        }
    
    }

    destruir(stack);
    delete[] conocidos;


    return ret;
}
