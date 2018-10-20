#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>

void generarCURP(char[30], char[30], char[30], char[30], char, int, int, int);
char* obtener_ApP(char[30]);
char obtener_ApM(char[30]);
char obtener_Nom(char[30]);
char* EntidadFed(char[30]);
char vocal(char[], int, int);
char consonante(char[30]);
bool Es_Prepocion(char[]);
bool validarNombre(char[]);
bool incluye(char[], char);
bool es_palabra_inconveniente(char[30]);

void main()
{
	char apellido_paterno[30], apellido_materno[30], nombre[30], entidad_federativa[30], genero;
	int year, mount, day;

	printf("\n\t\tCLAVE UNICA DE REGISTRO POBLACIONAL.\n\t\t\t\tCURP");

	printf("\n\n\t\tApelledio Paterno: ");
	gets(apellido_paterno);

	printf("\n\t\tApellido Materno: ");fflush( stdin );
	gets(apellido_materno);

	printf("\n\t\tNombre(s): ");fflush( stdin );
	gets(nombre);

	printf("\n\t\tEntidad Federativa de nacimiento: ");fflush( stdin );
	gets(entidad_federativa);

	printf("\n\t\tGenero(H/M): ");fflush( stdin );
	scanf("%c", &genero);

	printf("\n\t\tFecha de nacimiento.");

	printf("\n\t\t\tAnio de nacimiento: ");
	scanf("%d", &year);

	printf("\n\t\t\tMes de nacimiento: ");
	scanf("%d", &mount);

	printf("\n\t\t\tDia de nacimiento: ");
	scanf("%d", &day);
	generarCURP(apellido_paterno, apellido_materno, nombre, entidad_federativa, genero, year, mount, day);
	getch();
}

void generarCURP(char ap_pat[30], char ap_mat[30], char nom[30], char e_fed[30], char gnr, int y, int m, int d)
{
	char nombre_curp[4] = {'\0'};
	int i, homoclave[2] = {0};
	for (i = 0; i < 4; ++i) {
		if (i == 0)
			strcpy(nombre_curp, obtener_ApP(ap_pat));
		if (i == 2)
			nombre_curp[i] = obtener_ApM(ap_mat);
		if (i == 3)
			nombre_curp[i] = obtener_Nom(nom);
	}
	if (strlen(nombre_curp) > 4) {
		nombre_curp[4] = '\0';
	}
	if (es_palabra_inconveniente(nombre_curp)) {
		nombre_curp[1] = 'x';
	}
	for (int j = 0; j < strlen(nombre_curp); ++j) {
		nombre_curp[j] = toupper(nombre_curp[j]);
	}
	if(y >= 2000) {
		srand(time(NULL));
		homoclave[0] = 97 + rand() % ((122+1)-97);
		homoclave[1] = 0 + rand() % ((9+1)-0);
		printf("\n\t\t%s%.2d%.2d%.2d%c%s%c%c%c%c%d", nombre_curp, (y % 100), m, d, toupper(gnr), EntidadFed(e_fed), toupper(consonante(ap_pat)), toupper(consonante(ap_mat)), toupper(consonante(nom)), toupper(homoclave[0]), homoclave[1]);
	}
	else {
		srand(time(NULL));
		for (int i = 0; i < 2; ++i)
		{
			homoclave[i] = 0 + rand() % ((9+1)-0);
		}
		printf("\n\t\t%s%.2d%.2d%.2d%c%s%c%c%c%d%d", nombre_curp, (y % 100), m, d, toupper(gnr), EntidadFed(e_fed), toupper(consonante(ap_pat)), toupper(consonante(ap_mat)), toupper(consonante(nom)), homoclave[0], homoclave[1]);
	}
}

char *obtener_ApP(char ap[30]) {
	static char letras[2];
	char *apellidos, ap_param[30] = "";
	if (incluye(ap, 32)) {
		strcpy(ap_param, ap);
		apellidos = strtok(ap_param, " ");
        while( apellidos != NULL ) {
            if (Es_Prepocion(apellidos)) {
                apellidos = strtok(NULL, " ");
            }
            else {
                break;
            }
        }
        letras[0] = apellidos[0];
		letras[1] += vocal(apellidos, strlen(apellidos), 1);
	}
    else {
        letras[0] = ap[0];
		letras[1] += vocal(ap, strlen(ap), 1);
    }
	if(letras[0] == 164 || letras[0] == -92)
		letras[0] = 'x';
    return letras;
}

char obtener_ApM(char am[30]) {
	char letra, *apellidos_maternos, am_param[30] = "";
		if (strcmp(am, "") == 0) {
		letra = 'x';
	}
	else {
		if (incluye(am, 32)) {
			strcpy(am_param, am);
			apellidos_maternos = strtok(am_param, " ");
			while( apellidos_maternos != NULL ) {
				if (Es_Prepocion(apellidos_maternos)) {
					apellidos_maternos = strtok(NULL, " ");
				}
				else {
					break;
				}
			}
			letra = apellidos_maternos[0];
		}
		else {
			letra = am[0];
		}
		if(letra == 164 || letra == -92)
			letra = 'x';
	}
	return letra;
}

char obtener_Nom(char nom[30]) {
	char letra, *nombres, nom_param[30] = "";
	if (incluye(nom, 32)) {
		strcpy(nom_param, nom);
		nombres = strtok(nom_param, " ");
		while( nombres != NULL ) {
			if (Es_Prepocion(nombres) || validarNombre(nombres)) {
				nombres = strtok(NULL, " ");
			}
			else {
				break;
			}
		}
		letra = nombres[0];
	}
	else {
		letra = nom[0];
	}
	if(letra == 164 || letra == -92)
		letra = 'x';
	return letra;
}

char *EntidadFed(char ef[30]) {
	for (int i = 0; i < strlen(ef); ++i)
	{
		ef[i] = toupper(ef[i]);
	}
	if (strlen(ef) > 2)
	{
		if (strcmp(ef, "AGUASCALIENTES") == 0)
			strcpy(ef , "AS");
		if (strcmp(ef, "BAJA CALIFORNIA") == 0)
			strcpy(ef , "BC");
		if (strcmp(ef, "BAJA CALIFORNIA SUR") == 0)
			strcpy(ef , "BS");
		if (strcmp(ef, "CAMPECHE") == 0)
			strcpy(ef , "CC");
		if (strcmp(ef, "CHIAPAS") == 0)
			strcpy(ef , "CS");
		if (strcmp(ef, "CHIHUAHUA") == 0)
			strcpy(ef , "CH");
		if (strcmp(ef, "COAHUILA") == 0)
			strcpy(ef , "CL");
		if (strcmp(ef, "COLIMA") == 0)
			strcpy(ef , "CM");
		if (strcmp(ef, "DISTRITO FEDERAL") == 0)
			strcpy(ef , "DF");
		if (strcmp(ef, "DURANGO") == 0)
			strcpy(ef , "DG");
		if (strcmp(ef, "ESTADO DE MEXICO") == 0)
			strcpy(ef , "MC");
		if (strcmp(ef, "GUANAJUATO") == 0)
			strcpy(ef , "GT");
		if (strcmp(ef, "GUERRERO") == 0)
			strcpy(ef , "GR");
		if (strcmp(ef, "HIDALGO") == 0)
			strcpy(ef , "HG");
		if (strcmp(ef, "JALISCO") == 0)
			strcpy(ef , "JC");
		if (strcmp(ef, "MICHOACAN") == 0)
			strcpy(ef , "MN");
		if (strcmp(ef, "MORELOS") == 0)
			strcpy(ef , "MS");
		if (strcmp(ef, "NAYARIT") == 0)
			strcpy(ef , "NT");
		if (strcmp(ef, "NUEVO LEON") == 0)
			strcpy(ef , "NL");
		if (strcmp(ef, "OAXACA") == 0)
			strcpy(ef , "OC");
		if (strcmp(ef, "PUEBLA") == 0)
			strcpy(ef , "PL");
		if (strcmp(ef, "QUERETARO") == 0)
			strcpy(ef , "QT");
		if (strcmp(ef, "QUINTANA ROO") == 0)
			strcpy(ef , "QR");
		if (strcmp(ef, "SAN LUIS POTOSI") == 0)
			strcpy(ef , "SP");
		if (strcmp(ef, "SINALOA") == 0)
			strcpy(ef , "SL");
		if (strcmp(ef, "SONORA") == 0)
			strcpy(ef , "SR");
		if (strcmp(ef, "TABASCO") == 0)
			strcpy(ef , "TC");
		if (strcmp(ef, "TAMAULIPAS") == 0)
			strcpy(ef , "TS");
		if (strcmp(ef, "TLAXCALA") == 0)
			strcpy(ef , "TL");
		if (strcmp(ef, "VERACRUZ") == 0)
			strcpy(ef , "VZ");
		if (strcmp(ef, "YUCATAN") == 0)
			strcpy(ef , "YN");
		if (strcmp(ef, "ZACATECAS") == 0)
			strcpy(ef , "ZS");
	}
	return ef;
}

char vocal(char str[], int lon, int init) {
	char letra;
    letra = '\0';
	for (int i = init; i < lon; ++i) {
		if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			letra = str[i];
			break;
		}
	}
    if (letra == '\0')
        letra = 'x';
	return letra;
}

char consonante(char str[30]) {
	char letra, *nombres, str_param[30] = "";
    letra = '\0';
	if (incluye(str, 32)) {
		strcpy(str_param, str);
		nombres = strtok(str_param, " ");
		while( nombres != NULL ) {
			if (Es_Prepocion(nombres) || validarNombre(nombres)) {
				nombres = strtok(NULL, " ");
			}
			else {
				break;
			}
		}
		for (int i = 1; i < strlen(nombres); ++i) {
			if(nombres[i] != 'a' && nombres[i] != 'e' && nombres[i] != 'i' && nombres[i] != 'o' && nombres[i] != 'u') {
				letra = nombres[i];
				break;
			}
		}
	}
	else {
        for (int i = 1; i < strlen(str); ++i) {
            if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') {
                letra = str[i];
                break;
            }
        }
    }
	if(letra == 164 || letra == -92 || letra == '\0')
		letra = 'x';
	return letra;
}

bool Es_Prepocion(char str[]){
	char palabras [19][3] = {"da", "das", "de", "del", "der", "di", "die", "dd", "el", "la", "los", "las", "le", "les", "mac", "mc", "van", "von", "y"};
	bool condicion;
	condicion = false;
	for (int i = 0; i < 19; ++i) {
		if(strcmp(str, palabras[i]) == 0){
			condicion = true;
			break;
		}
	}
	return condicion;
}

bool validarNombre(char str[]) {
	char nombres [6][6] = {"maria", "ma.", "ma", "jose", "j", "j."};
	bool condicion;
	condicion = false;
	for (int i = 0; i < 6; ++i) {
		if(strcmp(str, nombres[i]) == 0){
			condicion = true;
			break;
		}
	}
	return condicion;
}

bool incluye(char str[], char car) {
	bool inc = false;
	for (int i = 0; i < strlen(str); ++i)
	{
		if (str[i] == car) {
			inc = true;
			break;
		}
	}
	return inc;
}

bool es_palabra_inconveniente(char str[4]) {
	char palabras[8][5] = {"peda", "pedo", "pene", "pipi", "pito", "popo", "puta", "puto"};
	bool condicion;
	condicion = false;
	for (int i = 0; i < 26; ++i) {
		if(strcmp(str, palabras[i]) == 0){
			condicion = true;
			break;
		}
	}
	return condicion;
}