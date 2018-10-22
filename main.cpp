#include "DoubleList.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int menu();

int main() 
{	
	DoubleList Lista=DoubleList();
	Persona Registro;

	string Nombre = "Julio Cesar";
	string ApellidoP = "Aguilar";
	string ApellidoM = "Ramos";
	string FechaNac = "03/noviembre/1998";
	char sexo = 'H';
	string EntidadFederativa = "mexico";
	int pos;

	char seguir = 's';
	while (seguir != 'n')
	{
		switch (menu())
		{
		case 1:

			cout << "Introduce lo que se pide en el formato\n\n";
			cout << "Nombre/s: ";
			getline(cin,Nombre);
			cout << "Apellido Paterno: ";
			getline(cin,ApellidoP);
			cout << "Apellido Materno: ";
			getline(cin,ApellidoM);
			cout << "Fecha de Nacimiento(dd/mm/aaaa): ";
			getline(cin,FechaNac);
			cout << "Sexo(H/M): ";
			cin >> sexo;
			cin.ignore();
			cout << "Lugar de Nacimiento: ";
			getline(cin, EntidadFederativa);
			Registro = Persona(Nombre,ApellidoP,ApellidoM,FechaNac,sexo,EntidadFederativa);
			Lista.Insertar(Registro);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			system("cls");
			Lista.Mostrar();
			cout << "Ingresa el curp de la persona a buscar: "; getline(cin,Nombre);
			pos = Lista.Buscar(Nombre);
			if (pos != -1) 
				cout << "La persona se encuentra en la posicion " << pos << endl;
			else
				cout << "La persona no fue encontrada" << endl;
			break;
		case 5:
			Lista.Ordenar();
			break;
		case 6:
			Registro=Persona(Nombre,ApellidoP,ApellidoM,FechaNac,sexo,EntidadFederativa);
			Registro.GenerarCurp();//prueba
			break;
    	default:
			cout << "No seleccionaste nada." << endl;
			break;
		}
		system("pause");
		system("cls");
		Lista.Mostrar();
	}
}

int menu()
{
 	int op;
	vector<string> menu = {
		"1.- Insertar.",
		"2.- Eliminar.",
		"3.- Imprimir.",
		"4.- Busqueda.",
		"5.- Ordenar por apellido.",
		"6.- Obtener CURP." };
	cout << "\n\t\tMenu.\n" << endl;
	for (auto elemento : menu)
	{
		cout << "\t\t" << elemento << endl;
	}
	cout << "Ingresa el numero de tu opcion: ";
	cin >> op;
	cin.ignore();
	return op;
}
