
/*
Renato Lopez
A01640057
ITC
26/05/2024
*/

#include "Episodio.h"


// Constructores
Episodio::Episodio(){
    titulo = "Herencia";
    temporada = 1;
    calificacion = 100;
}
Episodio::Episodio(string _titulo, int _temporada, int _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}

// Modificadores
void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}
void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}
void Episodio::setCalificacion(int _calificacion){
    calificacion = _calificacion;
}

// Acceso 
string Episodio::getTitulo(){
    return titulo;
}
int Episodio::getTemporada(){
    return temporada;
}
int Episodio::getCalificacion(){
    return calificacion;
}

// Otros
string Episodio::str(){
    return titulo + ' ' + to_string(temporada) + ' ' + to_string(calificacion);
}

