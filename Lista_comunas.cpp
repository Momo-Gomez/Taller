#include <iostream>
#include "Nodo_comuna.cpp"
using namespace std;
class Lista_comunas
{
    Nodo_comuna *first;

public:
    bool isEmpty()
    {
        return first == NULL;
    }

    void ingresar_comuna_txt(string nombre_comuna, double longitud, double latitud)
    {
        Nodo_comuna *nn = new Nodo_comuna(new Comuna(nombre_comuna, longitud, latitud));

        if (!isEmpty())
        {
            nn->set_next(first);
        }
        first = nn;
    }
    void ingresar_casos_txt ( string nombre_comuna, int cantidad_poblacion, int numero_casos){
        Nodo_comuna* aux= first;
        while (aux!=nullptr){
            Comuna* comuna= aux->get_comuna();
            if (comuna->get_nombre_comuna()== nombre_comuna){
              comuna->set_cantidad_poblacion(cantidad_poblacion);
              comuna->set_numero_casos(numero_casos);
              break;
            }
            aux=aux->get_next();
        }
    }
    void ordenar() // supuestamente ordena de mayor a menor, mayor latitud es mas al norte (creo)
    {
        Nodo_comuna *actual = first;
        Nodo_comuna *siguiente = actual->get_next();
        Comuna *c;
        while (actual->get_next() != nullptr)
        {
            while (siguiente != nullptr)
            {
                if (actual->get_comuna()->get_latitud() < siguiente->get_comuna()->get_latitud())
                {
                    c = actual->get_comuna();
                    actual->set_comuna(siguiente->get_comuna());
                    siguiente->set_comuna(c);
                }
                siguiente = siguiente->get_next();
            }
            actual = actual->get_next();
            siguiente = actual->get_next();
        }
    }
    void mostrar()
    {
        Nodo_comuna *aux = first;
        while (aux != nullptr)
        {
            cout << aux->get_comuna()->get_latitud();
            aux->get_next();
        }
    }
    Nodo_comuna *getfirst()
    {
        return first;
    }
};