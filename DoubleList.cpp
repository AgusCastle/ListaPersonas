#include "DoubleList.h"
#include <iostream>
#include <cstdlib>

using namespace std;

DoubleList::DoubleList()
{
	inicio = nullptr;
	nuevo = nullptr;
	iterador = nullptr;
	fin = nullptr;
	count = 0;
}


DoubleList::~DoubleList()
{

}


bool DoubleList::Vacia()
{
	return (inicio == nullptr && fin == nullptr);
}


int DoubleList::Buscar(const Persona &persona)
{
	return 0;
}


void DoubleList::Insertar(const Persona &persona)
{
	nuevo= new Nodo(persona);
		if( Vacia())
		{
			inicio=nuevo;
			fin=inicio;
		}
		else
		{
			inicio->atras=nuevo;
			nuevo->siguiente=inicio;
			inicio=nuevo;
		}
}


void DoubleList::Eliminar(const Persona &persona)
{

}


void DoubleList::Ordenar()
{

}


void DoubleList::Mostrar()
{

}