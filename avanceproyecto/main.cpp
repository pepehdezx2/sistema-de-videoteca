//  A01381334 José Antonio Hernández Hernández
//  main.cpp
//  proyecto2
//
//  Created by Jose Antonio on 02/03/18.
//  Copyright © 2018 Jose Antonio. All rights reserved.
//  algoritmos
//  declaracion de variables, archivos, objetos y arreglos
//  abrir dos archivos de entrada y leerlos totalmente con un while loop hasta que terminen, cortar cada que se encuentre un renglon excepto al string final
//  do while loop que pregunta al usuario si quiere crear funciones, de ser asi crea estas hasta que el usuario no quiere mas
//  imprimir opciones en la pantalla
//  do while loop que recibe lo que quiera hacer el usuario y depende la seleccion realizara esa tara
//  cerrar archivos

#include <iostream>
#include <string>
#include <fstream>
#include "Hora.h"
#include "Pelicula.h"
#include "Funcion.h"
#include "Actor.h"
using namespace std;
int main() {
    // declaracion de variables...
    int cvea[10];
    int seguir, sala, cont, act=0, gc=0, func=0, cve, cact, year, dura, ho, num, min, hob, minb, idact, band, w;
    string gen, nomact, tit, continuar, fcve;
    char casos;
    // declaracion de objetos...
    Hora hora, horb;
    Pelicula p;
    Pelicula arrp[20];
    Funcion arrf[20];
    Actor arra[20];
    // declaracion de archivos de entrada...
    ifstream archivoentrada("Actores.txt");
    ifstream archivoentradb("Peliculas.txt");
    // ciclo que lee el archivo de actores...
    while (!archivoentrada.eof()){
        archivoentrada >> cact;
        archivoentrada.ignore();
        getline(archivoentrada, nomact);
        arra[act].setId(cact);
        arra[act].setNombre(nomact);
        act++;
    }
    // ciclo que lee el archivo de peliculas...
    while(!archivoentradb.eof()){
        archivoentradb >> cve;
        archivoentradb >> year;
        archivoentradb >> dura;
        archivoentradb >> gen;
        archivoentradb >> cact;
        for (int i=0; i<cact; i++){
            archivoentradb >> cvea[i];
        }
        archivoentradb.ignore();
        getline (archivoentradb, tit);
        arrp[gc].setnumPeli(cve);
        arrp[gc].setYear(year);
        arrp[gc].setDuracion(dura);
        arrp[gc].setGenero(gen);
        arrp[gc].setcantActores(cact);
        for (int i=0; i<cact; i++){
        arrp[gc].addActor(cvea[i]);
        }
        arrp[gc].setTitulo(tit);
        gc++;
        }
    // do while loop que crea funciones con sus respectivos parametros incluyendo horas...
    do{
        cout << "agregaras alguna funcion (si/no)" << endl;
        cin >> continuar;
        if (continuar=="si"){
            cout << "ingresa el numero de la pelicula" << endl;
            cin >> cve;
            band=0;
            for (int i=0; i<gc; i++){
                if(cve==arrp[i].getnumPeli()){
                    band=1;
                    i=20;
                }
                while(band==0){
                    cout << "no esta en la lista, dame otra clave" << endl;
                    cin >> cve;
                }
            }
            cout << "cual sera la clave para la funcion" << endl;
            cin >> fcve;
            for (int i=0; i<20; i++){
                if (fcve==arrf[i].getcveFuncion()){
                    band=0;
                }
                cout << "esa clave ya esta utilizada use otra" << endl;
                cin >> fcve;
            }
            cout << "ingresa la hora de la función";
            cin >> ho;
            while(ho<0 || ho>23){
                cout << "ingresa una hora valida";
                cin >> ho;
            }
            cout << "ingresa los minutos de la función: ";
            cin >> min;
            while(min<0 || min>59){
                cout << "ingresa minutos validos" << endl;
                cin >> min;
            }
            horb.setHoras(ho);
            horb.setMinutos(min);
            cout << "sala donde sera la funcion";
            cin >> sala;
            arrf[func].setcveFuncion(fcve);
            arrf[func].setnumPeli(cve);
            arrf[func].setSala(sala);
            arrf[func].setHora(horb);
            func++;
        }
        // imprimir opciones para el usuario...
    } while(continuar=="si");
    cout << "Presiona A para consultar todos los actores que estan en la lista" << endl;
    cout << "Presiona B para consultar todas las peliculas que estan en la lista" << endl;
    cout << "Presiona C para consultar todas las funciones disponibles" << endl;
    cout << "Presiona D para consultar funciones por hora" << endl;
    cout << "Presiona E para consultar por clave de funcion" << endl;
    cout << "Presiona F para consultar la lista de peliculas en las que participa un actor" << endl;
    // do while loop que lee los casos y hace lo que el usaurio pide...
    do{
        cin >> casos;
        switch (casos){
                case 'A':
                // funcion que imprime todos los actores en la lista...
                for(int i=0; i<act ; i++){
                    cout << arra[i].getId() << " " << arra[i].getNombre() << endl;
                }
                seguir=1;
                break;
                case 'B':
                // funcion que imprime las peliculas en la lista...
                for(int i=0; i<gc; i++){
                    cact=arrp[i].getcantActores();
                    cout << arrp[i].getTitulo() << " " << arrp[i].getYear() << " " << arrp[i].getDuracion() << " " << arrp[i].getGenero() << endl;
                    for (int c=0; c<cact; c++){
                        idact=arrp[i].getlistActores(c);
                        for (int x=0; x<act; x++){
                            if (idact==arra[x].getId()){
                                nomact=arra[x].getNombre();
                        cout << nomact << " ";
                            }
                        }
                    }
                }
                cout << endl;
                seguir=1;
                break;
                case 'C':
                // funcion que imprime todas las funciones que hay...
                for (int i=0; i<func; i++){
                    cout << arrf[i].getcveFuncion() << " ";;
                    cve=arrf[i].getnumPeli();
                    for (int i=0; i<gc; i++){
                        if(cve==arrp[i].getnumPeli()){
                            cout << arrp[i].getTitulo() << " ";
                        }
                    }
                    hora=arrf[i].getHora();
                    cout << arrf[i].getSala() << " " << hora.getHoras() << ":" << hora.getMinutos() << endl;
                }
                seguir=1;
                break;
                case 'D':
                // funcion que busca por medio de las horas que habra funciones...
                cout << "horas que desea buscar" << endl;
                cin >> ho;
                while(ho>23 || ho<0){
                    cout << "introduzca una hora valida" << endl;
                    cin >> ho;
                }
                cout << "minuto que desea buscar" << endl;
                cin >> min;
                while(min>59 || min<0){
                    cout << "introduzca un minuto valido" << endl;
                    cin >> min;
                }
                for (int i=0; i<func; i++){
                    hob=arrf[i].getHora().getHoras();
                    minb=arrf[i].getHora().getMinutos();
                    if (ho==hob && min==minb){
                        num=arrf[i].getnumPeli();
                        for (int c=0; c<gc; c++){
                            if(num==arrp[i].getnumPeli()){
                                p=arrp[c];
                                cout << "la pelicula " << p.getTitulo() << " en la sala " << arrf[i].getSala() << endl;
                                cont=0;
                            }
                            else{
                                cont=1;
                            }
                        }
                        if (cont==1){
                            cout << "a esa hora no hay funciones" << endl;
                        }
                    }
                }
                seguir =1;
                break;
                case 'E':
                // funcion que busca por la clave de la funcion las peliculas...
                cout << "ingresa la clave de la funcion" << endl;
                cin >> fcve;
                for (int i=0; i<func; i++){
                    if(fcve==arrf[i].getcveFuncion()){
                        hora=arrf[i].getHora();
                        cve=arrf[i].getnumPeli();
                        for (int c=0; c<gc; c++){
                            if(cve==arrp[c].getnumPeli()){
                                w=c;
                                c=20;
                            }
                        }
                        cout << arrf[i].getSala() << " " << arrp[w].getTitulo() << " " << hora.getHoras() << ":" << hora.getMinutos() << " " << arrp[w].getGenero() << " ";
                        cact=arrp[w].getcantActores();
                        for (int t=0; t<cact; t++){
                            idact=arrp[w].getlistActores(t);
                            for (int m=0; m<act; m++){
                                if (idact==arra[m].getId()){
                                    cout << arra[m].getNombre() << " ";
                                }
                            }
                        }
                    }
                }
                cout << endl;
                seguir=1;
                break;
                case 'F':
                // funcion que busca por id actor imprime su nombre y peliculas donde ha salido...
                cout << "id del actor a buscar" << endl;
                cin >> idact;
                for (int i=0; i<act; i++){
                    if(idact==arra[i].getId()){
                        cout << arra[i].getNombre() << " ";
                        for (int c=0; c<gc; c++){
                            cact=arrp[c].getcantActores();
                            for (int m=0; m<cact; m++){
                                if (idact==arrp[c].getlistActores(m)){
                                    cout << arrp[c].getTitulo() << " ";
                                }
                        }
                    }
                    cout << "no existe el actor dame otro" << endl;
                    cin >> idact;
                
                    }
                }
                seguir=1;
                break;
                case 'G':
                seguir=0;
        }
    }while (seguir!=0);
    // cerrar archivos de entrada...
    archivoentrada.close();
    archivoentradb.close();
    return 0;
    }
