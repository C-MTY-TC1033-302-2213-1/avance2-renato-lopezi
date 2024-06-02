
/*
Renato Lopez
A01640057
ITC
26/05/2024

Programar la clase `Video` enseña los fundamentos de la programación orientada a objetos en C++, 
incluyendo la definición de clases con atributos protegidos para encapsulación y la creación de 
constructores (por defecto y con parámetros) para inicializar objetos. Se aprende a implementar métodos 
modificadores (setters) y de acceso (getters) para manipular y obtener los valores de los atributos, 
así como a definir métodos adicionales como `str` para obtener una representación en cadena del objeto. 
También se practica el uso de guardas de inclusión (`#ifndef`, `#define`, `#endif`) para prevenir 
múltiples inclusiones del archivo de encabezado.
*/

#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>
using namespace std;

class Video{

// Atributos
protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;

// Metodos
public:

    // Constructores
    Video();
    Video(string _iD, string _titulo, int _duracion, 
    string _genero, double _calificacion);

    // Modificadores
    void setId(string _iD);
    void setNombre(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);

    // Acceso
    string getId();
    string getNombre();
    int getDuracion();
    string getGenero();
    double getCalificacion();

    // Otros
    virtual string str();

};

#endif

