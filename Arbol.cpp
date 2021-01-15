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
    void insertar_hojas(nodo_arbol *arreglo, int tamano) // recibe un arreglo de nodo_arbol ya formado en el main con las hojas
    {
        raiz = formar_arbol(arreglo, tamano, 1); // funcion recursiva para que solo quede un sector y este sea la raiz
    }
    string casos_confirmados_nacional()
    {
        return to_string(raiz->get_numero_casos());
    }
    void casos_confirmados_nivel(int nivel)
    {
        cout << "Nivel numero " << nivel << endl;
        casos_confirmados_nivel(raiz, nivel);
    }
    void casos_confirmados_puntos(double longitud_mayor, double longitud_menor, double latitud_mayor, double latitud_menor)
    {
        cout << "----------------   COMUNAS PERTENECIENTES AL CUADRANTE INGRESADO  ----------------" << endl;
        casos_confirmados_puntos(raiz, longitud_mayor, longitud_menor, latitud_mayor, latitud_menor);
        cout << "----------------------------------   FIN   ---------------------------------------" << endl;
    }
    void porcentaje_casos_confirmados(){
        cout << "---------   PORCENTAJE DE CASOS CONFIRMADOS RESPECTO A LA POBLACION TOTAL  ---------" << endl;
        porcentaje_casos_confirmados(raiz);
        cout << "----------------------------------    FIN    --------------------------------------" << endl;
    }
    void comunas_rango_porcentaje(double porcentaje){
        cout << "---------   COMUNAS EN RANGO DE PORCENTAJE RESPECTO A LA POBLACION TOTAL  ---------" << endl;
        comunas_rango_porcentaje(raiz,porcentaje);
        cout << "----------------------------------    FIN    --------------------------------------" << endl;
    }

private:
    void comunas_rango_porcentaje(nodo_arbol* nodo,double porcentaje){ // aqui voy
        if (nodo != nullptr)
        {
            if (nodo->get_nodo_derecho() == nullptr)
            {
                {   
                    if (100*nodo->get_numero_casos()/nodo->get_cantidad_poblacion()<= porcentaje)
                    {
                        cout << "$-   "<<nodo->get_nombre() << endl;
                    }
                }
            }
            porcentaje_casos_confirmados(nodo->get_nodo_izquierdo());
            porcentaje_casos_confirmados(nodo->get_nodo_derecho());
        }
    }
    void porcentaje_casos_confirmados(nodo_arbol* nodo){
         if (nodo != nullptr)
        {
            if (nodo->get_nodo_derecho() == nullptr)
            {
                {   
                    cout<<"$-   "<<nodo->get_nombre()<< "    \t"<< (100*nodo->get_numero_casos()/nodo->get_cantidad_poblacion())<<"%"<<endl; 
                }
            }
            porcentaje_casos_confirmados(nodo->get_nodo_izquierdo());
            porcentaje_casos_confirmados(nodo->get_nodo_derecho());
        }
    }
    void casos_confirmados_puntos(nodo_arbol *nodo, double longitud_mayor, double longitud_menor, double latitud_mayor, double latitud_menor)
    {
        if (nodo != nullptr)
        {
            if (nodo->get_nodo_derecho() == nullptr)
            {
                {   
                    if (latitud_mayor >= nodo->get_latitud1() && latitud_menor <= nodo->get_latitud1() && longitud_menor <= nodo->get_longitud1() && longitud_mayor >= nodo->get_longitud1())
                    {
                        cout << "$-   "<<nodo->get_nombre() << endl;
                    }
                }
            }
            casos_confirmados_puntos(nodo->get_nodo_izquierdo(), longitud_mayor, longitud_menor, latitud_mayor, latitud_menor);
            casos_confirmados_puntos(nodo->get_nodo_derecho(), longitud_mayor, longitud_menor, latitud_mayor, latitud_menor);
        }
    }
    void casos_confirmados_nivel(nodo_arbol *nodo, int nivel)
    {
        if (nodo != nullptr)
        {
            if (nivel == 0)
            {
                cout << "---------------------------------" << endl;
                cout << "Sector: " << nodo->get_nombre()<<"\t\t\t|" << endl;
                cout << "Cantidad de casos: " << nodo->get_numero_casos()<<"\t|"  << endl;
                cout << "---------------------------------"<< endl;
                //MODIFICACION PROVISORIA
                //cout<< nodo->get_latitud1()<<" " << nodo->get_latitud2()<<" " << nodo->get_longitud2()<< " "<<nodo->get_longitud1()<<endl;  
                if (nodo->get_nodo_derecho() != nullptr)
                {
                    cout << "Subsector 1: " << nodo->get_nodo_izquierdo()->get_nombre()<<"\t\t|"  << endl;
                    cout << "Cantidad de casos: " << nodo->get_nodo_izquierdo()->get_numero_casos()<<"\t|" << endl;
                    cout << "Subsector 2: " << nodo->get_nodo_derecho()->get_nombre()<<"\t\t|"  << endl;
                    cout << "Cantidad de casos: " << nodo->get_nodo_derecho()->get_numero_casos()<<"\t|" << endl;
                    cout << "---------------------------------"<< endl;
                    cout << "\n\n\n\n";
                }
            }
            casos_confirmados_nivel(nodo->get_nodo_izquierdo(), nivel - 1);
            casos_confirmados_nivel(nodo->get_nodo_derecho(), nivel - 1);
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
                    menor_distancia = nullptr; // caso base de menor distancia
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
                    definicion_extremos_longitud(&arreglo[i], menor_distancia, &longitud_menor, &longitud_mayor);
                    definicion_extremos_latitud(&arreglo[i], menor_distancia, &latitud_menor, &latitud_mayor);
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
    void definicion_extremos_longitud(nodo_arbol *arreglo, nodo_arbol *menor_distancia, double *longitud_menor, double *longitud_mayor)
    {
        if (arreglo->get_longitud1() < menor_distancia->get_longitud1())
        { //casos para seleccionar extremos
            *longitud_menor = arreglo->get_longitud1();
        }
        else
        {
            *longitud_menor = menor_distancia->get_longitud1();
        }
        if (arreglo->get_longitud2() > menor_distancia->get_longitud2())
        {
            *longitud_mayor = arreglo->get_longitud2();
        }
        else
        {
            *longitud_mayor = menor_distancia->get_longitud2();
        }
    }
    void definicion_extremos_latitud(nodo_arbol *arreglo, nodo_arbol *menor_distancia, double *latitud_menor, double *latitud_mayor)
    {
        if (arreglo->get_latitud1() > menor_distancia->get_latitud1())
        {
            *latitud_mayor = arreglo->get_latitud1();
        }
        else
        {
            *latitud_mayor = menor_distancia->get_latitud1();
        }
        if (arreglo->get_latitud2() < menor_distancia->get_latitud2())
        {
            *latitud_menor = arreglo->get_latitud2();
        }
        else
        {
            *latitud_menor = menor_distancia->get_latitud2();
        }
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
