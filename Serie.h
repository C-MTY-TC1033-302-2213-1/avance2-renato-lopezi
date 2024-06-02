
/*
Renato Lopez
A01640057
ITC
26/05/2024

Programar la clase `Serie` enseña conceptos clave de la programación orientada a objetos en C++, 
como la herencia al derivar de la clase `Video` y la composición al incluir objetos de tipo `Episodio`. 
Demuestra cómo definir y utilizar arreglos de objetos, encapsulando atributos y proporcionando métodos públicos 
(getters y setters) para acceder y modificar estos datos. Además, introduce la implementación de métodos 
específicos como `calculaPromedio` para operaciones adicionales y `agregaEpisodio` para manejar dinámicamente 
los episodios de la serie. El uso de guardas de inclusión (`#ifndef`, `#define`, `#endif`) asegura que los archivos 
de encabezado no se incluyan múltiples veces.
*/

#ifndef Serie_h
#define Serie_h

// Para herencia
#include "Video.h"

// Para composicion
#include "Episodio.h"


class Serie: public Video{

private:
    Episodio episodios [5];
    int cantidad;

public:
    // Metodo constructor
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion );

    // Metodo calcular duracion
    void calculaDuracion();

    // Metodos modificadores
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

    // Metodos de acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();

    // Otros
    double calculaPromedio();

    string str();

    void agregaEpisodio(Episodio episodio);

};

#endif