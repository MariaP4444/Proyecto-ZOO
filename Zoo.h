//
// Created by Lenovo on 31/03/2023.
//

#ifndef PROYECTO_ZOO_ZOO_H
#define PROYECTO_ZOO_ZOO_H

#include <iostream>
#include <string>
#include <cctype>
#include "Habitat.h"
#include <vector>

using namespace std;

/* Clase contenedora del proyecto
 * ATRIBUTOS
 * - Nombre: Nombre del zoologico
 * - cantAnimales: contador de animales dentro del zoologico, este sirve para asignarles un ID a los animales para poder identificarlos
 * - zooVacio: booleano que nos ayudara a saber si por lo menos existe un habitat
*/
class Zoo {
private:
    string nombre;
    int cantAnimales;
    bool zooVacio;
    vector<Habitat*> habitats;
public:
    Zoo() = default;

    bool habitatRepetido(string nombre);
    void registrarHabitat(string nombre, int tMin, int tMax);

    bool getZooVacio();
    void setZooVacio(bool zooVacio);

    int getCantAnimales();
    void setCantAnimales(int cantAnimales);

    string getNombre();
    void setNombre(string nombre);

};


#endif //PROYECTO_ZOO_ZOO_H
