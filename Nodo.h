#ifndef NODO_H
#define NODO_H
class Nodo{
public:
	int dato;
	Nodo *izquierda;
	Nodo *derecha;	
	

	Nodo(){
		this -> dato =0;
		this ->izquierda = NULL;
		this ->derecha = NULL;
	}
	Nodo(int dato){
		this -> dato = dato;
		this -> izquierda = NULL;
		this -> derecha = NULL;
	}
	void setDato(int dato){
		this -> dato =dato;
	}
	int getDato(){
		return this -> dato;
	}
	void setIzquierda(Nodo *izquierda){
		this -> izquierda = izquierda;
	}
	Nodo *getIzquierda(){
		return this -> izquierda;
	}
	void setDerecha(Nodo *derecha){
		this -> derecha = derecha;
	}
	Nodo *getDerecha(){
		return this -> derecha;
	}
	
	
	
	
	
};






#endif
