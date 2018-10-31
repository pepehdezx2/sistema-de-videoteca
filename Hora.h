//  A01381334 José Antonio Hernández Hernández
//  Hora.h
//  avanceproyecto
//
//  Created by Jose Antonio on 02/03/18.
//  Copyright © 2018 Jose Antonio. All rights reserved.
//

#ifndef Hora_h
#define Hora_h
using namespace std;
class Hora{
public:
    // declaracion de metodos a utilizar en el encabezado...
    Hora();
    Hora(int horas,int minutos);
    void setHoras(int horas);
    void setMinutos(int minutos);
    int getHoras();
    int getMinutos();
private:
    // declaracion de atributos a utilizar en el encabezado...
    int hh, mm;
};
// constructores de clase...
Hora::Hora(){
    hh=0;
    mm=0;
}
Hora::Hora(int horas, int minutos){
    hh=horas;
    mm=minutos;
}
// definir metodos de modificacion...
void Hora::setHoras(int horas){
    hh=horas;
}
void Hora::setMinutos(int minutos){
    mm=minutos;
}
// definir metodos de acceso...
int Hora::getHoras(){
    return hh;
}
int Hora::getMinutos(){
    return mm;
}
#endif /* Hora_h */
