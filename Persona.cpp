#include "Persona.h"
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