//
// Created by Lenovo on 31/03/2023.
//

#ifndef PROYECTO_ZOO_ZOOLOGICO_H
#define PROYECTO_ZOO_ZOOLOGICO_H

#include <iostream>
#include <string>
#include "Habitat.h"
#include <vector>

using namespace std;

/* Clase contenedora del proyecto
 * ATRIBUTOS
 * - Nombre: Nombre del zoologico
 * - cantAnimales: contador de animales dentro del zoologico, este sirve para asignarles un ID a los animales para poder identificarlos
 * - existenHabitat: booleano que nos ayudara a saber si por lo menos existe un habitat
*/
class Zoologico {
private:
    string nombre;
    int cantAnimales;
    bool existenHabitat;
public:
    Zoologico() = default;


    bool getExistenHabitat();
    void setExistenHabitat(bool existenHabitat);

    int getCantAnimales();
    void setCantAnimales(int cantAnimales);

    string getNombre();
    void setNombre(string nombre);

};


#endif //PROYECTO_ZOO_ZOOLOGICO_H
