//  A01381334 José Antonio Hernández Hernández
//  Pelicula.h
//  avanceproyecto
//
//  Created by Jose Antonio on 02/03/18.
//  Copyright © 2018 Jose Antonio. All rights reserved.
//

#ifndef Pelicula_h
#define Pelicula_h
using namespace std;
class Pelicula{
public:
    // declaracion de metodos a utilizar en el encabezado...
    Pelicula();
    Pelicula(int npel, string tit, int y, int dura, string gen, int cact);
    void setnumPeli(int npel);
    void setTitulo(string tit);
    void setYear(int y);
    void setDuracion(int dura);
    void setGenero(string gen);
    void setcantActores(int cact);
    int getnumPeli();
    string getTitulo();
    int getYear();
    int getDuracion();
    string getGenero();
    int getcantActores();
    int getlistActores(int n);
    bool addActor(int act);
private:
    // declaracion de atributos a utilizar en el encabezado...
    int numPeli, year, duracion, cantact, i;
    int arra[10];
    string titulo, genero;
};
// constructores de clase...
Pelicula::Pelicula(){
    numPeli=0;
    year=0;
    duracion=0;
    cantact=0;
    titulo=" ";
    genero=" ";
}
Pelicula::Pelicula(int npel, string tit, int y, int dura, string gen, int cact){
    numPeli=npel;
    titulo=tit;
    year=y;
    duracion=dura;
    genero=gen;
    cantact=cact;
}
// definir metodos de modificacion...
void Pelicula::setnumPeli(int npel){
    numPeli=npel;
}
void Pelicula::setTitulo(string tit){
    titulo=tit;
}
void Pelicula::setYear(int y){
    year=y;
}
void Pelicula::setDuracion(int dura){
    duracion=dura;
}
void Pelicula::setGenero(string gen){
    genero=gen;
}
void Pelicula::setcantActores(int cact){
    cantact=cact;
}
// definir metodos de acceso...
int Pelicula::getnumPeli(){
    return numPeli;
}
string Pelicula::getTitulo(){
    return titulo;
}
int Pelicula::getYear(){
    return year;
}
int Pelicula::getDuracion(){
    return duracion;
}
string Pelicula::getGenero(){
    return genero;
}
int Pelicula::getcantActores(){
    return cantact;
}
int Pelicula::getlistActores(int n){
    i=n;
    return arra[i];
}
// definicion de metodo tipo booleano para agrerar un actor...
bool Pelicula::addActor(int act){
    bool add = 1;
    if(cantact != 10){
        for(int i=0; i<cantact; i++){
            if(arra[i]==act){
                add=0;
                i=cantact;
            }
        }
    }
    else {
        add=false;
    }
    if(add){
        arra[cantact--]=act;
        cantact++;
    }
    return add;
}


#endif /* Pelicula_h */
