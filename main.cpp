#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Arbol.cpp"
#include "Lista_comunas.cpp"
using namespace std;

void leerComunas(string nombre_archivo, Lista_comunas *lista_comunas)
{
	ifstream comunas;
	comunas.open(nombre_archivo, ios::in);
	if (comunas.is_open())
	{

		string reg;
		while (!comunas.eof())
		{
			getline(comunas, reg);
			istringstream regCopy(reg);
			string lineaTemp;
			vector<string> infoInv;
			while (getline(regCopy, lineaTemp, ','))
			{
				infoInv.push_back(lineaTemp);
			}
			string comuna;
			double latitud, longitud;

			comuna = infoInv[0];
			istringstream(infoInv[1]) >> longitud;
			istringstream(infoInv[2]) >> latitud;

			lista_comunas->ingresar_comuna_txt(comuna, longitud, latitud);

			infoInv.clear();
		}
		comunas.close();
	}
	else
	{
		cout << "Problema al abrir el archivo 'comunas.txt'." << endl;
		system("pause");
	}
}

void leerCasos(string nombre_archivo, Lista_comunas *lista_comunas)
{
	ifstream casos;
	casos.open(nombre_archivo, ios::in);
	if (casos.is_open())
	{

		string reg;
		while (!casos.eof())
		{
			getline(casos, reg);
			istringstream regCopy(reg);
			string lineaTemp;
			vector<string> infoInv;
			while (getline(regCopy, lineaTemp, ','))
			{
				infoInv.push_back(lineaTemp);
			}
			string comuna;
			int poblacion, casos;

			comuna = infoInv[0];
			istringstream(infoInv[1]) >> poblacion;
			istringstream(infoInv[2]) >> casos;

			lista_comunas->ingresar_casos_txt(comuna, poblacion, casos);

			infoInv.clear();
		}
		casos.close();
	}
	else
	{
		cout << "Problema al abrir el archivo 'casos.txt'." << endl;
		system("pause");
	}
}
void formacion_hojas_arbol(Lista_comunas *comunas, nodo_arbol *hojas)
{ //problema de creacion de hojas
	int tamano = comunas->get_tamano();
	Nodo_comuna *aux = comunas->getfirst();
	nodo_arbol *hoja;
	Comuna *comuna;
	string nombre;
	double longitud;
	double latitud;
	int cantidad_poblacion;
	int numero_casos;
	int i = 0;
	while (aux != nullptr)
	{
		comuna = aux->get_comuna();
		nombre = comuna->get_nombre_comuna();
		longitud = comuna->get_longitud();
		latitud = comuna->get_latitud();
		cantidad_poblacion = comuna->get_cantidad_poblacion();
		numero_casos = comuna->get_numero_casos();
		hoja = new nodo_arbol(nombre, longitud, latitud, longitud, latitud, cantidad_poblacion, numero_casos);
		hojas[i++] = *hoja;
		aux = aux->get_next();
	}
}
void casos_confirmado_nacional(Arbol *arbol)
{ //RF1
	cout << "Casos confirmado a nivel nacional: " << arbol->casos_confirmados_nacional() << endl;
}
void casos_confirmado_nivel(Arbol *arbol)
{ //RF2
	cout << "Ingrese nivel a revisar: ";
	int nivel = 0;
	scanf("%i", &nivel);
	if (nivel >= 1 && nivel <= 8)
	{
		arbol->casos_confirmados_nivel(nivel);
	}
}
void casos_confirmados_puntos(Arbol *arbol)
{ //RF3
	cout << "Ingrese longitud Menor: ";
	int longitud1 = 0;
	scanf("%i", &longitud1);
	cout << "Ingrese latitud Menor: ";
	int latitud2 = 0;
	scanf("%i", &latitud2);
	;
	cout << "Ingrese longitud Mayor: ";
	int longitud2 = 0;
	scanf("%i", &longitud2);
	cout << "Ingrese latitud Mayor: ";
	int latitud1 = 0;
	scanf("%i", &latitud1);
	arbol->casos_confirmados_puntos(longitud2, longitud1, latitud1, latitud2);
}
void porcentaje_casos(Arbol *arbol)
{ //RF4.1
	arbol->porcentaje_casos_confirmados();
}
void comunas_porcentaje_casos(Arbol *arbol)
{
	cout << "Ingrese porcentaje a buscar: ";
	int porcentaje = 0;
	scanf("%i", &porcentaje);
	if (porcentaje >= 0 && porcentaje <= 100)
	{
		arbol->comunas_rango_porcentaje(porcentaje);
	}
}
void menu(Arbol *arbol)
{
	cout << "****************MENÚ****************\n"
		 << endl;
	cout << "1) Casos confirmando a nivel nacional." << endl;
	cout << "2) Casos condirmado en un nivel." << endl;
	cout << "3) Casos confirmando entre puntos" << endl;
	cout << "4) Porcentaje de casos confirmados" << endl;
	cout << "5) Comunas en rango de porcentaje" << endl;
	cout << "6) SALIR" << endl;
	cout << "\nRespueta: ";
	int resp = 0;
	scanf("%i", &resp);

	while (resp != 6)
	{
		if (resp == 1)
		{
			casos_confirmado_nacional(arbol);
		}
		else if (resp == 2)
		{
			casos_confirmado_nivel(arbol);
		}
		else if (resp == 3)
		{
			casos_confirmados_puntos(arbol);
		}
		else if (resp == 4)
		{
			porcentaje_casos(arbol);
		}
		else if (resp == 5)
		{
			comunas_porcentaje_casos(arbol);
		}

		cout << "\n\n\n****************MENÚ****************\n"
			 << endl;
		cout << "1) Casos confirmando a nivel nacional." << endl;
		cout << "2) Casos condirmado en un nivel." << endl;
		cout << "3) Casos confirmando entre puntos" << endl;
		cout << "4) Porcentaje de casos confirmados" << endl;
		cout << "5) Comunas en rando de porcentaje" << endl;
		cout << "6) SALIR" << endl;
		cout << "\nRespueta: ";
		resp = 0;
		scanf("%i", &resp);
	}
	if (resp == 6)
	{
		cout << "\n\n\n++++++++++FIN DEL PROGRAMA++++++++++" << endl;
	}
}

int main()
{
	Lista_comunas *comunas = new Lista_comunas();
	Arbol *arbol = new Arbol();
	nodo_arbol *hojas_arbol;
	leerComunas("comunas.txt", comunas);
	leerCasos("casos.txt", comunas);
	comunas->ordenar_latitud();
	int tamano = comunas->get_tamano();
	hojas_arbol = new nodo_arbol[tamano];
	formacion_hojas_arbol(comunas, hojas_arbol);
	arbol->insertar_hojas(hojas_arbol, tamano);
	menu(arbol);
	//###############inicio test#####################################
	//#################fin test######################################
}