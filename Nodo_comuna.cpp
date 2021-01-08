#include <iostream>
#include "Comuna.cpp"
using namespace std;
class Nodo_comuna
{
    Comuna *comuna;
    Nodo_comuna *next;

public:
    Nodo_comuna()
    {
        comuna = nullptr;
        next = nullptr;
    }
    Nodo_comuna(Comuna *comuna)
    {
        this->comuna = comuna;
        next = nullptr;
    }
    void set_next(Nodo_comuna *next)
    {
        this->next = next;
    }
    void set_comuna(Comuna* comuna){
        this->comuna= comuna;
    }
    Comuna *get_comuna()
    {
        return comuna;
    }
    Nodo_comuna *get_next()
    {
        return next;
    }
};