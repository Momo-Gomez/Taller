#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "Arbol.cpp"
#include "Lista_comunas.cpp"
using namespace std;

void leerComunas(string nombre_archivo, Lista_comunas *lista_comunas){
	ifstream comunas;
	comunas.open(nombre_archivo,ios::in);
	if(comunas.is_open()){
    
		string reg;
		while(!comunas.eof()){
			getline(comunas,reg);
			istringstream regCopy(reg);
			string lineaTemp;
			vector <string> infoInv;
			while(getline(regCopy,lineaTemp,',')){
				infoInv.push_back(lineaTemp);
			}
			string comuna;
			int latitud,longitud;
			
			istringstream(infoInv[0])>>comuna;
			istringstream(infoInv[1])>>latitud;
			istringstream(infoInv[2])>>longitud;
			
      lista_comunas->ingresar_comuna_txt(comuna,latitud,longitud);
      
			infoInv.clear();
		}
		comunas.close();
	}else{
		cout<<"Problema al abrir el archivo 'comunas.txt'."<<endl;
		system("pause");
	}
	
}

void leercasos(string nombre_archivo, Lista_comunas* lista_comunas){
	ifstream casos;
	casos.open(nombre_archivo,ios::in);
	if(casos.is_open()){
    
		string reg;
		while(!casos.eof()){
			getline(casos,reg);
			istringstream regCopy(reg);
			string lineaTemp;
			vector <string> infoInv;
			while(getline(regCopy,lineaTemp,',')){
				infoInv.push_back(lineaTemp);
			}
			string comuna;
			int poblacion,casos;
			
			istringstream(infoInv[0])>>comuna;
			istringstream(infoInv[1])>>poblacion;
			istringstream(infoInv[2])>>casos;
			
      lista_comunas->ingresar_casos_txt(comuna, poblacion, casos);
      
			infoInv.clear();
		}
		casos.close();
	}else{
		cout<<"Problema al abrir el archivo 'casos.txt'."<<endl;
		system("pause");
	}
	
}	
	



int main() {
  
  Lista_comunas comunas;/* ingresar(string nombre_comuna, double longitud, double latitud, int cantidad_poblacion, int numero_casos)*/
  Arbol dual_tree;/* el ingresar del arbol recibe un arreglo de nodo_arbol con las hojas que son las comunas o sea desde la lista de comuna hay que formar por cada comuna una hoja con los datos que pide*/
  
}