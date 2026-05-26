#include "PruebasGrafoInt.h"

void pruebasGrafoIntDirigido(Prueba* prueba);
void pruebasGrafoIntNoDirigido(Prueba* prueba);


void pruebasGrafoInt(Prueba* pruebaConcreta) {
    pruebaConcreta->mImpresion.iniciarSeccion("PRUEBAS GrafoInt");
    pruebasGrafoIntDirigido(pruebaConcreta);
    pruebasGrafoIntNoDirigido(pruebaConcreta);
    pruebaConcreta->mImpresion.cerrarSeccion("PRUEBAS GrafoInt");

}


// =============================================================
//  GRAFO DIRIGIDO
// =============================================================
void pruebasGrafoIntDirigido(Prueba* pruebaConcreta)
{
    GrafoInt g = crearGrafo(6, true);
    cout << "Es dirigido: " << esDirigido(g) << endl;
    cout << "#vertices: " << cantidadVertices(g) << endl;
    cout << "#aristas (inicio): " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Creo grafo dirigido vacío");

    // Agregar aristas
    agregarArista(g, 0, 1, 5);
    agregarArista(g, 0, 2, 2);
    agregarArista(g, 2, 4, 7);
    agregarArista(g, 5, 0, 1);
    cout << "#aristas tras agregar: " << cantidadAristas(g) << endl;
    cout << "Tiene 0->1: " << tieneArista(g, 0, 1) << ", peso: " << pesoArista(g, 0, 1) << endl;
    cout << "Tiene 0->2: " << tieneArista(g, 0, 2) << ", peso: " << pesoArista(g, 0, 2) << endl;
    cout << "Tiene 2->4: " << tieneArista(g, 2, 4) << ", peso: " << pesoArista(g, 2, 4) << endl;
    cout << "Tiene 5->0: " << tieneArista(g, 5, 0) << ", peso: " << pesoArista(g, 5, 0) << endl;
    pruebaConcreta->ver3("Agrego aristas e inspecciono existencia y peso");

    // Conexiones y vecinos
    cout << "Conexiones desde 0: " << cantidadConexiones(g, 0) << endl;
    cout << "Conexiones desde 2: " << cantidadConexiones(g, 2) << endl;
    cout << "Conexiones desde 3 (aislado): " << cantidadConexiones(g, 3) << endl;
    cout << "Conexiones desde 5: " << cantidadConexiones(g, 5) << endl;
    pruebaConcreta->ver3("Verifico grado de salida y vecinos");

    // Actualización de peso
    agregarArista(g, 0, 1, 8);
    cout << "Peso 0->1 actualizado: " << pesoArista(g, 0, 1) << endl;
    cout << "#aristas (sin duplicar por actualización): " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Actualizar una arista no cambia la cantidad de aristas");

    // Búsquedas que no existen
    cout << "Tiene 1->5 (no existe): " << tieneArista(g, 1, 5) << endl;
    cout << "Peso 1->5 (inexistente): " << pesoArista(g, 1, 5) << endl;
    pruebaConcreta->ver3("Consultar arista inexistente (peso debería ser -1)");

    // Borrar arista
    eliminarArista(g, 0, 2);
    cout << "Tras eliminar 0->2, tiene 0->2: " << tieneArista(g, 0, 2) << endl;
    cout << "#aristas: " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Elimino una arista existente y re-chequeo vecinos");

    // Idempotencia de eliminar
    eliminarArista(g, 0, 2);
    cout << "Eliminar 0->2 nuevamente no cambia #aristas: " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Eliminar una arista inexistente no debe afectar el grafo");

    // Bucle (self-loop)
    agregarArista(g, 3, 3, 9);
    cout << "Tiene 3->3: " << tieneArista(g, 3, 3) << ", peso: " << pesoArista(g, 3, 3) << endl;
    cout << "Conexiones desde 3 (con bucle): " << cantidadConexiones(g, 3) << endl;
    pruebaConcreta->ver3("Agrego un bucle y verifico efectos en grado y vecinos");

    // Clonado e independencia (incluye vecinos)
    GrafoInt c = clon(g);
    cout << "#aristas (original): " << cantidadAristas(g) << endl;
    cout << "#aristas (clon): " << cantidadAristas(c) << endl;
    pruebaConcreta->ver3("Clono el grafo y comparo vecinos");

    eliminarArista(c, 0, 1);
    agregarArista(c, 1, 0, 4);
    cout << "(clon) tiene 0->1: " << tieneArista(c, 0, 1) << ", (orig) tiene 0->1: " << tieneArista(g, 0, 1) << endl;
    cout << "(clon) #aristas: " << cantidadAristas(c) << ", (orig) #aristas: " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Modifico el clon y verifico que el original no cambie (incluye vecinos)");

    destruir(c);
    destruir(g);
    pruebaConcreta->ver3("Libero memoria");
}

// =============================================================
//  GRAFO NO DIRIGIDO
// =============================================================
void pruebasGrafoIntNoDirigido(Prueba* pruebaConcreta)
{
    GrafoInt g = crearGrafo(5, false);
    cout << "Es dirigido: " << esDirigido(g) << endl;
    cout << "#vertices: " << cantidadVertices(g) << endl;
    cout << "#aristas (inicio): " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Creo grafo no dirigido vacío");

    // Agregar aristas (deben reflejarse en ambos sentidos)
    agregarArista(g, 0, 1, 1);
    agregarArista(g, 3, 4, 3);
    cout << "#aristas tras agregar {0-1, 3-4}: " << cantidadAristas(g) << endl;
    cout << "Tiene 0-1: " << (tieneArista(g, 0, 1) && tieneArista(g, 1, 0)) << endl;
    cout << "Peso 1->0 (de 0-1): " << pesoArista(g, 1, 0) << endl;
    pruebaConcreta->ver3("Agrego aristas y verifico simetría y vecinos en no dirigidos");

    // Actualización de peso en arista existente (no cambia vecinos)
    agregarArista(g, 0, 1, 5);
    cout << "Peso actualizado 0-1: (0->1) " << pesoArista(g, 0, 1)
         << ", (1->0) " << pesoArista(g, 1, 0) << endl;
    cout << "#aristas se mantiene: " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Actualizar peso no duplica aristas ni cambia vecinos");

    // Peso 0 y bucle
    agregarArista(g, 2, 2, 0); // bucle con peso 0
    cout << "Tiene 2-2: " << tieneArista(g, 2, 2) << ", peso: " << pesoArista(g, 2, 2) << endl;
    cout << "#aristas (con bucle): " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Agrego bucle con peso 0 y verifico vecinos");

    // Clonado e independencia
    GrafoInt c = clon(g);
    eliminarArista(c, 0, 1); // debe eliminar en ambos sentidos
    cout << "(clon) tiene 0-1: " << (tieneArista(c, 0, 1) || tieneArista(c, 1, 0)) << endl;
    cout << "(orig) tiene 0-1: " << (tieneArista(g, 0, 1) && tieneArista(g, 1, 0)) << endl;
    cout << "(clon) #aristas: " << cantidadAristas(c) << ", (orig) #aristas: " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Eliminación en el clon no afecta al original (incluye vecinos)");

    // Eliminaciones adicionales
    eliminarArista(g, 3, 4);
    cout << "Tras eliminar 3-4, conexiones(3): " << cantidadConexiones(g, 3)
         << ", conexiones(4): " << cantidadConexiones(g, 4) << endl;
    cout << "#aristas: " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Elimino arista en no dirigido y verifico grados, vecinos y conteo");

    // Idempotencia de eliminar
    eliminarArista(g, 3, 4);
    cout << "Eliminar 3-4 nuevamente no cambia #aristas: " << cantidadAristas(g) << endl;
    pruebaConcreta->ver3("Eliminar arista inexistente no cambia el grafo");

    destruir(c);
    destruir(g);
    pruebaConcreta->ver3("Libero memoria");
}
