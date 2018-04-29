#include <iostream>
#include "treeABB.h"
#include <vector>

using namespace std;

int tamArbol,nPruebas,mode;

void AskData(){
    cout << "Introduzca el tamaño del arbol:";
    cin >> tamArbol;
    cout << "Introduzca el número de pruebas:";
    cin >> nPruebas;
}

void SelectMode(){
    cout << "--------------------------------" << endl;
    cout << "    Arbol de busqueda binario"<< endl<<endl;
    cout << "Elija el modo:" <<endl<< "0 - Demostracion"<<endl<<"1 - Estadistica"<<endl;
    cin >> mode;
}

int main()
{
    SelectMode();

    if(mode == 0){
        //demo
    } else if(mode==1){
        //estadistica
        AskData();
        //creamos el banco de pruebas
        vector<DNI> testbench;
        for(int i=0;i<2*tamArbol;i++){
            DNI aleat;
            testbench.push_back(aleat);
        }
        //creamos el arbol y insertamos la mitad de elementos del banco de pruebas
        Treeabb<DNI> arbol;
        for(int i=0;i<tamArbol;i++){
            arbol.Insertar(testbench.at(i));
        }

        //reseteamos estadisitcas
        arbol.ResetStatistics();


    } else if(mode == 2){
        Treeabb<int> arbol;
        arbol.Insertar(8);
        arbol.Insertar(3);
        arbol.Insertar(10);
        arbol.Insertar(1);
        arbol.Insertar(6);
        arbol.Insertar(14);
        arbol.Insertar(4);
        arbol.Insertar(7);
        arbol.Insertar(13);
    } else {
        cout << "Modo incorrecto";
        return 0;
    }
    return 0;
}
