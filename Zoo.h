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
    bool zooNoVacio;
    vector<Habitat*> habitats;
    vector<string> dietaCarnivora;
    vector<string> dietaHerbivora;
public:
    Zoo() = default;


    bool habitatRepetido(string nombre);
    void registrarHabitat(string nombre, int tMin, int tMax);

    vector<string> getCarnivoro();
    void setCarnivoro(vector<string> dietaCarnivora);

    vector<string> getHerbivoro();
    void setHerbivoro(vector<string> dietaHerbivora);

    bool getZooNoVacio();
    void setZooVacio(bool zooNoVacio);

    int getCantAnimales();
    void setCantAnimales(int cantAnimales);

    string getNombre();
    void setNombre(string nombre);

    bool exieteHabitatTemp(int temMax, int  temMin);
    vector<string> listaHabitatsDisponibles(int temMax, int  temMin);

    Habitat* devolverPunteroVec(string nombre);

    void listarHabitatsConAnimales();



};


#endif //PROYECTO_ZOO_ZOO_H
