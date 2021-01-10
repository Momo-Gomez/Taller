class nodo_arbol
{
    nodo_arbol *comuna1;
    nodo_arbol *comuna2;
    double longitud1;
    double latitud1;
    double longitud2;
    double latitud2;
    int cantidad_poblacion;
    int numero_casos;

public:
    nodo_arbol()
    {
        longitud1 = 0;
        latitud1 = 0;
        longitud2 = 0;
        latitud2 = 0;
        cantidad_poblacion = 0;
        numero_casos = 0;
        comuna1 = nullptr;
        comuna2 = nullptr;
    }
    nodo_arbol(double longitud1, double latitud1, double longitud2, double latitud2, int cantidad_poblacion, int numero_casos)
    {
        this->longitud1 = longitud1;
        this->latitud1 = latitud1;
        this->longitud2 = longitud2;
        this->latitud2 = latitud2;
        this->cantidad_poblacion = cantidad_poblacion;
        this->numero_casos = numero_casos;
        comuna1= nullptr;
        comuna2=nullptr;
    }
    double get_longitud1()
    {
        return longitud1;
    }
    double get_longitud2()
    {
        return longitud2;
    }
    double latitud1()
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
    void set_comuna1(nodo_arbol *comuna1)
    {
        this->comuna1 = comuna1;
    }
    void set_comuna2(nodo_arbol *comuna2)
    {
        this->comuna2 = comuna2;
    }
};