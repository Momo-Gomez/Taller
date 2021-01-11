#include <iostream>
#include "Nodo_arbol.cpp"
#include <math.h>
using namespace std;
class arbol
{
    nodo_arbol *raiz;

public:
    arbol()
    {
        raiz = nullptr;
    }
    void insertar(nodo_arbol *aux)
    {
        raiz = formar_arbol(aux);
    }
private:
    nodo_arbol *formar_arbol(nodo_arbol *aux)
    {
        int tamaño = sizeof(aux); //tamaño del arreglo de sectores agrupados;
        int k = -1;               //contador de llenado nuevo arreglo;
        if (tamaño > 1)           // en la ultima iteracion la posicion 2 estar usada y no entrara;
        {
            nodo_arbol *aux2 = new nodo_arbol[tamaño / 2];
            nodo_arbol *nn;
            for (int i = 0; i < tamaño - 1; i++)
            {
                if (!aux[i].get_usado())
                {
                    nodo_arbol *menor = &aux[i + 1]; // caso base de menor distancia
                    for (int j = 0; j < tamaño; j++)
                    {
                        if (!aux[j].get_usado())
                        {
                            if (es_menor(aux[i], aux[j], *menor))
                            {
                                menor = &aux[j];
                            }
                        }
                    }
                    menor->set_usado(true); // cuando termia el ciclo ponemos al menor como usado;
                    nn = new nodo_arbol(aux[i].get_longitud1(), menor->get_latitud1(), aux[i].get_longitud2(), menor->get_latitud2(), aux[i].get_cantidad_poblacion() + menor->get_cantidad_poblacion(), aux[i].get_numero_casos() + menor->get_numero_casos());
                    nn->set_nodo_izquierdo(&aux[i]);
                    nn->set_nodo_derecho(menor);
                    aux2[++k] = *nn;
                }
            }
            aux = formar_arbol(aux2);
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
        {
            double punto_medio_aux_latitud = (aux.get_latitud1() - aux.get_latitud2())/2;
            double punto_medio_aux_longitud= (aux.get_longitud1()-aux.get_latitud2())/2;
            double punto_medio_aux2_latitud = (aux.get_latitud1() - aux.get_latitud2())/2;
            double punto_medio_aux2_longitud= (aux.get_longitud1()-aux.get_latitud2())/2;
            double punto_medio_menor_latitud = (aux.get_latitud1() - aux.get_latitud2())/2;
            double punto_medio_menor_longitud= (aux.get_longitud1()-aux.get_latitud2())/2;
            distancia1 = sqrt(pow(punto_medio_aux_latitud - punto_medio_aux2_latitud,2) + pow(punto_medio_aux_longitud -punto_medio_aux2_longitud,2));
            distancia2 = sqrt(pow(punto_medio_aux_latitud - punto_medio_menor_latitud,2) + pow(punto_medio_aux_latitud - punto_medio_menor_latitud,2));
        }

    if (distancia1<distancia2){
        return true;
    }
    return false;
    }

};
