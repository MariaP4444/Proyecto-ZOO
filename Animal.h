//
// Created by Lenovo on 31/03/2023.
//

#ifndef PROYECTO_ZOO_ANIMAL_H
#define PROYECTO_ZOO_ANIMAL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
private:
    string nombre;
    string especie;
    string estadoDeSalud;
    string alimentacion;
    int id;
    int edad;
    int tempMaxA;
    int tempMinA;
    int cantHorasDormidas;
    int cantMaxDormir;
    bool jugar;
    bool comer;
    vector <string> jugetes;
    vector <string> alimentos;
public:
    Animal() = default;
    Animal(string nombre, string especie, string estadoDeSalud, int id, int tempMaxA, int tempMinA, int cantHorasDormidas, int cantMaxDormir, bool jugar, bool comer, int edad);
    vector<string> getJugetes();
    void agregarJugete(string juegueteNuevo);

    bool getComer();
    void setComer(bool comer);

    bool getJugar() ;
    void setJugar(bool jugar);

    int getCantMaxDormir();
    void setCantMaxDormir(int cantMaxDormir);

    int getCantHorasDormidas();
    void setCantHorasDormidas(int cantHorasDormidas);

    int getTempMinA();
    void setTempMinA(int tempMinA);

    int getTempMaxA();
    void setTempMaxA(int tempMaxA);

    int getEdad();
    void setEdad(int edad);

    int getId();
    void setId(int id);

    string getEstadoDeSalud();
    void setEstadoDeSalud(string estadoDeSalud);

    string getEspecie();
    void setEspecie(string especie);

    string getNombre();
    void setNombre(string nombre);

    string getAliemtacion();
    void setAliemtacion(string aliemtacion);

    void menuAnimal(string nombre);

    void elegirAlim(int tipoAlim);


};


#endif //PROYECTO_ZOO_ANIMAL_H
