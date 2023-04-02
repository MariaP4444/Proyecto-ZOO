

#include <iostream>
#include "Habitat.h"
#include "Zoo.h"
using namespace std;

void primeraOpcion(Zoo* pZoo){
    string nombre;
    int tMin, tMax;

    cout << "Ingrese nombre del habitat " << endl;
    cin.ignore();
    getline(cin, nombre, '\n');
    cout << "Ingrese la temperatura minima del habitat " << endl;
    cin >> tMin;
    cout << "Ingrese la temperatura maxima del habitat " << endl;
    cin >> tMax;

    for(char& c : nombre){
        c = std::tolower(c);
    }

    pZoo->registrarHabitat(nombre, tMin, tMax);

}

void mostrarMenu(Zoo* pZoo) {
    int id, opc, cantAnimales = 0;

    do
    {
        cout << "\n** Zoo MAVA\n";
        cout << "1. Agregar habitat\n";
        cout << "2. Lista de habitats y animales\n";

        if(pZoo->getZooVacio() == false){
            cout << "3. Agregar animal\n";
            cout << "4. Modificar informacion de animal\n";
            cout << "5. Visitar habitat \n";
            cout << "0. Salir\n" << endl;
        }

        cin >> opc;

        switch (opc)
        {
            case 1:
                primeraOpcion(pZoo);
                id++;
                break;
            case 2:
                //segundaOpcion();
                //Zoo->mostrarInfo();

                break;
            case 3:

                break;
            case 4:


                break;
            case 5:


                break;
            default:
                break;
        }
    } while (opc != 0);
}

int main() {

    Zoo* pZoo = new Zoo();
    mostrarMenu(pZoo);
    delete pZoo;
    return 0;

}

/*
vector<Habitat*>::iterator itVectorHab;

for (itVectorHab = this->animales.begin(); itVectorHab != this->animales.end(); ++itVectorHab){
Habitat* HabitatTemp = *itVectorHab;
HabitatTemp->mostrarAnimales;
}
*/