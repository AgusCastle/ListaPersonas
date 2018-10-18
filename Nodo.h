#include "Persona.h"

struct Nodo
{
	Persona valor;
	Nodo * siguiente;
	Nodo * atras;

	Nodo(const Persona &val) : valor(val), siguiente(nullptr), atras(nullptr) { }
};