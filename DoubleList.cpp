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