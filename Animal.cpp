//
// Created by Lenovo on 31/03/2023.
//

#include "Animal.h"

Animal::Animal(string nombre, string especie, string estadoDeSalud, int id, int tempMaxA, int tempMinA,
               int cantHorasDormidas, int cantMaxDormir, bool jugar, bool comer, int edad, vector<string> juguetes, string alimentacion)
        : nombre(nombre), especie(especie), estadoDeSalud(estadoDeSalud), id(id), tempMaxA(tempMaxA),
          tempMinA(tempMinA), cantHorasDormidas(cantHorasDormidas), cantMaxDormir(cantMaxDormir), jugar(jugar),
          comer(comer), edad(edad), juguetes(juguetes), alimentacion(alimentacion){}

string convertidorStringMinuscula3(string palabra){
    for(char& c : palabra){
        c = std::tolower(c);
    }
    return palabra;
}

string Animal::getNombre() {
    return this->nombre;
}

void Animal::setNombre(string nombre) {
    Animal::nombre = nombre;
}

string Animal::getEspecie() {
    return this->especie;
}

void Animal::setEspecie(string especie) {
    Animal::especie = especie;
}

string Animal::getEstadoDeSalud() {
    return this->estadoDeSalud;
}

void Animal::setEstadoDeSalud(string estadoDeSalud) {
    Animal::estadoDeSalud = estadoDeSalud;
}

string Animal::getAliemtacion() {
    return this->alimentacion;
}

void Animal::setAliemtacion(string alimentacion) {
    Animal::alimentacion = alimentacion;
}

int Animal::getId() {
    return this->id;
}

void Animal::setId(int id) {
    Animal::id = id;
}

int Animal::getTempMaxA() {
    return this->tempMaxA;
}

void Animal::setTempMaxA(int tempMaxA) {
    Animal::tempMaxA = tempMaxA;
}

int Animal::getTempMinA() {
    return this->tempMinA;
}

void Animal::setTempMinA(int tempMinA) {
    Animal::tempMinA = tempMinA;
}

int Animal::getCantHorasDormidas() {
    return this->cantHorasDormidas;
}

void Animal::setCantHorasDormidas(int cantHorasDormidas) {
    Animal::cantHorasDormidas = cantHorasDormidas;
}

int Animal::getCantMaxDormir() {
    return this->cantMaxDormir;
}

void Animal::setCantMaxDormir(int cantMaxDormir) {
    Animal::cantMaxDormir = cantMaxDormir;
}

bool Animal::getJugar() {
    return this->jugar;
}

void Animal::setJugar(bool jugar) {
    Animal::jugar = jugar;
}

bool Animal::getComer() {
    return this->comer;
}

void Animal::setComer(bool comer) {
    Animal::comer = comer;
}

int Animal::getEdad() {
    return this->edad;
}

void Animal::setEdad(int edad) {
    Animal::edad = edad;
}

bool Animal::eliminarJuguetes(string jugueteElimanar) {
    if(find(this->juguetes.begin(),this->juguetes.end(),jugueteElimanar)!= this->juguetes.end()){
        this->juguetes.erase(find(this->juguetes.begin(),this->juguetes.end(),jugueteElimanar));
        return true;
    }
    else{
        return false;
    }
}

int aseguradorDeCantAlimetos(){
    int cantidadComidad;
    do{
        cout << "Por favor ingrese la cantidad de Kg que come el animal del alimento: " << endl;
        cin >> cantidadComidad;
    }while(cantidadComidad<= 0);

    return cantidadComidad;
}

void Animal::editarAlimento() {
    unordered_map <string, int>::iterator itMapA;
    int kg = 0;

    for (itMapA = this->alimentos.begin(); itMapA != this->alimentos.end(); ++itMapA) {
        int opc = 0;

        cout << "  Alimento: " << itMapA->first << endl;
        cout << "  Kg: " << itMapA->second << endl;
        cout << "------------------------------------" << endl;

        while(opc != 1 && opc != 2){

            cout << "1.Editar" << endl;
            cout << "2.Guardar" << endl;
            cin >> opc;

        }
        if (opc == 1) {
            itMapA->second = aseguradorDeCantAlimetos();

        }
    }
}

void Animal::menuAnimal() {
    int opc, edad, hDormir,cantJuguetes;
    string salud,jugueteNom, jugueteEliminar;
    do {
        cout << "\n** Seleccine el dato a cambiar\n";
        cout << "1. Edad\n";
        cout << "2. Estado de salud\n";
        cout << "3. Horas de suenio maximas\n";
        cout << "4. Cantidad de kg en dieta\n";
        cout << "5. Agregar juguetes\n";
        cout << "6. Eliminar juguete\n";
        cout << "0. Guardar y salir\n";

        cin >> opc;

        switch (opc) {
            case 1:
                do {
                    cout << "Ingrese la nueva edad del animal: " << endl;
                    cin >> edad;
                }while(edad < this->edad || edad > 100);
                this->setEdad(edad);
                cout << "Ahora la edad del animal es de"<<this->getEdad() << endl;
                break;
            case 2:
                cin.ignore();
                cout << "Ingrese el estado actual de salud del animal: " << endl;
                getline(cin, salud, '\n');
                salud = convertidorStringMinuscula3(salud);
                this->setEstadoDeSalud(salud);
                cout << "Ahora el estado de salud  del animal es de"<<this->getEstadoDeSalud()<< endl;
                break;
            case 3:
                do {
                    cout << "Ingrese las nuevas horas de sueño del animal: " << endl;
                    cin >> hDormir;
                }while(hDormir <= 0);
                this->setCantMaxDormir(hDormir);
                cout << "Ahora las horas de sueno del animal es de"<<this->getCantMaxDormir() << endl;
                break;
            case 4:
                editarAlimento();
                cout << "Ya se edito con exito las porciones de alimentos" << endl;
                break;

            case 5:

                do {
                    cout << "Ingrese el numero de juguetes que va agregar a la lista del animal: " << endl;
                    cin >> cantJuguetes;
                }while(cantJuguetes <= 0);

                cin.ignore();
                while(cantJuguetes > 0){
                    cout << " - Ingrese ingrese el nombre del juguete: " << endl;
                    getline(cin, jugueteNom, '\n');
                    jugueteNom= convertidorStringMinuscula3(jugueteNom);
                    this->juguetes.push_back(jugueteNom);
                    cantJuguetes--;
                }
                cout << "Se agrego corectamente los/el jueguete/s" << endl;
                break;
            case 6:
                cin.ignore();
                do {
                    cout << "Ingrese el nombre: " << endl;
                    getline(cin, jugueteEliminar, '\n');
                    jugueteEliminar = convertidorStringMinuscula3(jugueteEliminar);
                }while(!eliminarJuguetes(jugueteEliminar));
                cout << "Se elimino correctamente el juguete"<<jugueteEliminar << endl;
                break;
            default:
                break;
        }
    } while (opc != 0);
}

void Animal::jugando(string nombre) {
    int opc;
    cout << "**Juguetes de " << nombre << endl;

    for (int i = 0; i < this->juguetes.size(); i++) {
        cout << i+1 << ". " << juguetes[i] << endl;
    }

    do {
        cout << "Ingrese una opcion: " << endl;
        cin >> opc;
        opc -=1;
    }while(opc < 0 || opc > juguetes.size());

    cout << nombre << " esta jugando con su " << juguetes[opc] << endl;

}

bool Animal::existeAlim(string alimento) {
    unordered_map <string, int>::iterator itMapA;
    for (itMapA = this->alimentos.begin(); itMapA != this->alimentos.end(); ++itMapA) {
        if(itMapA->first == alimento){
            return true;
        }
    }
    cout << "Alimento no valido para el animal" << endl;
    return false;
}

void Animal::comiendo(string nombre) {
    string alimento;
    int kg;
    bool existe = false;

    while(!existe){
        cout << "Ingrese el alimento : " << endl;
        cin >> alimento;
        existe = existeAlim(alimento);
    }

    //Tal vez esto no es necesario
    do {
        cout << "Ingrese la cantidad de kilogramos de alimento: " << endl;
        cin >> kg;
    }while(kg != this->alimentos[alimento]);
    //

    cout << nombre << " esta comiendo " << kg << "kg de " << alimento << endl;
}


void Animal::interactAnimal(string opc) {
    string nombre = this->getNombre();
    int hDormir;

    if(opc == "jugar") {
        if(!jugar) {
            jugando(nombre);
            this->jugar = true;
        }
        else{
            cout << nombre <<" ya ha jugado el dia de hoy" << endl;
        }
    }
    else if(opc == "comer") {
        if(!comer) {
            comiendo(nombre);
            this->comer = true;
        }
        else{
            cout << nombre <<" ya ha comido el dia de hoy" << endl;
        }

    }
    else if(opc == "dormir") {
        if (cantHorasDormidas < cantMaxDormir) {
            do {
                cout << "Ingrese las nuevas horas de sueño del animal: " << endl;
                cin >> hDormir;
                if (this->cantMaxDormir < hDormir + this->cantHorasDormidas) {
                    cout << "Esta cantidad se excede del limite de suenio del animal " << endl;
                }
            } while (this->cantMaxDormir < hDormir + this->cantHorasDormidas);
            this->cantHorasDormidas += hDormir;
        }
        else{
            cout << nombre <<" ya ha dormido suficiente el dia de hoy" << endl;
        }
    }
    else {
        throw invalid_argument("Esta no es una actividad posible");
    }


}


void Animal::elegirAlim(string tipoAlim) {
    if (tipoAlim == "carnivoro") {
        cout << "- Res" << endl;
        this->alimentos.insert(make_pair("res", aseguradorDeCantAlimetos()));
        cout << "- Pollo" << endl;
        this->alimentos.insert(make_pair("pollo", aseguradorDeCantAlimetos()));
        cout << "- Pescado" << endl;
        this->alimentos.insert(make_pair("pescado", aseguradorDeCantAlimetos()));
    } else if (tipoAlim == "herbivoro") {
        cout << "- Frutas" << endl;
        this->alimentos.insert(make_pair("frutas", aseguradorDeCantAlimetos()));
        cout << "- Verduras" << endl;
        this->alimentos.insert(make_pair("Verduras", aseguradorDeCantAlimetos()));
        cout << "- Granos" << endl;
        this->alimentos.insert(make_pair("granos", aseguradorDeCantAlimetos()));
    } else if (tipoAlim == "omnivoro") {
        cout << "- Res" << endl;
        this->alimentos.insert(make_pair("res", aseguradorDeCantAlimetos()));
        cout << "- Pollo" << endl;
        this->alimentos.insert(make_pair("pollo", aseguradorDeCantAlimetos()));
        cout << "- Frutas" << endl;
        this->alimentos.insert(make_pair("frutas", aseguradorDeCantAlimetos()));
        cout << "- Verduras" << endl;
        this->alimentos.insert(make_pair("Verduras", aseguradorDeCantAlimetos()));
    }
}

unordered_map<string, int> Animal::getAlimentos() {
    return this->alimentos;
}

void Animal::setAlimentos(unordered_map<string, int> alimentos) {
    Animal::alimentos = alimentos;
}

void Animal::mostrarMapAlimentacion() {
    unordered_map<string, int>::iterator itMapP;
    int contador = 1;

    for (itMapP = this->alimentos.begin(); itMapP != this->alimentos.end(); ++itMapP){
        cout << "   -- ALIMENTO:"<< contador<< "--"<<endl;
        cout << "       Nombre: " << itMapP->first<< endl;
        cout << "       Cantidad de kg: " << itMapP->second<< endl;
        contador++;
    }
}








