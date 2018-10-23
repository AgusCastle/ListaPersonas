#include "DoubleList.h"
#include <iostream>
#include <cstdlib>
#include <algorithm>

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


int DoubleList::Buscar(const string &curp)
{
	int pos = 0;
	iterador = inicio;
	while (iterador != nullptr && iterador->valor.getCurp() != curp)
	{
		iterador = iterador->siguiente;
		pos++;
	}
	if (iterador == nullptr)
		return -1;
	return pos;
}


void DoubleList::Insertar(const Persona &persona)
{
	nuevo= new Nodo(persona);
	if( Vacia())
	{
		inicio = nuevo;
		fin = inicio;
	}
	else
	{
		nuevo->atras = fin;
    	fin->siguiente = nuevo;
    	fin = nuevo;
	}
	nuevo->valor.GenerarCurp();
	count++;
}


void DoubleList::Eliminar(const string &curp)
{
	if (!Vacia())
  {
    if (Buscar(curp) != -1)
    {
      if (iterador == inicio && iterador == fin)
      {
        inicio = nullptr;
        fin =  nullptr;
      }
      else if (iterador == inicio)
      {
        iterador->siguiente->atras = nullptr;
        inicio = inicio->siguiente;
      }
      else if (iterador == fin)
      {
        iterador->atras->siguiente = nullptr;
        fin = fin->atras;
      }
      else
      {
        iterador->atras->siguiente = iterador->siguiente;
        iterador->siguiente->atras = iterador->atras;
      }
      delete iterador;
      count--;
    }
    else
      cout << " No se encuentra en la lista." << endl;
  }
}


void DoubleList::Ordenar()
{
	Nodo *menor, *i_comp = NULL;
	Persona aux_persona;
	string nom_menor = "", nom_comparacion = "";
	iterador = inicio;
	while (iterador != NULL)
	{
		menor = iterador;
		i_comp = iterador->siguiente;
		while (i_comp != NULL)
		{
			nom_menor = menor->valor.getAp() + " " + menor->valor.getAm() + " " + menor->valor.getNombre();
			nom_comparacion = i_comp->valor.getAp() + " " + i_comp->valor.getAm() + " " + i_comp->valor.getNombre();

			if (ComparacionAlfabeto(nom_menor, nom_comparacion))
				menor = i_comp;
	  		i_comp = i_comp->siguiente;
		}
		
		if (menor != iterador)
		{
	  		aux_persona = iterador->valor;
	  		iterador->valor = menor->valor;
	  		menor->valor = aux_persona;
		}
		iterador = iterador->siguiente;
	}
}


void DoubleList::Mostrar()
{
	int pos = 0;
	string nombre;
	Persona persona;
	if (!Vacia())
	{
		iterador = inicio;
		while (iterador != nullptr)
		{
			persona = iterador->valor;
			nombre = persona.getNombre() + " " + persona.getAp() + " " + persona.getAm();
			cout << "| " << persona.getCurp() << " | " << nombre;
			for (int i = 0; i < (40 - nombre.size()); ++i) 
				cout << " ";

			cout << "| " << persona.getFechaNacimiento();
			for (int i = 0; i < (17 - persona.getFechaNacimiento().size()); ++i)
				cout << " ";

			cout << "| " << persona.getGenero() << " | " << persona.getEntidadFederativa();
			for (int i = 0; i < (20 - persona.getEntidadFederativa().size()); ++i)
				cout << " ";
			
			cout << "|" << endl << "|";
			for (int i = 0; i < 100; ++i)
				cout << "-";
			
			cout << "|" << endl;
			iterador = iterador->siguiente;
		}
	}
	else
		cout << "Lista Vacia." << endl;
}

bool DoubleList::ComparacionAlfabeto(string nombre1, string nombre2)
{
	bool menor = false;
	for (int i = 0; i < nombre1.size() && i < nombre2.size(); ++i)
	{
		if (toupper(nombre1[i]) < toupper(nombre2[i]) && (nombre1[i] != 32 && nombre2[i] != 32))
			menor = true;
	}
	return menor;
}