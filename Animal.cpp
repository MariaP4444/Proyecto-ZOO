//
// Created by Lenovo on 31/03/2023.
//

#include <limits>
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
        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }
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

            if(!cin.good()){
                throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
            }

        }
        if (opc == 1) {
            bool terminado = false;
            do {
                try {
                    itMapA->second = aseguradorDeCantAlimetos();
                    terminado = true;
                }
                catch (const invalid_argument error) {
                    cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    terminado = false;
                }
            }
            while(terminado == false);

        }
    }
}

bool buscarAlimentoenListaDieta(string alimento,vector<string> dieta){
    if(find(dieta.begin(),dieta.end(),alimento) != dieta.end()){
        return true;
    }
    else{
        return false;
    }
}

void Animal::agregarAlimentoaMap(vector<string> dieta) {
    string alimentoAgregar;
    if(this->alimentos.size()< dieta.size()){
        do{
            cout << "Ingrese el nombre del alimento:"<< endl;
            getline(cin, alimentoAgregar, '\n');
            alimentoAgregar = convertidorStringMinuscula3(alimentoAgregar);
            if(this->alimentos.count(alimentoAgregar)) {
                cout << "Este alimento ya esta agregado a la dieta del animal " << endl;
            }
        }while(!buscarAlimentoenListaDieta(alimentoAgregar,dieta) && !this->alimentos.count(alimentoAgregar));

        bool terminado = false;
        do {
            try {
                this->alimentos.insert(make_pair(alimentoAgregar,aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);

    }
    else{
        cout << " Al parecer el animal ya cuenta con la capacidad maxima de alimentos disponibles" << endl;
    }
}

void Animal::agregarAlimentoaMapOmnivoro(vector<string> dieta1,vector<string> dieta2) {
    string alimentoAgregar;
    if(this->alimentos.size()< dieta1.size()+ dieta2.size()){
        do{
            cout << "Ingrese el nombre del alimento:"<< endl;
            getline(cin, alimentoAgregar, '\n');
            alimentoAgregar = convertidorStringMinuscula3(alimentoAgregar);
            if(this->alimentos.count(alimentoAgregar)) {
                cout << "Este alimento ya esta agregado a la dieta del animal " << endl;
            }
        }while(!buscarAlimentoenListaDieta(alimentoAgregar,dieta1)&& !buscarAlimentoenListaDieta(alimentoAgregar,dieta2) && !this->alimentos.count(alimentoAgregar));

        bool terminado = false;
        do {
            try {
                this->alimentos.insert(make_pair(alimentoAgregar,aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);

    }
    else{
        cout << " Al parecer el animal ya cuenta con la capacidad maxima de alimentos disponibles" << endl;
    }
}

bool Animal::eliminarAlimento(string alimento) {
    if(this->alimentos.count(alimento)){
        this->alimentos.erase(alimento);
        cout << "Se ha eliminado: " << alimento << endl;
        return true;
    }
    else{
        cout << " No se ha encontrado el alimento que desea eliminar, vuelve a intentarlo" << endl;
        return false;
    }
}

void Animal::menuAnimal(vector<string> dietaCarnivora, vector<string> dietaHervivora) {
    int opc, edad, hDormir,cantJuguetes;
    string salud,jugueteNom, jugueteEliminar, alimentoEliminar;
    bool terminado = false;
    do {
        cout << "\n** Seleccine el dato a cambiar\n";
        cout << "1. Edad\n";
        cout << "2. Estado de salud\n";
        cout << "3. Horas de suenio maximas\n";
        cout << "4. Cantidad de kg en dieta\n";
        cout << "5. Agregar juguetes\n";
        cout << "6. Eliminar juguete\n";
        cout << "7. Agregar alimeto a la dieta del animal\n";
        cout << "8. Eliminar alimeto de la dieta del animal\n";
        cout << "0. Guardar y salir"<< endl;

        cin >> opc;
        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }

        switch (opc) {
            case 1:
                do {
                    cout << "Ingrese la nueva edad del animal: " << endl;
                    cin >> edad;

                    if(!cin.good()){
                        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
                    }

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

                    if(!cin.good()){
                        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
                    }

                }while(hDormir <= 0);
                this->setCantMaxDormir(hDormir);
                cout << "Ahora las horas de sueno del animal es de"<<this->getCantMaxDormir() << endl;
                break;
            case 4:
                do {
                    try {
                        editarAlimento();
                        cout << "Ya se edito con exito las porciones de alimentos" << endl;
                        terminado = true;
                    }
                    catch (const invalid_argument error) {
                        cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                        terminado = false;
                    }
                }
                while(terminado == false);
                terminado = false;
                break;

            case 5:
                do {
                    cout << "Ingrese el numero de juguetes que va agregar a la lista del animal: " << endl;
                    cin >> cantJuguetes;

                    if(!cin.good()){
                        throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
                    }

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
                if(juguetes.size() == 1){
                    cout << "No puedes eliminar el unico juguete de " << nombre << endl;
                }
                else {
                    do {
                        cout << "Ingrese el nombre: " << endl;
                        getline(cin, jugueteEliminar, '\n');

                        jugueteEliminar = convertidorStringMinuscula3(jugueteEliminar);
                    } while (!eliminarJuguetes(jugueteEliminar));
                    cout << "Se elimino correctamente el juguete" << jugueteEliminar << endl;
                }
                break;
            case 7:
                cin.ignore();
                if(alimentacion == "carnivoro"){
                    agregarAlimentoaMap(dietaCarnivora);
                }
                else if(alimentacion == "hervivoro"){
                    cin.ignore();
                    agregarAlimentoaMap(dietaHervivora);
                }
                else{
                    cin.ignore();
                    agregarAlimentoaMapOmnivoro(dietaHervivora,dietaCarnivora);
                }
                cout << "Se agrego corectamente el alimento" << endl;
                break;
            case 8:
                cin.ignore();
                do {
                    cout << "Ingrese el alimento: " << endl;
                    getline(cin, alimentoEliminar, '\n');
                    alimentoEliminar = convertidorStringMinuscula3(alimentoEliminar);
                }while(!eliminarAlimento(alimentoEliminar));
                cout << "Se elimino correctamente el alimento"<<alimentoEliminar << endl;
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

        if(!cin.good()){
            throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
        }

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
    do {
        cout << "Ingrese la cantidad de kilogramos de alimento: " << endl;
        cin >> kg;
    }while(kg != this->alimentos[alimento]);
    //

    cout << nombre << " esta comiendo " << kg << "kg de " << alimento << endl;
}

void Animal::durmiendo() {
    int hDormir;
    if (cantHorasDormidas < cantMaxDormir) {
        do {
            cout << "Ingrese las horas de suenio: " << endl;
            cin >> hDormir;

            if(!cin.good()){
                throw invalid_argument("se ingreso un argumento invalido y se espera un numero entero");
            }

            if (this->cantMaxDormir < hDormir + this->cantHorasDormidas) {
                cout << "Esta cantidad se excede del limite de suenio del animal " << endl;
            }
        } while (this->cantMaxDormir < hDormir + this->cantHorasDormidas);
        this->cantHorasDormidas += hDormir;

        cout << nombre << " va a dormir durante" << hDormir << "horas" << endl;
    }
    else{
        cout << nombre <<" ya ha dormido suficiente el dia de hoy" << endl;
    }
}

void Animal::interactAnimal(string opc) {
    string nombre = this->getNombre();
    bool terminado = false;

    if(opc == "jugar") {
        do {
            try {
                if(!jugar) {
                    jugando(nombre);
                    this->jugar = true;
                }
                else{
                    cout << nombre <<" ya ha jugado el dia de hoy" << endl;
                }
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;
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
        do {
            try {
                durmiendo();
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;
    }
    else {
        throw invalid_argument("Esta no es una actividad posible");
    }


}

void Animal::elegirAlim(string tipoAlim) {
    bool terminado = false;
    if (tipoAlim == "carnivoro") {

        cout << "- Res" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("res", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;

        cout << "- Pollo" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("pollo", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }while(terminado == false);
        terminado = false;

        cout << "- Pescado" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("pescado", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }while(terminado == false);
        terminado = false;

    } else if (tipoAlim == "herbivoro") {

        cout << "- Frutas" << endl;

        do {
            try {
                this->alimentos.insert(make_pair("frutas", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }while(terminado == false);
        terminado = false;

        cout << "- Verduras" << endl;
        bool terminado = false;
        do {
            try {
                this->alimentos.insert(make_pair("verduras", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }while(terminado == false);
        terminado = false;

        cout << "- Granos" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("granos", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }while(terminado == false);
        terminado = false;

    } else if (tipoAlim == "omnivoro") {

        cout << "- Res" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("res", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;

        cout << "- Pollo" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("pollo", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;

        cout << "- Frutas" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("frutas", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;

        cout << "- Verduras" << endl;
        do {
            try {
                this->alimentos.insert(make_pair("verduras", aseguradorDeCantAlimetos()));
                terminado = true;
            }
            catch (const invalid_argument error) {
                cout << "\nSE PRESENTO UN ERROR: " << error.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(),'\n');
                terminado = false;
            }
        }
        while(terminado == false);
        terminado = false;
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

void Animal::mostrarJuguetes() {
    vector<string>::iterator itVector;
    int contador = 1;

    for (itVector = this->juguetes.begin(); itVector!= this->juguetes.end(); ++itVector){
        cout << contador << ". " << (*itVector) << endl;
        contador++;
    }
}
