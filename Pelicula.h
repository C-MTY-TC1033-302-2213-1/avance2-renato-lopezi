
/*
Renato Lopez
A01640057
ITC
26/05/2024

La clase `Pelicula` enseña la herencia en C++ al derivar de la clase `Video`, 
mostrando cómo extender funcionalidades de una clase base. Demuestra encapsulamiento con atributos 
privados y métodos públicos (getters y setters), y el uso de constructores (por defecto y con parámetros) 
para inicializar objetos. Utiliza guardas de inclusión (`#ifndef`, `#define`, `#endif`) 
para evitar múltiples inclusiones del mismo archivo de encabezado.
*/

#ifndef Pelicula_h
#define Pelicula_h

#include "Video.h"
using namespace std;
#include <string>


// Clase pelicula es derivada de video
class Pelicula : public Video{
    private:
    int oscares;

    public:
    // Constructores
    Pelicula();
    Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion , int _oscares);

    // Metodo Modificador
    void setOscares(int _oscares);

    // Metodo Acceso
    int getOscares();

    // Otros metodos
    string str();

};

#endif