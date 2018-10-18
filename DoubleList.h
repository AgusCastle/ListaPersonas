#include "Nodo.h"

class DoubleList
{
private:
	int count;
	Nodo * inicio;
	Nodo * nuevo;
	Nodo * iterador;
	Nodo * fin;
public:
	DoubleList();
	~DoubleList();
	bool Vacia();
	int Buscar(const Persona&);
	void Insertar(const Persona&);
	void Eliminar(const Persona&);
	void Ordenar();
	void Mostrar();
};