//
// Created by Lenovo on 31/03/2023.
//

#ifndef PROYECTO_ZOO_HABITAT_H
#define PROYECTO_ZOO_HABITAT_H

#include <iostream>
#include <string>
#include "Animal.h"
#include <vector>

using namespace std;

class Habitat {
private:
    string nombre;
    int tempMax;
    int tempMin;
    vector <Animal*> animalesEnHabitat;

public:
    Habitat()= default;
    Habitat(string nombre, int tempMax, int tempMin);

    int getTempMin();
    void setTempMin(int tempMin);

    string getNombre();
    void setNombre(string nombre);

    int getTempMax();
    void setTempMax(int tempMax);

};


#endif //PROYECTO_ZOO_HABITAT_H
