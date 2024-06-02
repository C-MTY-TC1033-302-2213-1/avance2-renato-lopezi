
/*
Renato Lopez
A01640057
ITC
26/05/2024
*/

#include "Polimorfismo.h"

using namespace std;

// Constructor default vacio
Polimorfismo::Polimorfismo(){
    for (int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }

    // Inicializar cantidad de videos
    cantidad = 0;
}


// Metodos modificadores
void Polimorfismo::setPtrVideo(int index, Video *video){
    // validar index >=0 && < cantidad
    if(index >= 0 && index < cantidad){
        // cambiar modificar el apuntador
        arrPtrVideos[index] = video;
    }
}

// cambia el valor del atributo cantidad
// cantidad debe ser entre 0 y MAX_VIDEOS -1, de lo contrario NO se modifica el valor del cantidad
void Polimorfismo::setCantidad(int _cantidad){
    // validar el valor de _cantidadVideos
    if(_cantidad >= 0 && _cantidad <= MAX_VIDEOS){
        cantidad = _cantidad;
    }
}


// Metodos de acceso
Video* Polimorfismo::getPtrVideo(int index){
    // validar que exista el index
    if(index >= 0 && index < cantidad){
        return arrPtrVideos[index];
    }

    //si no existe 
    return nullptr;
}
int Polimorfismo::getCantidad(){
    return cantidad;
}


// Otros metodos
void Polimorfismo::reporteInventario(){
    // Declaracion de contadores
    int contPeliculas, contSeries;

    // inicializar
    contPeliculas = 0;
    contSeries = 0;

    // recorrer todo el arreglo de ptr usando un for
    for(int index = 0; index < cantidad; index++){
        cout << arrPtrVideos[index] -> str() << endl;

        // * indireccion (ptr) genera el objeto
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            contPeliculas++;
        }
        else if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            contSeries++;
        }

    }

    // fuera del for - desplegar los totales 
    cout << "Peliculas = " << contPeliculas << endl;
    cout << "Series = " << contSeries << endl;
}

void Polimorfismo::reporteCalificacion(double _calificacion){
    // contador total
    int total;

    // inicializar contador
    total = 0;

    for (int index = 0; index < cantidad; index++){
        // verificar si tiene la calificacion == _calificacion
        if(arrPtrVideos[index]->getCalificacion() == _calificacion){
            cout << arrPtrVideos[index] -> str() << endl;
            total++;
        }
    }

    // desplegar el total fuera del for
    cout << "Total = " << total << endl;
}

void Polimorfismo::reporteGenero(string _genero){
    // contador total
    int total;
    
    // inicializar contador
    total = 0;

    for (int index = 0; index < cantidad; index++){
        // verificar si tiene el genero == _genero
        if(arrPtrVideos[index]->getGenero() == _genero){
            cout << arrPtrVideos[index] -> str() << endl;
            total++;
        }
    }

    // desplegar el total fuera del for
    cout << "Total = " << total << endl;
}

void Polimorfismo::reportePeliculas(){
    // Declaracion de contador
    int contPeliculas;

    // inicializar
    contPeliculas = 0;

    // recorrer todo el arreglo de ptr usando un for
    for(int index = 0; index < cantidad; index++){

        // * indireccion (ptr) genera el objeto
        if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
            cout << arrPtrVideos[index] -> str() << endl;
            contPeliculas++;
        }
    }

    // fuera del for - desplegar el total peliculas si hay
    if(contPeliculas > 0){
        cout << "Total Peliculas = " << contPeliculas << endl;
    }
    else{
        cout << "No peliculas" << endl; 
    }

}

void Polimorfismo::reporteSeries(){
    // Declaracion de contador
    int contSeries;

    // inicializar
    contSeries = 0;

    // recorrer todo el arreglo de ptr usando un for
    for(int index = 0; index < cantidad; index++){

        // * indireccion (ptr) genera el objeto
        if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
            cout << arrPtrVideos[index] -> str() << endl;
            contSeries++;
        }
    }

    // fuera del for - desplegar el total series si hay
    if(contSeries > 0){
        cout << "Total Series = " << contSeries << endl;
    }
    else{
        cout << "No series" << endl; 
    }
}


void Polimorfismo::leerArchivo(string nombre){
    Serie *arrPtrSeries[50];
    Pelicula *arrPtrPeliculas[50];
    Episodio episodio;
    fstream entrada;
    string row[7];
    string line, word;
    int cantidadPeliculas = 0;
    int cantidadSeries = 0;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in);

    while (getline(entrada, line)) {
        stringstream s(line);
        iR = 0;

        while (getline(s, word, ',')){
            row[iR++] = word;
        }

        if (row[0] == "P"){
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula( row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            //std::cout << "Pelicula " << arrPtrPeliculas[cantidadPeliculas] -> str() << endl;
            cantidadPeliculas++;
        }
        else if (row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            //std::cout << "Serie " << arrPtrSeries[cantidadSeries] -> str() << endl;
            cantidadSeries++;
        }
        else if (row[0] == "E"){
            index = stoi(row[1])-500;

            arrPtrSeries[index]->agregaEpisodio(*(new Episodio( row[2], stoi(row[3]), stoi(row[4]))));
            //std::cout << "Episodio " << arrPtrSeries[index] -> str() << endl;
        }
    }

    for(int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index] -> calculaPromedio();
        arrPtrSeries[index]->setCalificacion(promedio); 
        arrPtrSeries[index] -> calculaDuracion();
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

    for(int index = 0; index < cantidadPeliculas; index++){
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

    /*
    for(int index = 0; index < cantidadVideos; index++){
        std::cout << index << " " << arrPtrVideos[index] -> str() << endl;
    }
    */
   
    entrada.close();

}
