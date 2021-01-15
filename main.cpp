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
			double latitud,longitud;
			
			comuna= infoInv[0];
			istringstream(infoInv[1])>>longitud;
			istringstream(infoInv[2])>>latitud;
    
      
      
      lista_comunas->ingresar_comuna_txt(comuna,longitud,latitud);
      
			infoInv.clear();
		}
		comunas.close();
	}else{
		cout<<"Problema al abrir el archivo 'comunas.txt'."<<endl;
		system("pause");
	}
	
}

void leerCasos(string nombre_archivo, Lista_comunas* lista_comunas){
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
			
			comuna= infoInv[0];
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
void formacion_hojas(Lista_comunas* comunas, nodo_arbol* hojas){ //problema de creacion de hojas
  int tamano=comunas->get_tamano();
  Nodo_comuna* aux = comunas->getfirst();
  nodo_arbol* hoja;
  Comuna* comuna;
  string nombre;
  double longitud;
  double latitud;
  int cantidad_poblacion;
  int numero_casos;
  int i=0;
  while (aux!=nullptr){
    comuna= aux->get_comuna();
	nombre= comuna->get_nombre_comuna();
    longitud= comuna->get_longitud();
    latitud= comuna->get_latitud();
    cantidad_poblacion=comuna->get_cantidad_poblacion();
    numero_casos= comuna->get_numero_casos();
    hoja=new nodo_arbol(nombre,longitud,latitud,longitud,latitud,cantidad_poblacion,numero_casos);
	hojas[i++]=*hoja;
    aux=aux->get_next();
  }
}
void casos_confirmado_nacional(Arbol* dual_tree){ //RF1
   cout<<"Casos confirmado a nivel nacional: " <<dual_tree->get_raiz()->get_numero_casos()<<endl;
}
void casos_confirmado_nivel(Arbol* dual_tree){//RF2
  
}
void casos_confirmados_puntos(Arbol* dual_tree){//RF3

}
void porcentaje_casos (Arbol* dual_tree){//RF4

}

int main() {
  Lista_comunas* comunas = new Lista_comunas();
  Arbol* dual_tree = new Arbol();
  nodo_arbol* hojas;
  leerComunas("comunas.txt", comunas);
  leerCasos("casos.txt",comunas);
  comunas->ordenar_latitud();
  hojas= new nodo_arbol [comunas->get_tamano()];
  formacion_hojas(comunas, hojas);
  dual_tree->insertar(hojas,comunas->get_tamano());
  //###############inicio test#####################################
  cout<<"Son: "<<comunas->get_cantidad_poblacion()<<endl;//RF1
  cout<<"Me da: " <<dual_tree->get_raiz()->get_cantidad_poblacion()<<endl;
  cout<<dual_tree->get_raiz()->get_latitud1()<<endl;
  cout<<dual_tree->get_raiz()->get_latitud2()<<endl;
  cout<<dual_tree->get_raiz()->get_longitud1()<<endl;
  cout<<dual_tree->get_raiz()->get_longitud2()<<endl;
  cout<<"Son: "<<comunas->get_numero_casos()<<endl;
  cout<<"Me da: " <<dual_tree->get_raiz()->get_numero_casos()<<endl;
  dual_tree->CasosConfirmados(7);// RF2
  //#################fin test######################################
}