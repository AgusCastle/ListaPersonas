#include <string>
class Persona
{
private:
	
	std::string nombre;
	std::string ap_paterno;
	std::string ap_materno;
	std::string fecha_nacimiento;
	char genero;
	std::string entidad_federativa;
	std::string curp;

public:
	Persona();
	Persona(std::string, std::string, std::string, std::string, char, std::string);
	Persona(const Persona&);
	~Persona();

	std::string getNombre();
	std::string getAp();
	std::string getAm();
	std::string getFechaNacimiento();
	char getGenero();
	std::string getEntidadFederativa();
	std::string getCurp();

	void setCurp(std::string);

	void GenerarCurp();
	std::string Mes(std::string);
	std::string EntidadFederativa(std::string);
	char PrimeraConsonante(std::string);
};