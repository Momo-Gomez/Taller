#include <iostream>
using namespace std;
class Comuna
{
    string nombre_comuna;
    double longitud;
    double latitud;
    int cantidad_poblacion;
    int numero_casos;

public:
    Comuna()
    {
        nombre_comuna = "";
        longitud = -1;
        latitud = -1;
        cantidad_poblacion = -1;
        numero_casos = -1;
    }
    Comuna(string nombre_comuna, double longitud, double latitud)
    {
        this->nombre_comuna = nombre_comuna;
        this->longitud = longitud;
        this->latitud = latitud;
        this->cantidad_poblacion = -1;
        this->numero_casos = -1;
    }
    string get_nombre_comuna()
    {
        return nombre_comuna;
    }
    double get_longitud()
    {
        return longitud;
    }
    double get_latitud()
    {
        return latitud;
    }
    int get_cantidad_poblacion()
    {
        return cantidad_poblacion;
    }
    int get_numero_casos()
    {
        return numero_casos;
    }
    void set_cantidad_poblacion(int cantidad_poblacion){
      this->cantidad_poblacion=cantidad_poblacion;
    }
    void set_numero_casos (int numero_casos){
      this->numero_casos=numero_casos;
    }
};