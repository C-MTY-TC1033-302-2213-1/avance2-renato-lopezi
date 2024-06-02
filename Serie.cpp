
/*
Renato Lopez
A01640057
ITC
26/05/2024
*/

#include "Serie.h"


// Metodo constructor
Serie::Serie():Video(){
    cantidad = 0;
}
Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion )
    :Video(_iD, _titulo, _duracion, _genero, _calificacion){
}

// Metodo calcula duracion
void Serie::calculaDuracion() {
    // Declaracion de la duracion total
    int duracionTotal;

    // Inicializar
    duracionTotal = 0;

    // Ciclo for para contar los episodios totales
    for (int index = 0; index < cantidad; index++){
        duracionTotal += episodios[index].getTemporada();
    }
    duracion = duracionTotal;
}


// Metodos modificadores
void Serie::setEpisodio(int posicion, Episodio episodio){
    // Primero validar si existe ese episodio
    if(posicion >= 0 && posicion < cantidad){
        episodios[posicion] = episodio;

    }

}

// Cambiar el valor del atributo cantidad con el nuevo valor recibido
void Serie::setCantidad(int _cantidad){
    cantidad = _cantidad;
}


// Metodos de acceso
Episodio Serie::getEpisodio(int posicion){
    // Crea un objeto de tipo episodio y lo inicializa con el contstructor default
    Episodio epi;

    if(posicion >=0 && posicion < cantidad){
        return episodios[posicion];
    }

    // Si no existe se retorna un default
    return epi;
}

// Retorna el valor del atributo cantidad
int Serie::getCantidad(){
    return cantidad;
}

// Otros
double Serie::calculaPromedio(){
    double acum = 0;

    for(int index = 0; index < cantidad; index++){
        acum = acum + episodios[index].getCalificacion();
    }

    // validar que tenga episodios
    if(cantidad > 0){
        return acum / cantidad;
    }
    else {
        return 0;
    }
}

// Otros métodos
string Serie::str(){
    string serieConcatenado = iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero + ' ' + to_string(calificacion) + ' ' + to_string(cantidad);
    if (cantidad > 0) {
        string episodiosConcatenado;
        for (int i = 0; i < cantidad; i++) {
            episodiosConcatenado =  episodiosConcatenado + '\n' + episodios[i].getTitulo() + ' ' + to_string(episodios[i].getTemporada()) + ' ' + to_string(episodios[i].getCalificacion());
        }
        return serieConcatenado + episodiosConcatenado + '\n';
    }
    return '\n' + serieConcatenado + '\n';
}

// Agrega un episodio solo si existe espacio
void Serie::agregaEpisodio(Episodio episodio){
    if(cantidad < 5){
        episodios[cantidad++] = episodio;
    }
}
