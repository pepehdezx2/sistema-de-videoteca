//  A01381334 José Antonio Hernández Hernández
//  Funcion.h
//  avanceproyecto
//
//  Created by Jose Antonio on 02/03/18.
//  Copyright © 2018 Jose Antonio. All rights reserved.
//

#ifndef Funcion_h
#define Funcion_h
#include"Hora.h"
using namespace std;
class Funcion{
public:
    // declaracion de metodos a utilizar en el encabezado...
    Funcion();
    Funcion(string cve, int numpel, Hora ho, int sal);
    void setcveFuncion(string cve);
    void setnumPeli(int numpel);
    void setHora(Hora ho);
    void setSala(int sal);
    string getcveFuncion();
    int getnumPeli();
    Hora getHora();
    int getSala();
private:
    // declaracion de atributos a utilizar en el encabezado...
    Hora hora;
    int numPeli, sala;
    string cveFuncion;
};
// constructores de clase...
Funcion::Funcion(){
    Hora horap(0, 0);
    hora=horap;
    numPeli=0;
    sala=0;
    cveFuncion=" ";
}
Funcion::Funcion(string cve, int numpel, Hora ho, int sal){
    cveFuncion=cve;
    numPeli=numpel;
    hora=ho;
    sala=sal;
}
// definir metodos de modificacion...
void Funcion::setcveFuncion(string cve){
    cveFuncion=cve;
}
void Funcion::setnumPeli(int numpel){
    numPeli=numpel;
}
void Funcion::setHora(Hora ho){
    hora=ho;
}
void Funcion::setSala(int sal){
    sala=sal;
}
// definir metodos de acceso...
string Funcion::getcveFuncion(){
    return cveFuncion;
}
int Funcion::getnumPeli(){
    return numPeli;
}
Hora Funcion::getHora(){
    return hora;
}
int Funcion::getSala(){
    return sala;
}

#endif /* Funcion_h */
