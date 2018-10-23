#include "Nodo.h"
#include <string>

class DoubleList
{
private:
	int count;
	Nodo * inicio;
	Nodo * nuevo;
	Nodo * iterador;
	Nodo * fin;
	bool ComparacionAlfabeto(std::string, std::string);
public:
	DoubleList();
	~DoubleList();
	bool Vacia();
	int Buscar(const std::string&);
	void Insertar(const Persona&);
	void Eliminar(const std::string&);
	void Ordenar();
	void Mostrar();
};