
#include "PruebasEjemploDeUsoEntrega.h"

PruebasEjemploDeUsoEntrega::PruebasEjemploDeUsoEntrega(ConductorPrueba* conductor)
:Prueba(conductor)
{

}

PruebasEjemploDeUsoEntrega::~PruebasEjemploDeUsoEntrega()
{
	
}

const char* PruebasEjemploDeUsoEntrega::getNombre() const
{
	return "PruebasEjemploDeUsoEntrega";
}

void PruebasEjemploDeUsoEntrega::correrPruebaConcreta()
{
	pruebasPilaInt(this);
	pruebasListaPosInt(this);
	pruebasColaInt(this);
	pruebasTablaIntString(this);
	pruebasMultisetInt(this);
    pruebasGrafoInt(this);
    
    PruebasEjerciciosTAD();
}

void PruebasEjemploDeUsoEntrega::PruebasEjerciciosTAD()
{
	// Pruebas EstaContenida
	this->mImpresion.iniciarSeccion("PRUEBAS EstaContenida");
	pruebaEstaContenida("(1,7,4,2)", "(7,3,2,1)");
	ver3("Prueba de pila contenida 1");
	pruebaEstaContenida("(1,7,4,2)", "(7,3,2,1,4,8)");
	ver3("Prueba de pila contenida 2");
	pruebaEstaContenida("(1,7,4,2,7,4,4,7)", "(7,3,7,2,4,1,4,8)");
	ver3("Prueba de pila contenida 3");
	pruebaEstaContenida("(1,7,4,2,7,4,4,7)", "(7,3,7,2,4,4,4,7,1,4,8)");
	ver3("Prueba de pila contenida 4");
	this->mImpresion.cerrarSeccion("PRUEBAS EstaContenida");

    // Pruebas EliminarMaximos
    this->mImpresion.iniciarSeccion("PRUEBAS EliminarMaximos");
    pruebaEliminarMaximos("()");
    ver3("Prueba eliminar maximos de cola 1");
    pruebaEliminarMaximos("(1,4,9,-7,3)");
    ver3("Prueba eliminar maximos de cola 2");
    pruebaEliminarMaximos("(5,9,3,9,2,9,1)");
    ver3("Prueba eliminar maximos de cola 3");
    pruebaEliminarMaximos("(7,7,7,7)");
    ver3("Prueba eliminar maximos de cola 4");
    pruebaEliminarMaximos("(-5,-1,-3,-1,-7)");
    ver3("Prueba eliminar maximos de cola 5");
    this->mImpresion.cerrarSeccion("PRUEBAS EliminarMaximos");

	// Pruebas ObtenerRepetidos
	this->mImpresion.iniciarSeccion("PRUEBAS ObtenerRepetidos");
    pruebaObtenerRepetidos("(1,1,2)");
	ver3("Prueba obtener repetidos multiset 1");
    pruebaObtenerRepetidos("()");
    ver3("Prueba obtener repetidos multiset 2");
	pruebaObtenerRepetidos("(1,2,3,2,1)");
	ver3("Prueba obtener repetidos multiset 3");
	pruebaObtenerRepetidos("(10,4,6,1,1,10,5,8)");
	ver3("Prueba obtener repetidos multiset 4");
	pruebaObtenerRepetidos("(1,1,1,1,1,1)");
	ver3("Prueba obtener repetidos multiset 5");
	pruebaObtenerRepetidos("(4,6,4,6,4,6,4,6)");
	ver3("Prueba obtener repetidos multiset 6");
	pruebaObtenerRepetidos("(1,2,1,4,2,1,4,2,7)");
	ver3("Prueba obtener repetidos multiset 7");
	this->mImpresion.cerrarSeccion("PRUEBAS ObtenerRepetidos");
    
    // Pruebas RestringirDominio
    this->mImpresion.iniciarSeccion("PRUEBAS RestringirDominio");
    pruebaRestringirDominio("()","()","()");
    ver3("Prueba restringir dominio tabla 1");
    pruebaRestringirDominio("()","()","(1,2)");
    ver3("Prueba restringir dominio tabla 2");
    pruebaRestringirDominio("(1,2)","(\"a\",\"b\")","(1,2,3)");
    ver3("Prueba restringir dominio tabla 3");
    pruebaRestringirDominio("(1,2,3)","(\"a\",\"b\",\"c\")","()");
    ver3("Prueba restringir dominio tabla 4");
    pruebaRestringirDominio("(1,2,3,4)","(\"a\",\"b\",\"c\",\"d\")","(2,4)");
    ver3("Prueba restringir dominio tabla 5");
    pruebaRestringirDominio("(-5,0,7)","(\"x\",\"y\",\"z\")","(0,100)");
    ver3("Prueba restringir dominio tabla 6");
    pruebaRestringirDominio("(1,2,3)","(\"a\",\"b\",\"c\")","(2,2,2)");
    ver3("Prueba restringir dominio tabla 7");
    this->mImpresion.cerrarSeccion("PRUEBAS RestringirDominio");

    // Pruebas RecorridaDFS
    this->mImpresion.iniciarSeccion("PRUEBAS RecorridaDFS");
    pruebaRecorridaDFS("()","()","()",0,0,0);
    ver3("Prueba recorrida DFS grafo 1");
    pruebaRecorridaDFS("()","()","()",1,0,0);
    ver3("Prueba recorrida DFS grafo 2");
    pruebaRecorridaDFS("(0,1)","(1,2)","(1,1)",3,0,0);
    ver3("Prueba recorrida DFS grafo 3");
    pruebaRecorridaDFS("(0,2)","(1,3)","(1,1)",4,0,0);
    ver3("Prueba recorrida DFS grafo 4");
    pruebaRecorridaDFS("(0,1)","(1,2)","(1,1)",3,1,0);
    ver3("Prueba recorrida DFS grafo 5");
    pruebaRecorridaDFS("(0)","(1)","(1)",3,1,1);
    ver3("Prueba recorrida DFS grafo 6");
    pruebaRecorridaDFS("(0,1,2)","(1,2,0)","(1,1,1)",3,1,0);
    ver3("Prueba recorrida DFS grafo 7");
    pruebaRecorridaDFS("(1)","(2)","()",4,1,3);
    ver3("Prueba recorrida DFS grafo 8");
    this->mImpresion.cerrarSeccion("PRUEBAS RecorridaDFS");
}


