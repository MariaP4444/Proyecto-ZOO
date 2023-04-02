//
// Created by Lenovo on 31/03/2023.
//

#include "Zoo.h"
/*
void Zoo::registrarHabitat(int id, string nombre, string sexo, string nacimiento, string hospital, string origen){

    Habitat* pHabitat = new Habitat(nombre, tMin, tMax);
    this->habitats.insert(make_pair(id, pHabitat));
}

*/

bool Zoo::habitatRepetido(string nombre){
    vector<Habitat*>::iterator itVectorHa;

    for (itVectorHa = this->habitats.begin(); itVectorHa != this->habitats.end(); ++itVectorHa){
        Habitat* habitatTemp = *itVectorHa;
        if(nombre == habitatTemp->getNombre()){
            return true;
        }
    }
    return false;
}

void Zoo::registrarHabitat(string nombre, int tMin, int tMax){
    if(this->habitatRepetido(nombre)){
    cout << "Este habitat ya existe " << endl;
    }
    else{
    Habitat* pHabitat = new Habitat(nombre, tMin, tMax);
    this->habitats.push_back(pHabitat);
    this->setZooVacio(false);

}

bool Zoo::getZooVacio() {
    return this->zooVacio;
}

void Zoo::setZooVacio(bool zooVacio){
    Zoo::zooVacio = zooVacio;
}

int Zoo::getCantAnimales() {
    return this->cantAnimales;
}

void Zoo::setCantAnimales(int cantAnimales) {
    Zoo::cantAnimales = cantAnimales;
}

string Zoo::getNombre(){
    return this->nombre;
}

void Zoo::setNombre(string nombre) {
    Zoo::nombre = nombre;
}
