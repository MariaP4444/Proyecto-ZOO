//
// Created by Lenovo on 31/03/2023.
//

#ifndef PROYECTO_ZOO_HABITAT_H
#define PROYECTO_ZOO_HABITAT_H

#include <iostream>
#include <string>
#include "Animal.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

/* ATRIBUTOS
 * nombre: nombre del habitat
 * tempMax: temperatura maxima del habitat
 * tempMin: temperatura minima del habitat
 * animales: mapa no ordenado que guarda los punteros de los animales pertenecientes al habitat como valor
 * y los id de los animales como clave
 */

class Habitat {
private:
    string nombre;
    int tempMax;
    int tempMin;
    unordered_map <int, Animal*> animales;

public:
    Habitat()= default;
    Habitat(string nombre, int tempMax, int tempMin);

    int getTempMin();

    string getNombre();

    int getTempMax();

    Animal* devolverPunteroAn(int id);

    void listarAnimales();

    void infoCompletaAn();

    void agregarAnimal(int idAnimalNuevo, int tempMaxA, int tempMinA);

};


#endif //PROYECTO_ZOO_HABITAT_H
