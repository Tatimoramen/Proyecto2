#include<iostream>
using namespace std;


#include "Nodo.h"
#include "Arbol.h"
#include <stdlib.h>
int main (int argc, char *argv[]) {
	
	Arbol *miArbol=new Arbol();
	Nodo *nodo;
	
	cout<<"********************************************"<<endl
		<<"PROYECTO FINAL ESTRUCTURAS DE DATOS"<<endl
		<<"********************************************"<<endl<<endl
		<<"ELABORADO POR:"<<endl
		<<"JERRY RODRIGUEZ BARQUERO"<<endl
		<<"KRISTHELL GUERRERO ALVARES"<<endl<<endl
		<<"PROFESOR "<<endl
		<<"GLORIANA PE�A RAMIRES"<<endl<<endl
		<<"ANIO 2019"<<endl
		<<"********************************************"<<endl;
	system("PAUSE");
	system("cls");
	

	miArbol->agregarHoja(8);
	miArbol->agregarHoja(3);
	miArbol->agregarHoja(6);
	miArbol->agregarHoja(2);
	miArbol->agregarHoja(9);
	miArbol->agregarHoja(4);
	miArbol->agregarHoja(5);
	miArbol->agregarHoja(7);
	miArbol->agregarHoja(1);
	miArbol->agregarHoja(10);

	
	int dato=0,opcion=0;
	do{
		system("cls");
		cout<<"\t ***MENU ***"<<endl
			<<"1.Mostrar preOrden "<<endl
			<<"2.Agregar elemento al arbol"<<endl
			<<"3.La cardinalidad de un arbol binario"<<endl
			<<"4.La suma de los elementos de un arbol"<<endl
			<<"5.La suma de sus elementos que son multiplos de 3 de un arbol"<<endl
			<<"6.La suma de los elementos pares correspondientes a las hojas de un arbol"<<endl
			<<"7.El mayor elemento de un arbol binario"<<endl
			<<"8.El menor elemento de un arbol binario"<<endl
			<<"9.La direcci�n del nodo en que se encuentra un valor X"<<endl
			<<"10.El numero de hojas de un arbol binario"<<endl
			<<"11.El numero de nodos internos"<<endl
			<<"12.El numero de hijos de un arbol"<<endl
			<<"0.Salir "<<endl
			<<"?";
		cin>>opcion;
		switch(opcion){
		case 1:
			system("cls");
			cout<<"preorden: ";
			miArbol->mostrarPREORDEN(); 
			cout<<endl;
			system("pause");
			break;
		case 2:
			system("cls");
			cout<<"Digie el numero de hoja para agregar: ";
			cin>>dato;
			miArbol ->agregarHoja(dato);
			cout<<"preorden: ";
			miArbol->mostrarPREORDEN();
			cout<<endl;
			system("pause");
			break;
		case 3:
			miArbol->cuentaNivelesArbol();
			system("pause");
			break;
		case 4:
			system("cls");
			miArbol->llamarSumaTodos();
			system("pause");
			break;
		case 5:
			system("cls");
			 miArbol->RecorreYsumaMult3();
			 system("pause");
			 break;
		case 6:
			system("cls");
			miArbol->RecorreYSumaPares();
			system("pause");
			break;
		case 7:
			miArbol->encuentraMayor();
			system("pause");
			break;	
		case 8:
			miArbol-> elMasPequeno();
			system("pause");
			break;	
		case 9:
			cout<<"Digite el elemento para saber su direccion en memoria"<<endl;
			cin>>dato;
			miArbol->encuentraDireccion(dato);
			system("pause");
			break;
		case 10:
			miArbol->cuentaHojas();
			system("pause");
			break;
		case 11:
			miArbol->cuentaNodosInternos();
			system("pause");
			break;	
		case 12:
			miArbol->cuentaHijos();
			system("pause");
			break;
		case 0:
			cout<<"Nos vemos luego";
			system("pause");
			break;
		}
	} while(opcion!=0);
	
	return 0;
}

