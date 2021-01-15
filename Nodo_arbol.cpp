#include <iostream>
using namespace std;
class nodo_arbol
{
    nodo_arbol *nodo_izquierdo;
    nodo_arbol *nodo_derecho;
    string nombre;
    double longitud1;
    double latitud1;
    double longitud2;
    double latitud2;
    int cantidad_poblacion;
    int numero_casos;
    bool usado;

public:
    nodo_arbol()
    {
        longitud1 = 0;
        latitud1 = 0;
        longitud2 = 0;
        latitud2 = 0;
        cantidad_poblacion = 0;
        numero_casos = 0;
        nodo_izquierdo = nullptr;
        nodo_derecho = nullptr;
        usado = false;
    }
    nodo_arbol(string nombre, double longitud1, double latitud1, double longitud2, double latitud2, int cantidad_poblacion, int numero_casos)
    {
        this->longitud1 = longitud1;
        this->latitud1 = latitud1;
        this->longitud2 = longitud2;
        this->latitud2 = latitud2;
        this->cantidad_poblacion = cantidad_poblacion;
        this->numero_casos = numero_casos;
        nodo_izquierdo = nullptr;
        nodo_derecho = nullptr;
        usado = false;
        this->nombre = nombre;
    }
    double get_longitud1()
    {
        return longitud1;
    }
    double get_longitud2()
    {
        return longitud2;
    }
    double get_latitud1()
    {
        return latitud1;
    }
    double get_latitud2()
    {
        return latitud2;
    }
    int get_cantidad_poblacion()
    {
        return cantidad_poblacion;
    }
    int get_numero_casos()
    {
        return numero_casos;
    }
    bool get_usado()
    {
        return usado;
    }
    void set_nodo_izquierdo(nodo_arbol *nodo_izquierdo)
    {
        this->nodo_izquierdo = nodo_izquierdo;
    }
    void set_nodo_derecho(nodo_arbol *nodo_derecho)
    {
        this->nodo_derecho = nodo_derecho;
    }
    void set_usado(bool usado)
    {
        this->usado = usado;
    }
    nodo_arbol *get_nodo_izquierdo()
    {
        return nodo_izquierdo;
    }
    nodo_arbol *get_nodo_derecho()
    {
        return nodo_derecho;
    }
    string get_nombre()
    {
        return nombre;
    }
};