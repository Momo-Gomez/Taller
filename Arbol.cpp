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
    void insertar(nodo_arbol *arreglo, int tamano) // recibe un arreglo de nodo_arbol ya formado en el main con las hojas
    {
        raiz = formar_arbol(arreglo, tamano, 1); // funcion recursiva para que solo quede un sector y este sea la raiz
    }
    nodo_arbol *get_raiz()
    {
        return raiz;
    }
    void CasosConfirmados(int nivel)
    {
        cout <<"Nivel numero "<<nivel<< endl;
        mostrar(raiz, nivel);
    }

private:
    void mostrar(nodo_arbol *node, int nivel)
    {
        if (node != nullptr)
        {
            if (nivel == 0)
            {
                cout << "Sector: "<<node->get_nombre() << endl;
                cout<<"Cantidad de casos: "<< node->get_numero_casos()<<endl;
                if(node->get_nodo_derecho()!=nullptr){
                    cout<<"##########################################################################"<<endl;
                    cout << "Subsector 1: "<<node->get_nodo_izquierdo()->get_nombre() << endl;
                    cout<<"Cantidad de casos: "<< node->get_nodo_izquierdo()->get_numero_casos()<<endl;
                    cout << "Subsector 2: "<<node->get_nodo_derecho()->get_nombre() << endl;
                    cout<<"Cantidad de casos: "<< node->get_nodo_derecho()->get_numero_casos()<<endl;
                    cout<<"##########################################################################"<<endl;
                }

            }
            mostrar(node->get_nodo_izquierdo(), nivel - 1);
            mostrar(node->get_nodo_derecho(), nivel - 1);
        }
    }
    nodo_arbol *formar_arbol(nodo_arbol *arreglo, int tamano, int sector) // forma el arbol desde las hojas
    {
        int k = 0; //contador de llenado nuevo arreglo;
        double longitud_mayor;
        double longitud_menor;
        double latitud_mayor;
        double latitud_menor;
        double distancia;
        if (tamano > 1) // condicion de salida el arreglo es de largo 1
        {
            nodo_arbol *nuevo_arreglo = new nodo_arbol[tamano / 2]; // forma un nuevo arreglo de mitad de tamano asumiendo que las comunas son pares.
            nodo_arbol *nuevo_nodo;
            for (int i = 0; i < tamano - 1; i++)
            {
                distancia = 9999;
                nodo_arbol *menor_distancia;
                if (!arreglo[i].get_usado())
                {
                    menor_distancia = &arreglo[i + 1]; // caso base de menor distancia
                    for (int j = i + 1; j < tamano; j++)
                    {
                        if (!arreglo[j].get_usado())
                        {
                            if (es_menor(&arreglo[i], &arreglo[j], &distancia)) //aqui voy
                            {
                                menor_distancia = &arreglo[j];
                            }
                        }
                    }
                    menor_distancia->set_usado(true); // cuando termia el ciclo ponemos al menor como usado;
                    if (arreglo[i].get_longitud1() < menor_distancia->get_longitud1())
                    { //casos para seleccionar extremos
                        longitud_menor = arreglo[i].get_longitud1();
                    }
                    else
                    {
                        longitud_menor = menor_distancia->get_longitud1();
                    }
                    if (arreglo[i].get_longitud2() > menor_distancia->get_longitud2())
                    {
                        longitud_mayor = arreglo[i].get_longitud2();
                    }
                    else
                    {
                        longitud_mayor = menor_distancia->get_longitud2();
                    }
                    if (arreglo[i].get_latitud1() > menor_distancia->get_latitud1())
                    {
                        latitud_mayor = arreglo[i].get_latitud1();
                    }
                    else
                    {
                        latitud_mayor = menor_distancia->get_latitud1();
                        ;
                    }
                    if (arreglo[i].get_latitud2() < menor_distancia->get_latitud2())
                    {
                        latitud_menor = arreglo[i].get_latitud2();
                    }
                    else
                    {
                        latitud_menor = menor_distancia->get_latitud2();
                    }
                    nuevo_nodo = new nodo_arbol(to_string(sector++), longitud_menor, latitud_mayor, longitud_mayor, latitud_menor, arreglo[i].get_cantidad_poblacion() + menor_distancia->get_cantidad_poblacion(), arreglo[i].get_numero_casos() + menor_distancia->get_numero_casos());
                    nuevo_nodo->set_nodo_izquierdo(&arreglo[i]);
                    nuevo_nodo->set_nodo_derecho(menor_distancia);
                    nuevo_arreglo[k++] = *nuevo_nodo; // guarda los grupos creados en un nuevo arreglo
                }
            }
            arreglo = formar_arbol(nuevo_arreglo, tamano / 2, sector); //llamada recursiva con el nuevo arreglo
        }
        return arreglo;
    }
    bool es_menor(nodo_arbol *nodo_base, nodo_arbol *nodo_comparacion, double *menor_distancia_encontrada)
    {
        double distancia1;
        double distancia2;
        if (nodo_base->get_latitud1() == nodo_base->get_latitud2() && nodo_base->get_longitud1() == nodo_base->get_longitud2()) //primer iteracion para comunas
        {
            distancia1 = sqrt(pow(nodo_base->get_latitud1() - nodo_comparacion->get_latitud1(), 2) + pow(nodo_base->get_longitud1() - nodo_comparacion->get_longitud1(), 2));
        }
        else
        { /* se busca el punto medio de las latitides y longitudes para dejar solo un valor de latitud y longitud para cada nodo ingresado*/
            double punto_medio_base_latitud = nodo_base->get_latitud1() - ((nodo_base->get_latitud1() - nodo_base->get_latitud2()) / 2);
            double punto_medio_base_longitud = nodo_base->get_longitud2() - ((nodo_base->get_longitud2() - nodo_base->get_longitud1()) / 2);
            double punto_medio_comparacion_latitud = nodo_comparacion->get_latitud1() - ((nodo_comparacion->get_latitud1() - nodo_comparacion->get_latitud2()) / 2);
            double punto_medio_comparacion_longitud = nodo_comparacion->get_longitud2() - ((nodo_comparacion->get_longitud2() - nodo_comparacion->get_longitud1()) / 2);
            distancia1 = sqrt(pow(punto_medio_base_latitud - punto_medio_comparacion_latitud, 2) + pow(punto_medio_base_longitud - punto_medio_comparacion_longitud, 2));
        }

        if (distancia1 < *menor_distancia_encontrada)
        { //si es menor retorna verdadero en caso contrario falso
            *menor_distancia_encontrada = distancia1;
            return true;
        }
        return false;
    }
};
