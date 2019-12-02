#ifndef ARBOL_H
#define ARBOL_H
#include "Nodo.h"
#include <iostream>
class Arbol{
private:
	Nodo *raiz;
	
	
	
	void agregarHojaPRIVADO(int _dato, Nodo *subArbol){
		if(raiz==NULL){
			raiz=crearHoja(_dato);
		}
		else if ( _dato < subArbol->dato ){
			if ( subArbol->izquierda==NULL ){
				subArbol->izquierda=crearHoja(_dato);
			}else{
				agregarHojaPRIVADO(_dato,subArbol->izquierda);
			}
		}
		else if ( _dato > subArbol->dato ){
			if ( subArbol->derecha==NULL){
				subArbol->derecha=crearHoja(_dato);
			}else{
				agregarHojaPRIVADO(_dato,subArbol->derecha);
			}
			
		}
		else{ /* NO SE AGREGAN HOJAS POR QUE YA EXISTE */ }
		
		
	}
	
	
	
	void mostrarPREORDEN_PRIVADO(Nodo *subArbol){
		if(subArbol!=NULL){
			cout<<subArbol->dato<<" ";
			if(subArbol->izquierda!=NULL)
			   mostrarPREORDEN_PRIVADO(subArbol->izquierda);
			   if(subArbol->derecha!=NULL)
				  mostrarPREORDEN_PRIVADO(subArbol->derecha);
		}
	}
	
	
	
	int elMasPequenoPRIVADO(Nodo *subArbol){
		if(raiz==NULL){
			cout<<"ARBOL VACIO\n";
			return -1000;
		} else{
			if(subArbol->izquierda !=NULL){
				return elMasPequenoPRIVADO(subArbol->izquierda);
			} else{
				return subArbol->dato;
			}
		}
	}
	
	
	
	int sumaMPRIVADO(Nodo *aux){   //suma multiplos de 3
		if(aux!=NULL){
			if(aux->dato%3==0)
			{
				sumaMultip=+aux->dato;
			}
			sumaMPRIVADO(aux->izquierda);
			sumaMPRIVADO(aux->derecha);
		}
		return sumaMultip;
	}
	
	
	
	
	int sumarParesPRIVADO(Nodo *aux){ //suma pares
		
		if(aux!=NULL){
			if((aux->dato%2==0)&&(aux->derecha==NULL&&aux->izquierda==NULL))
			{
				sumaPa += aux->dato;
			}
			sumarParesPRIVADO(aux->izquierda);
			sumarParesPRIVADO(aux->derecha);
			
		}
		return sumaPa;
	}
	
	
	
	int elMayorPRIVADO(Nodo *aux){  
		if(aux!=NULL){
			while(aux->derecha!=NULL){
				aux= aux->derecha;
			}
			return aux->dato;
		}else{
			cout<<"no hay elementos"<<endl;
		}
		
	}
	
	
	
	int elMenorPRIVADO(Nodo *aux){
		if(aux!=NULL){
			while(aux->izquierda!=NULL){
				aux=aux->izquierda;
			}
			return aux->dato;
			
		}else{
			cout<<"no hay elementos"<<endl;
		}
		
	}
	
	
	
	int cuentaHPRIVADO(Nodo *aux){
		if(aux!=NULL){
			if(aux->izquierda==NULL && aux->derecha==NULL){
				totalHoj++;
			}
			cuentaHPRIVADO(aux->izquierda);
			cuentaHPRIVADO(aux->derecha);
		}
		return totalHoj;
	}
	
	
	
	int cuentaInternosPRIVADO(Nodo *aux){
		if(aux!=NULL){
			if((aux->derecha!=NULL || aux->izquierda!=NULL)&&aux!=raiz){
				totalInt+=1;
			}
			cuentaInternosPRIVADO(aux->izquierda);
			cuentaInternosPRIVADO(aux->derecha);
		}
		return totalInt;
	}
	
	
	
	void encontrarDireccionPRIVADO(Nodo *&aux, int dato)
	{
		if(aux!=NULL){
			if(aux->dato!=dato)
			{
				encontrarDireccionPRIVADO(aux->izquierda, dato );
				encontrarDireccionPRIVADO(aux->derecha, dato);
			}
			else{cout<<"la direccion en memoria del elemento "<<dato<< " es "<<  &aux<<endl;}
		}
		
	}
	
	
	
	int sumaTodosPRIVADO(Nodo *aux)
	{
		if (aux == 0)
		{
			return 0;
		}else
		{
			sumatoria= aux->dato + sumaTodosPRIVADO(aux->izquierda) + sumaTodosPRIVADO(aux->derecha);
		}
		return sumatoria;
	}

	
	
	int cuentanHijPRIVADO(Nodo *aux){
		if(aux!=NULL){
			if(aux==raiz){
				cuentanHijPRIVADO(aux->izquierda);
				cuentanHijPRIVADO(aux->derecha);
			}
			else{
				cuentaNodosHijos++;
				cuentanHijPRIVADO(aux->izquierda);
				cuentanHijPRIVADO(aux->derecha);
			}
		}
		return cuentaNodosHijos;
	}
	
	
	int cuentaNivelesPRIVADO(Nodo *aux){
		
		
	}
	
	
public:
	int sumaPa=0;
	int sumaMultip;
	int Mayor;
	int Menor;
	int totalHoj;
	int totalInt;
	int sumatoria;
	int cuentaNodosHijos;
	int totalNiveles;
	
	
    Arbol(){
		raiz=NULL;
	}
	
	
	
	Nodo *crearHoja(int _dato){
		Nodo *n=new Nodo;
		n->dato=_dato;
		n->izquierda=NULL;
		n->derecha=NULL;
		return n;
	}
	
	
	
	void agregarHoja(int _dato){
		agregarHojaPRIVADO(_dato, raiz);
		
	}
	
	
	void mostrarPREORDEN(){
		mostrarPREORDEN_PRIVADO(raiz);
	}
	
	
	void elMasPequeno(){
		cout<< elMasPequenoPRIVADO(raiz);
	}
	
	
	void RecorreYSumaPares(){
		sumaPa = 0;
		cout<<"la suma de todos los elementos pares es: "<<sumarParesPRIVADO(this->raiz)<<endl;
	}

	void RecorreYsumaMult3(){ //suma multiplos de 3
		sumaMultip=0;
		cout<<"la suma de los elementos multiplos de tres es: "<< sumaMPRIVADO(this->raiz)<<endl;
	}

	void encuentraMayor()
	{
		
		Mayor=0;
		cout<<elMayorPRIVADO(this->raiz);
	}

	void encuentraMenor(){
		Menor=0;
		cout<<elMenorPRIVADO(this->raiz);
	}
	
	
	void cuentaHojas(){
		totalHoj=0;
		cout<<cuentaHPRIVADO(this->raiz);
	}
	

	void cuentaNodosInternos(){
		totalInt=0;
		cout<<cuentaInternosPRIVADO(this->raiz);
	}
	

	int encuentraDireccion(int dato)
	{
		encontrarDireccionPRIVADO(this->raiz, dato);
	}
	
	void llamarSumaTodos(){
		sumatoria=0;
		cout<<"la suma de todos los elementos es de: "<<sumaTodosPRIVADO(this->raiz)<<endl;
	}
	
	
	int cuentaHijos(){
		cuentaNodosHijos=0;
		cout<<cuentanHijPRIVADO(this->raiz)<<endl;
	}
	
	void cuentaNivelesArbol(){
		totalNiveles=0;
		cout<< cuentaNivelesPRIVADO(this->raiz);
	}
};


#endif
