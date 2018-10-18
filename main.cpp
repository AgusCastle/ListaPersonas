#include "DoubleList.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int menu();

int main() 
{
  	int valor;
	char seguir = 's';
	while (seguir != 'n')
	{
		switch (menu())
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
    	default:
			cout << "No seleccionaste nada." << endl;
			break;
		}
		system("pause");
		system("cls");
	}
}

int menu()
{
 	 int op;
	vector<string> menu = {
		"1.- Insertar.",
		"2.- Sacar.",
		"3.- Salir." };
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