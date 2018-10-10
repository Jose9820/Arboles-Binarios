//no duplicados
//arreglo para los valores
//imprimir de forma vertical

#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *izquierdo;
    Nodo *derecho;
};
//prototipo de funcion
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int n);
Nodo *arbol = NULL;

int main(){
    menu();
	return 0;
}
//funcion para crear un nuevo nodo
Nodo *crearNodo (int n){
    Nodo *inicio = new Nodo ();
    inicio->dato = n;
    inicio->izquierdo = NULL;
    inicio->derecho = NULL;
    return inicio;
}
//insertar elementos en el arbol
void insertarNodo(Nodo *&arbol, int n){
 	if(arbol == NULL){//si el arbol esta vacio
        Nodo *inicio = crearNodo(n);
        arbol = inicio;
 	}else{//si el arbol tiene un noda mas
     	int valorRaiz = arbol->dato;//obtenemos el valor de la raiz
     	if (n == valorRaiz) {
     		cout << "El elemento ya existe";
		 }
     	else if(n < valorRaiz){//si el elemento es menor a la raiz, insertamos en izquierda
         	insertarNodo(arbol->izquierdo, n);
     	}else{//si el elemento es mayor a la izq, insertamos en derecha
         	insertarNodo(arbol->derecho, n);
         }
    }
}

void mostrarArbol(Nodo *&arbol, int cont){
    if(arbol == NULL){//si el arbol esta vacio
        return;
    }else{//si el arbol tiene un nodo o mas
        mostrarArbol(arbol->derecho, cont+1);
        for(int i=0; i<cont;i++){
            cout << "   ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izquierdo, cont+1);
    }
}

void menu(){
    int dato, opcion, contador=0;
    do{
        cout << "\nMenu" << endl;
        cout << "1.- insertar nuevo nodo" << endl;
        cout << "2.- mostrarArbol" << endl;
        cout << "3.- Salir" << endl;
        cin>>opcion;
        switch(opcion){
            case 1:
                cout << "Digite un numero" << endl;
                cin >> dato;
                insertarNodo(arbol, dato);
                cout << endl;
                system("pause");
                break;
            case 2:
                cout << "\nMostrado Arbol completo" << endl;
                mostrarArbol(arbol, contador);
                system("pause");
                break;
        }
        system("cls");
    }while(opcion != 3);
}
