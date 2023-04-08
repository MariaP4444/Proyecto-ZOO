//
// Created by Lenovo on 31/03/2023.
//

#ifndef PROYECTO_ZOO_ANIMAL_H
#define PROYECTO_ZOO_ANIMAL_H

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/* ATRIBUTOS
 *
 * Nombre: nombre del animal
 * Especie: tipo de especie
 * estadoDeSalud: estado de salud del animal
 * alimentacion: tipo de alimentacion del animal (carnivora, herbivora, omnivora)
 * id: identificacion unica del animal
 * edad: edad del animal
 * tempMaxA: temperatura maxima adecuada para el animal
 * tempMinA: temperatura minima adecuada para el animal
 * cantHorasDormidas: horas dormidas en el dia
 * cantMaxDormir: cantidad limite de horas que puede dormir un animal
 * jugar: booleano que indica si el animal ha jugado en el dia
 * comer: booleano que indica si el animal ha comido en el dia
 * juguetes: vector tipo string que guarda los juguetes del animal
 * alimentos: mapa no ordenado que relaciona un tipo de alimento con una cantidad
 * estos son los alimentos de la dieta del animal
 */
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
    vector<string> juguetes;
    unordered_map<string, int> alimentos;

public:
    Animal() = default;

    Animal(string nombre, string especie, string estadoDeSalud, int id, int tempMaxA, int tempMinA,
           int cantHorasDormidas, int cantMaxDormir, bool jugar, bool comer, int edad, vector<string> juguetes, string alimentacion);


    bool getComer();

    void setComer(bool comer);

    bool getJugar();

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

    void menuAnimal(vector<string> dietaCarnivora, vector<string> dietaHerbivora);

    void elegirAlim(string tipoAlim);

    unordered_map<string, int> getAlimentos();

    void setAlimentos(unordered_map<string, int> alimentos);

    bool eliminarJuguetes(string jugueteElimanar);

    void editarAlimento();

    void interactAnimal(string opc);

    void comiendo(string nombre);

    void jugando(string nombre);

    void durmiendo();

    bool existeAlim(string alimento);

    void mostrarMapAlimentacion();
    void mostrarJuguetes();

    void agregarAlimentoaMap(vector<string> listaAlimetos );
    void agregarAlimentoaMapOmnivoro(vector<string> dieta1,vector<string> dieta2);
    bool eliminarAlimento(string alimento);
};


#endif //PROYECTO_ZOO_ANIMAL_H
