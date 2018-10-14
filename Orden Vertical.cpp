//imprimir de forma vertical

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <cstdio>

using namespace std;

struct Nodo{
 	int dato;
 	Nodo *izquierdo;
 	Nodo *derecho;
};

void gotoxy(int x, int y);
//prototipo de funcion
void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&, int []);
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
     		;
		 }
     	else if(n < valorRaiz){//si el elemento es menor a la raiz, insertamos en izquierda
         	insertarNodo(arbol->izquierdo, n);
       	}else{//si el elemento es mayor a la izq, insertamos en derecha
         	insertarNodo(arbol->derecho, n);
         }
 	 }
}

void mostrarArbol(Nodo *&arbol, int x, int y){
 	if(arbol == NULL){//si el arbol esta vacio
 		return;
 	}else{//si el arbol tiene un nodo o mas
 		gotoxy(x, y);
 		cout << arbol->dato << endl;
 		x=x-3;
 		y=y+3;
     	mostrarArbol(arbol->izquierdo, x, y);
     	x=x+6;
     	mostrarArbol(arbol->derecho, x, y);
     	y=y-3;
     }
}

void gotoxy(int x, int y){
 	HANDLE hcon;
 	hcon=GetStdHandle(STD_OUTPUT_HANDLE);
 	COORD dwPos;
 	dwPos.X=x;
 	dwPos.Y=y;
 	SetConsoleCursorPosition(hcon, dwPos);
}

void menu(){
 	int dato, opcion, contador=0, n;
 	bool bandera=true;
 	do{
 		if (bandera == true) {
 			cout << "\nCantidad de datos: ";
	     	cin >> n;
	     	cout << endl;
	     	for (int i = 0; i < n; i++) {
         		cout << "Digite un numero: ";
             	cin >> dato;
				 insertarNodo(*&arbol, dato);  	    
			 }
	 		cout << endl;
 		 }
 		cout << "1.- Agregar mas datos" << endl;
     	cout << "2.- Mostrar Arbol" << endl;
     	cout << "3.- Salir" << endl;
     	cin>>opcion;
     	system("cls");
	 	switch(opcion){
         	case 1:
             	bandera = true;
             	break;
         	case 2:
             	cout << "\nMostrado Arbol completo:\n" << endl;
             	int x, y;
             	x=40;
             	y=5;
             	mostrarArbol(arbol, x, y);
             	bandera = false;
         		break;
            case 3:
             	return;
             	break;
            default :
             	cout << "\nError: Opcion invalida. Reintente...\n";
             	bandera = false;
             	break;
     	 }
     	cout << endl;
     	system("pause");
     	//system("cls");
 	 }while(opcion != 3);
 }
