#include <iostream>
#include "Nodo_arbol.cpp"
#include <math.h>
using namespace std;

class Arbol // arbol que agrupa las comunas
{
    nodo_arbol *raiz;

public:
    Arbol()
    {
        raiz = nullptr;
    }
    void insertar(nodo_arbol *aux, int tamaño)// recibe un arreglo de nodo_arbol ya formado en el main con las hojas
    {
        raiz = formar_arbol(aux,tamaño); // funcion recursiva para que solo quede un sector y este sea la raiz
    }
    nodo_arbol* get_raiz(){
      return raiz;
    }
private:
    nodo_arbol *formar_arbol(nodo_arbol *aux, int tamaño) // forma el arbol desde las hojas
    {
        int k = -1; //contador de llenado nuevo arreglo;
        double longitud_mayor;
        double longitud_menor;
        double latitud_mayor;
        double latitud_menor;         
        if (tamaño >1)           // condicion de salida el arreglo es de largo 1
        {
            nodo_arbol *aux2 = new nodo_arbol[tamaño / 2];// forma un nuevo arreglo de mitad de tamaño asumiendo que las comunas son pares.
            nodo_arbol *nn;
            for (int i = 0; i < tamaño; i++)
            {
                if (!aux[i].get_usado())// 
                {
                    nodo_arbol *menor= &aux[i+1];// caso base de menor distancia
                    for (int j = 0; j < tamaño; j++)
                    {
                        if (!aux[j].get_usado())
                        {
                            if(es_menor(aux[i], aux[j], *menor)){
                              *menor = aux[j];
                            }
                        }
                    }
                    menor->set_usado(true); // cuando termia el ciclo ponemos al menor como usado;
                    if (aux[i].get_longitud1()<menor->get_longitud1()){//casos para seleccionar extremos
                        longitud_menor=aux[i].get_longitud1();
                    }else{
                       longitud_menor= menor->get_longitud1();
                       }
                     if (aux[i].get_longitud2()>menor->get_longitud2()){
                        longitud_mayor=aux[i].get_longitud2();
                    }else{
                       longitud_mayor= menor->get_longitud2();
                       }
                    if (aux[i].get_latitud1()>menor->get_latitud1()){
                        latitud_mayor=aux[i].get_latitud1();
                    }else{
                      latitud_mayor= menor->get_latitud1();;
                       }
                    if (aux[i].get_latitud2()<menor->get_latitud2()){
                        latitud_menor=aux[i].get_latitud2();
                    }else{
                      latitud_menor= menor->get_latitud2();;
                       }
                    nn = new nodo_arbol(longitud_menor,latitud_mayor,longitud_mayor,latitud_menor, aux[i].get_cantidad_poblacion() + menor->get_cantidad_poblacion(), aux[i].get_numero_casos() + menor->get_numero_casos());
                    nn->set_nodo_izquierdo(&aux[i]);
                    nn->set_nodo_derecho(menor);
                    aux2[++k] = *nn;// guarda los grupos creados en un nuevo arreglo
                }
            }
            aux = formar_arbol(aux2,tamaño/2); //llamada recursiva con el nuevo arreglo
        }
        return aux;
    }
    bool es_menor(nodo_arbol aux, nodo_arbol aux2, nodo_arbol menor)
    {
        double distancia1;
        double distancia2;
        if (aux.get_latitud1() == aux.get_latitud2() && aux.get_longitud1() == aux.get_longitud2())//primer iteracion para comunas
        {
            distancia1 = sqrt(pow(aux.get_latitud1() - aux2.get_latitud1(),2) + pow(aux.get_longitud1() -aux2.get_latitud1(),2));
            distancia2 = sqrt(pow(aux.get_latitud1() - menor.get_latitud1(),2) + pow(aux.get_longitud1() - menor.get_longitud1(),2));
            
        }
        else
        { /* se busca el punto medio de las latitides y longitudes para dejar solo un valor de latitud y longitud para cada nodo ingresado*/
            double punto_medio_aux_latitud = (aux.get_latitud1() - aux.get_latitud2())/2;
            double punto_medio_aux_longitud= (aux.get_longitud1()-aux.get_latitud2())/2;
            double punto_medio_aux2_latitud = (aux.get_latitud1() - aux.get_latitud2())/2;
            double punto_medio_aux2_longitud= (aux.get_longitud1()-aux.get_latitud2())/2;
            double punto_medio_menor_latitud = (aux.get_latitud1() - aux.get_latitud2())/2;
            double punto_medio_menor_longitud= (aux.get_longitud1()-aux.get_latitud2())/2;
            distancia1 = sqrt(pow(punto_medio_aux_latitud - punto_medio_aux2_latitud,2) + pow(punto_medio_aux_longitud -punto_medio_aux2_longitud,2));
            distancia2 = sqrt(pow(punto_medio_aux_latitud - punto_medio_menor_latitud,2) + pow(punto_medio_aux_latitud - punto_medio_menor_latitud,2));
        }

    if (distancia1<distancia2){//si es menor retorna verdadero en caso contrario falso
        return true;
    }
    return false;
    }
    
};
