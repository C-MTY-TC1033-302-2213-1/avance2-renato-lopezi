
/*
Renato Lopez
A01640057
ITC
26/05/2024

La clase `Episodio` enseña los principios básicos de la programación orientada a objetos en C++, 
incluyendo la definición de clases, encapsulamiento mediante atributos privados y métodos públicos (getters y setters), 
y el uso de constructores para inicializar objetos. También demuestra el uso de guardas de inclusión (`#ifndef`, `#define`, `#endif`) 
para prevenir la inclusión múltiple de archivos de encabezado.
*/

#ifndef Episodio_h
#define Episodio_h

#include <string>
using namespace std;

class Episodio{

// Atributos
private:
    string titulo;
    int temporada;
    int calificacion;

// Publico
public:

// Constructores
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);

// Modificadores
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);

// Acceso 
    string getTitulo();
    int getTemporada();
    int getCalificacion();

// Otros
    string str();

};

#endif