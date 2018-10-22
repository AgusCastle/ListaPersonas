#include "Persona.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

Persona::Persona()
{
	nombre = "0";
	ap_paterno = "0";
	ap_materno = "0";
	fecha_nacimiento = "0";
	genero =0;
	entidad_federativa ="0";
	curp = "0";
}

Persona::Persona(string nom, string ap, string am, string fecha, char g, string e_fed)
{
	nombre = nom;
	ap_paterno = ap;
	ap_materno = am;
	fecha_nacimiento = fecha;
	genero = g;
	entidad_federativa = e_fed;
	curp = "";
}

Persona::Persona(const Persona &p_copia)
{
	nombre = p_copia.nombre;
	ap_paterno = p_copia.ap_paterno;
	ap_materno = p_copia.ap_materno;
	fecha_nacimiento = p_copia.fecha_nacimiento;
	genero = p_copia.genero;
	entidad_federativa = p_copia.entidad_federativa;
	curp = "";
}

Persona::~Persona()
{
}

string Persona::getNombre() const
{
		return nombre;
}

string Persona::getAp() const
{
	return ap_paterno;
}

string Persona::getAm() const
{
	return ap_materno;
}

string Persona::getFechaNacimiento() const
{
	return fecha_nacimiento;
}

char Persona::getGenero() const 
{
	return genero;
}

string Persona::getEntidadFederativa() const 
{
	return entidad_federativa;
}

string Persona::getCurp() const 
{
	return curp;
}

void Persona::setCurp(string _curp){
	curp = _curp;
}


void Persona::GenerarCurp(){
	bool control = false;
	string diccionario = "aeiou";
	string abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string Curp = "000000000000000000";
	string aux,aux2="          ";
	aux = getAp();
	int Size = aux.size(),k;
	srand(time(NULL));
	Curp[0] = aux[0];
	for (int i =1; i < Size; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (aux[i] == diccionario[j])
			{
				control = true;
				Curp[1] = aux[i];
				break;
			}
		}
		if(control) break;
	}
	Curp[2] = getAm()[0];
	Curp[3] = getNombre()[0];
	Size = getFechaNacimiento().size();
	Curp[4] = getFechaNacimiento()[Size-2];
	Curp[5] = getFechaNacimiento()[Size-1];

	aux = getFechaNacimiento();
	for (int i = 3; i < Size; i++)
	{
		if (aux[i] == '/')
			break;
		else
			aux2[i-3] = aux[i]; 
	}
	diccionario = "0123456789";
	Size = diccionario.size();
	control = false;
	for (int i = 0; i < Size; ++i)
	{
		if (aux2[0] == diccionario[i]){
			control = true;
			break;
		}
	}
	if (control){
		Curp[6] = getFechaNacimiento()[3];
		Curp[7] = getFechaNacimiento()[4];
	}
	else{
		aux = Mes(aux2);
		Curp[6] = aux[0];
		Curp[7] = aux[1];
	}
	
	Curp[8] = getFechaNacimiento()[0];
	Curp[9] = getFechaNacimiento()[1];
	Curp[10] = getGenero();
	aux2 = getEntidadFederativa();
	aux = EntidadFederativa(aux2);
	Curp[11] = aux[0];
	Curp[12] = aux[1];
	Curp[13] = PrimeraConsonante(getAp());
	Curp[14] = PrimeraConsonante(getAm());
	Curp[15] = PrimeraConsonante(getNombre());
	Size = getFechaNacimiento().size();
	aux = "    ";
 	k = Size-4;
	for (int i = 0; i < 4;i++)
	{
	 	aux[i] = getFechaNacimiento()[k];
	 	k++;
	}
	if (stoi(aux) < 2000){
		k = 0 + rand() % (9);
		aux = to_string(k);
		Curp[16] = aux[0];
	} 
	else{
		k = 0 + rand() % (26);
		Curp[16] = abecedario[k]; 
	}
	k = 0 + rand() % (9);
	aux = to_string(k);
	Curp[17] = aux[0];
	setCurp(Curp);
	//cout << "Su CURP es: " << getCurp() << endl;
}

string Persona::Mes(string _mes){
	string NoMes;
	if(_mes == "enero     ")
		NoMes = "01";
	if(_mes == "febrero   ")
		NoMes = "02";
	if(_mes == "marzo     ")
		NoMes = "03";
	if(_mes == "abril     ")	
		NoMes = "04";
	if(_mes == "mayo      ")
		NoMes = "05";
	if(_mes == "junio     ")
		NoMes = "06";
	if(_mes == "julio     ")
		NoMes = "07";
	if(_mes == "agosto    ")
		NoMes = "08";
	if(_mes == "septiembre")
		NoMes = "09";
	if(_mes == "octubre   ")
		NoMes = "10";
	if(_mes == "noviembre ")
		NoMes = "11";
	if(_mes == "diciembre ")
		NoMes = "12";
	return NoMes;
}

string Persona::EntidadFederativa(string _entidad){
	string conosonantes;
	if (_entidad == "aguascalientes")
		conosonantes = "AS";
	if (_entidad == "baja california")
		conosonantes = "BC";
	if (_entidad == "baja california sur")
		conosonantes = "BS";
	if (_entidad == "campeche")
		conosonantes = "CC";
	if (_entidad == "coahuila")
		conosonantes = "CL";
	if (_entidad == "colima")
		conosonantes = "CM";
	if (_entidad == "chiapas")
		conosonantes = "CS";
	if (_entidad == "chihuahua")
		conosonantes = "CH";
	if (_entidad == "distrito federal" || _entidad == "ciudad de mexico")
		conosonantes = "DF";
	if (_entidad == "durango")
		conosonantes = "DG";
	if (_entidad == "guanajuato")
		conosonantes = "GT";
	if (_entidad == "guerrero")
		conosonantes = "GR";
	if (_entidad == "hidalgo")
		conosonantes = "HG";
	if (_entidad == "jalisco")
		conosonantes = "JC";
	if (_entidad == "mexico")
		conosonantes = "MC";
	if (_entidad == "michoacan")
		conosonantes = "MN";
	if (_entidad == "morelos")
		conosonantes = "MS";
	if (_entidad == "nayarit")
		conosonantes = "NT";
	if (_entidad == "nuevo leon")
		conosonantes = "NL";
	if (_entidad == "oaxaca")
		conosonantes = "OC";
	if (_entidad == "puebla")
		conosonantes = "PL";
	if (_entidad == "queretaro")
		conosonantes = "QT";
	if (_entidad == "quintana roo")
		conosonantes = "QR";
	if (_entidad == "san luis potosi")
		conosonantes = "SP";
	if (_entidad == "sinaloa")
		conosonantes = "SL";
	if (_entidad == "sonora")
		conosonantes = "SR";
	if (_entidad == "tabasco")
		conosonantes = "TC";
	if (_entidad == "tamaulipas")
		conosonantes = "TS";
	if (_entidad == "tlaxcala")
		conosonantes = "TL";
	if (_entidad == "veracruz")
		conosonantes = "VZ";
	if (_entidad == "yucatan")
		conosonantes = "YN";
	if (_entidad == "zacatecas")
		conosonantes = "ZS";
	return conosonantes;		
}

char Persona::PrimeraConsonante(string _ap){
	char consonate;
	string diccionario = "bcdfghjklmnpqrstvwxyz";
	bool primera = false;
	int Size = diccionario.size();
	int SizeAp = _ap.size();
	for (int i = 1; i < SizeAp; i++)
	{
		if (primera) break;
		for (int j = 0; j < Size; j++)
		{
			if (_ap[i] == diccionario[j]){
				consonate = _ap[i];
				primera = true;
				break;
			}
		}	
	}
	return consonate;
}