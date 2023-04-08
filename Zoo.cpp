//
// Created by Lenovo on 31/03/2023.
//

#include "Zoo.h"


bool Zoo::getZooNoVacio() {
    return this->zooNoVacio;
}

void Zoo::setZooVacio(bool zoonNoVacio){
    Zoo::zooNoVacio = zoonNoVacio;
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

vector<string> Zoo::getCarnivoro(){
    return this->dietaCarnivora;
}

void Zoo::setCarnivoro(vector<std::string> dietaCarnivora) {
    Zoo::dietaCarnivora = dietaCarnivora;
}

vector<string> Zoo::getHerbivoro(){
    return this->dietaHerbivora;
}

void Zoo::setHerbivoro(vector<std::string> dietaHerbivora) {
    Zoo::dietaHerbivora = dietaHerbivora;
}

//Retorna un booleano que indica si el habitat ingresado ya existe
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

//Esta funcion comprueba si el habitat ingresado ya existe, esto cn el fin de evitar agregar habitats repetidos
// si no lo esta, lo agrega al vector "habitats" de Zoo
void Zoo::registrarHabitat(string nombre, int tMin, int tMax) {
    if (this->habitatRepetido(nombre)) {
        cout << "Este habitat ya existe " << endl;
    } else {
        Habitat *pHabitat = new Habitat(nombre, tMin, tMax);
        this->habitats.push_back(pHabitat);
        setZooVacio( true);

    }
}
//Retorna el puntero tipo habitat segun el nombre del habitat
Habitat* Zoo::devolverPunteroVec(string nombre){
    vector<Habitat*>::iterator itVectorHa;

    for (itVectorHa = this->habitats.begin(); itVectorHa != this->habitats.end(); ++itVectorHa){
        Habitat* habitatTemp = *itVectorHa;
        if(habitatTemp->getNombre() == nombre){
            return habitatTemp;
        }

    }
    return nullptr;
}

//Esta funcion imprime la informacion de cada habitat y la informacion de sus animales correspondientes
void Zoo::listarHabitatsConAnimales(){
    vector<Habitat*>::iterator itVectorHa;

    for (itVectorHa = this->habitats.begin(); itVectorHa != this->habitats.end(); ++itVectorHa){
        Habitat* habitatTemp = *itVectorHa;
        cout << "--------------------Habitat: " << habitatTemp->getNombre()<< "--------------------" << endl;
        cout << " - Temperatua maxima: " << habitatTemp->getTempMax() << endl;
        cout << " - Temperatua minima: " << habitatTemp->getTempMin() << endl;
        cout << "---------------------------------------------------------------" << endl;
        habitatTemp->infoCompletaAn();
    }
}


//Esta funcion recorre el vector de habitats para encontrar si hay algun habitat que se ajuste a
//la temperatura del animal
bool Zoo::exieteHabitatTemp(int temMax, int temMin) {
    vector<Habitat*>::iterator itVector;

    for (itVector = this->habitats.begin(); itVector != this->habitats.end(); ++itVector){
       if((*itVector)->getTempMax() <= temMax && (*itVector)->getTempMin() >= temMin){
           return true;
       }
    }
    return false;
}

//Esta funcion crea y retorna un vector con los nombres de los habitat que se ajusten al animal,
//esto para que el usuario no digite un habitat no adecuado para el animal
vector<string> Zoo::listaHabitatsDisponibles(int temMax, int  temMin){
    vector<Habitat*>::iterator itVector;
    vector<string> habitatsAnimal;

    for (itVector = this->habitats.begin(); itVector != this->habitats.end(); ++itVector){
        if((*itVector)->getTempMax() <= temMax && (*itVector)->getTempMin() >= temMin){
            habitatsAnimal.push_back((*itVector)->getNombre());
        }
    }
    return habitatsAnimal;
}



