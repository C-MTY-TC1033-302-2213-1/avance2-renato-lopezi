
/*
Renato Lopez
A01640057
ITC
26/05/2024

El código define una clase `Polimorfismo` en C++ que gestiona un arreglo de punteros 
a objetos `Video`, incluyendo episodios, 
películas y series mediante herencia y polimorfismo. Incluye un constructor y un 
método para leer archivos, probablemente para llenar el arreglo con datos leídos de 
un archivo. Utiliza técnicas para evitar múltiples inclusiones del archivo de encabezado 
y depende de varias bibliotecas estándar de C++ y otros archivos de encabezado que definen 
las clases específicas de video.
*/

#ifndef Polimorfismo_h
#define Polimorfismo_h

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>

#include "Video.h"
#include "Episodio.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Polimorfismo.h"


const int MAX_VIDEOS = 100;

class Polimorfismo{
private:   
    Video *arrPtrVideos[MAX_VIDEOS];
    int cantidad;

public:

    // Constructor default - vacio
    Polimorfismo();

    void leerArchivo(string nombre);

    // Metodos modificadores
    void setPtrVideo(int index, Video *video);
    void setCantidad(int _cantidad);

    // Metodos de acceso
    Video* getPtrVideo(int index);
    int getCantidad();

    // Otros metodos
    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();

};


#endif

