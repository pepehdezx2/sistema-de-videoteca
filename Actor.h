//  A01381334 José Antonio Hernández Hernández
//  Actor.h
//  avanceproyecto
//
//  Created by Jose Antonio on 02/03/18.
//  Copyright © 2018 Jose Antonio. All rights reserved.
//

#ifndef Actor_h
#define Actor_h
using namespace std;
class Actor{
public:
    // declaracion de metodos a utilizar en el encabezado...
    Actor();
    Actor(int ident, string nom);
    void setId(int ident);
    void setNombre(string nom);
    int getId();
    string getNombre();
private:
    // declaracion de atributos a utilizar en el encabezado...
    int identificacion;
    string nombre;
};
// constructores de clase...
Actor::Actor(){
    identificacion=0;
    nombre=" ";
}
Actor::Actor(int ident, string nom){
    identificacion=ident;
    nombre=nom;
}
// definir metodos de modificacion...
void Actor::setId(int ident){
    identificacion=ident;
}
void Actor::setNombre(string nom){
    nombre=nom;
}
// definir metodos de acceso...
int Actor::getId(){
    return identificacion;
}
string Actor::getNombre(){
    return nombre;
}

#endif /* Actor_h */
